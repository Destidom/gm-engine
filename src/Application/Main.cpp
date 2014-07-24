#include "GM/Application/Main.h"

#include "GM/Framework/Systems/SceneSystem.h"
#include "GM/Framework/Systems/RenderSystem.h"

#include "GM/Framework/EntityManager.h"
#include "GM/Framework/Managers/BufferManager.h"
#include "GM/Framework/Managers/ShaderManager.h"
#include "GM/Framework/Managers/TextureManager.h"
#include "GM/Framework/Managers/VaoManager.h"

#include "GM/Framework/IO/SoilTextureIO.h"

#include <glm/ext.hpp>

#include <iostream>

namespace GM {
namespace Application {

	Main::Main(const std::string &title, Main::Flags flags, Main::ErrorFlags error_flags, unsigned int width, unsigned int height, bool fullscreen, bool visible, bool construct_window)
: Framework::PropertyContainer<>()
, window(nullptr)
, error_flags(error_flags)

, scene_system()
, render_system()
, entity_manager()
, buffer_manager()
, shader_manager()
, texture_manager()
, vao_manager()

, title(add<std::string>("title", title))
, resolution(add<glm::uvec2>("width", glm::uvec2(width, height)))
, fullscreen(add<bool>("fullscreen", fullscreen))
, visible(add<bool>("visible", visible))
, keep_running(add<bool>("keep_running", false))

#ifdef __APPLE__
, gl_version(3,2)
#else
, gl_version(4,3)
#endif

, game_time(30, 0)

, slots()
, initialize_sign()
, update_sign()
, prepare_sign()
, render_sign()
, clean_up_sign()
{
	slots.connect(this->title.value_changed(), this, &Main::on_title_changed);
	slots.connect(this->resolution.value_changed(), this, &Main::on_resolution_changed);
	slots.connect(this->fullscreen.value_changed(), this, &Main::on_fullscreen_changed);
	slots.connect(this->visible.value_changed(), this, &Main::on_visible_changed);

	if (flags & GM_FRAMEWORK_SCENE_SYSTEM)
	{
		scene_system = std::make_shared<Framework::SceneSystem>();
	}

	if (flags & GM_FRAMEWORK_RENDER_SYSTEM)
	{
		render_system = std::make_shared<Framework::RenderSystem>();
	}

	if (flags & GM_FRAMEWORK_ENTITY_MANAGER)
	{
		entity_manager = std::make_shared<Framework::EntityManager>();
	}
	
	if (flags & GM_FRAMEWORK_BUFFER_MANAGER)
	{
		buffer_manager = std::make_shared<Framework::BufferManager>();
	}

	if (flags & GM_FRAMEWORK_SHADER_MANAGER)
	{
		shader_manager = std::make_shared<Framework::ShaderManager>();
	}
	
	if (flags & GM_FRAMEWORK_TEXTURE_MANAGER)
	{
		texture_manager = std::make_shared<Framework::TextureManager>(
			std::make_shared<Framework::SoilTextureIO>()
		);
	}

	if (flags & GM_FRAMEWORK_VAO_MANAGER)
	{
		vao_manager = std::make_shared<Framework::VaoManager>();
	}

	if (construct_window)
	{
		construct_window_and_gl();
	}
}

Main::~Main()
{
	destruct_window_and_gl();
}

MainPtr Main::create_with_no_context(const std::string &title, Main::Flags flags, Main::ErrorFlags error_flags)
{
	return std::make_shared<Main>(title, flags, error_flags, 800, 640, false, true, false);
}

MainPtr Main::create_with_gl_version(const std::string &title, unsigned int major, unsigned int minor, bool visible, bool construct_context, Main::Flags flags, Main::ErrorFlags error_flags)
{
	auto app = std::make_shared<Main>(title, flags, error_flags, 800, 640, false, visible, false);
	app->set_gl_version(major, minor);

	if (construct_context)
	{
		app->construct_window_and_gl();
	}

	return app;
}

void Main::run(bool destruct_window_and_gl_on_exit)
{

	//Test if we should check for null systems
	if (error_flags & GM_ERROR_NULL_SYSTEM)
	{
		if (!has_scene_system()) {
			throw std::runtime_error("Must have scene system in order to run!");
		}

		if (!has_render_system()) {
			throw std::runtime_error("Must have render system in order to run!");
		}

		if (!has_entity_manager()) {
			throw std::runtime_error("Must have entity manager in order to run!");
		}

		if (!has_buffer_manager()) {
			throw std::runtime_error("Must have buffer manager in order to run!");
		}

		if (!has_shader_manager()) {
			throw std::runtime_error("Must have shader manager in order to run!");
		}

		if (!has_texture_manager()) {
			throw std::runtime_error("Must have texture manager in order to run!");
		}

		if (!has_vao_manager()) {
			throw std::runtime_error("Must have vao manager in order to run!");
		}
	}

	construct_window_and_gl();
	
	keep_running = true;

	initialize();

	while(is_running())
	{
		update();
		prepare();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwWindowShouldClose(window))
		{
			stop_running();
		}
	}

	clean_up();

	if (destruct_window_and_gl_on_exit)
	{
		destruct_window_and_gl();
	}
}

void Main::initialize()
{
	initialize_sign();
}

void Main::update()
{

	game_time.update();
	auto elapsed_time = game_time.get_time_elapsed();

	if (has_entity_manager())
	{
		entity_manager->update(elapsed_time);
	}

	update_sign(elapsed_time);
}

void Main::prepare()
{

	if (has_scene_system())
	{
		scene_system->prepare();
	}

	prepare_sign();
}

void Main::render()
{

	if (has_render_system())
	{
		render_system->render();
	}

	render_sign();
}

void Main::clean_up()
{
	clean_up_sign();
}

void Main::on_title_changed(const std::string &/*old_value*/, const std::string &new_value)
{
	if (is_context_setup())
	{
		glfwSetWindowTitle(window, new_value.c_str());
	}
}

void Main::on_resolution_changed(const glm::uvec2 &/*old_value*/, const glm::uvec2 &new_value)
{
	if (is_context_setup())
	{
		glfwSetWindowSize(window, new_value.x, new_value.y);
	}
}

void Main::on_fullscreen_changed(const bool &/*old_value*/, const bool &new_value)
{
	// TODO: Update fullscreen state for GLFW
	if (is_context_setup())
	{
		
	}
}

void Main::on_visible_changed(const bool &/*old*value*/, const bool &visible)
{
	if (is_context_setup())
	{
		if (visible)
		{
			glfwShowWindow(window);
		}
		else
		{
			glfwHideWindow(window);
		}
	}
}

void Main::construct_window_and_gl()
{
	if (is_running() || is_context_setup())
	{
		// Should not be possible to construct multiple windows and contexts in same object
		return;
	}

	if (!glfwInit())
	{
		// Failed to initialize 
		glfwTerminate();
		throw std::runtime_error("Unable to initialize glfw!");
	}

	GLFWmonitor *fullscreen_monitor = nullptr;
	if (fullscreen)
	{
		fullscreen_monitor = glfwGetPrimaryMonitor();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_version.x);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_version.y);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_VISIBLE, visible);

	window = glfwCreateWindow(
		resolution.get().x, resolution.get().y,
		title.get().c_str(),
		fullscreen_monitor,
		nullptr
	);
	if (!window)
	{
		glfwTerminate();
		throw std::runtime_error("Unable to create window or OpenGL context!");
	}

	glfwSetWindowUserPointer(window, this);

	glfwMakeContextCurrent(window);

	gl3wInit();

	std::clog << "VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::clog << "VERSION: " << glGetString(GL_VERSION) << std::endl;
	std::clog << "RENDERER: " << glGetString(GL_RENDERER) << std::endl;

	glm::ivec2 context_gl_version;
	glGetIntegerv(GL_MAJOR_VERSION, &context_gl_version.x);
	glGetIntegerv(GL_MINOR_VERSION, &context_gl_version.y);

	if (gl_version != context_gl_version) {
		std::clog << "Requested GL version: " << gl_version.x << "." << gl_version.y << std::endl;
		std::clog << "Got GL version: " << context_gl_version.x << "." << context_gl_version.y << std::endl;
	}
}

void Main::destruct_window_and_gl()
{
	if (is_running() || !is_context_setup())
	{
		// throw exception?
		return;
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	window = nullptr;
}

void Main::set_gl_version(int major, int minor)
{
	if (!is_running())
	{
#ifndef __APPLE__ // On Mac OS X, you will get the version supported by the os, OS X 10.9 supports 4.1
		gl_version.x = major;
		gl_version.y = minor;
#endif
	}
	else
	{
		throw std::runtime_error("You should not set GL version while run() is running");
	}
}

} // namespace Application
} // namespace GM