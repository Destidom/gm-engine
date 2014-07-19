#pragma once

#include "../Framework/EntityManager.h"
#include "../Framework/Totem/Totem.h"

// gl3w has to be included before glfw
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <ClanLib/core.h>

#include <string>

namespace GM {

namespace Framework {
	class SceneSystem; typedef std::shared_ptr<SceneSystem> SceneSystemPtr;
	class RenderSystem; typedef std::shared_ptr<RenderSystem> RenderSystemPtr;

	class EntityManager; typedef std::shared_ptr<EntityManager> EntityManagerPtr;
	class BufferManager; typedef std::shared_ptr<BufferManager> BufferManagerPtr;
	class ShaderManager; typedef std::shared_ptr<ShaderManager> ShaderManagerPtr;
	class TextureManager; typedef std::shared_ptr<TextureManager> TextureManagerPtr;
	class VaoManager; typedef std::shared_ptr<VaoManager> VaoManagerPtr;
}

namespace Application {

class Application : public Framework::PropertyContainer<>
{
public:

	enum Flags
	{
		GM_FRAMEWORK_SCENE_SYSTEM = (1 << 0),
		GM_FRAMEWORK_RENDER_SYSTEM = (1 << 1),
		GM_FRAMEWORK_ENTITY_MANAGER = (1 << 2),
		GM_FRAMEWORK_BUFFER_MANAGER = (1 << 3),
		GM_FRAMEWORK_SHADER_MANAGER = (1 << 4),
		GM_FRAMEWORK_TEXTURE_MANAGER = (1 << 5),
		GM_FRAMEWORK_VAO_MANAGER = (1 << 6),

		GM_FRAMEWORK_NO_DEFAULTS = 0,
		GM_FRAMEWORK_ALL_DEFAULTS = ((1<<30) - 1)
	};

	enum ErrorFlags
	{
		GM_ERROR_NULL_SYSTEM = (1 << 0),
		GM_ERROR_EXCEPTION = (1 << 1),
		GM_ERROR_GL_DEBUG_OUTPUT = (1 << 2),

		GM_ERROR_NO_CHECKS = 0,
		GM_ERROR_ALL_CHECKS = ((1<<30) - 1)
	};

public:
	Application(const std::string &title, Application::Flags flags = Flags::GM_FRAMEWORK_ALL_DEFAULTS, Application::ErrorFlags error_flags = GM_ERROR_ALL_CHECKS, unsigned int width = 800, unsigned int height = 640, bool fullscreen = false);
	virtual ~Application();

	void run();

	const std::string &get_title() const { return title; }
	unsigned int get_width() const { return width; }
	unsigned int get_height() const { return height; }
	bool is_fullscreen() const { return fullscreen; }
	bool is_running() const { return keep_running; }

	clan::Signal<void()> &on_initialize() { return initialize_sign; }
	clan::Signal<void(float)> &on_update() { return update_sign; }
	clan::Signal<void()> &on_prepare() { return prepare_sign; }
	clan::Signal<void()> &on_render() { return render_sign; }
	clan::Signal<void()> &on_clean_up() { return clean_up_sign; }

	// FIXME: All setters should probably ensure that the this-> version is nullptr and not already set...?
	// FIXME: Else throw an exception?

	bool has_scene_system() const { return scene_system != nullptr; }
	const Framework::SceneSystemPtr &get_scene_system() const { return scene_system; }
	void set_scene_system(const Framework::SceneSystemPtr &scene_system) { this->scene_system = scene_system; }

	bool has_render_system() const { return render_system != nullptr; }
	const Framework::RenderSystemPtr &get_render_system() const { return render_system; }
	void set_render_system(const Framework::RenderSystemPtr &render_system) { this->render_system = render_system; }

	bool has_entity_manager() const { return entity_manager != nullptr; }
	const Framework::EntityManagerPtr &get_entity_manager() const { return entity_manager; }
	void set_entity_manager(const Framework::EntityManagerPtr &entity_manager) { this->entity_manager = entity_manager; }

	bool has_buffer_manager() const { return buffer_manager != nullptr; }
	const Framework::BufferManagerPtr &get_buffer_manager() const { return buffer_manager; }
	void set_buffer_manager(const Framework::BufferManagerPtr &buffer_manager) { this->buffer_manager = buffer_manager; }

	bool has_shader_manager() const { return shader_manager != nullptr; }
	const Framework::ShaderManagerPtr &get_shader_manager() const { return shader_manager; }
	void set_shader_manager(const Framework::ShaderManagerPtr &shader_manager) { this->shader_manager = shader_manager; }

	bool has_texture_manager() const { return texture_manager != nullptr; }
	const Framework::TextureManagerPtr &get_texture_manager() const { return texture_manager; }
	void set_texture_manager(const Framework::TextureManagerPtr &texture_manager) { this->texture_manager = texture_manager; }

	bool has_vao_manager() const { return vao_manager != nullptr; }
	const Framework::VaoManagerPtr &get_vao_manager() const { return vao_manager; }
	void set_vao_manager(const Framework::VaoManagerPtr &vao_manager) { this->vao_manager = vao_manager; }

protected:
	void initialize();
	void update();
	void prepare();
	void render();
	void clean_up();

	GLFWwindow *window;

	Application::ErrorFlags error_flags;

	Framework::SceneSystemPtr scene_system;
	Framework::RenderSystemPtr render_system;

	Framework::EntityManagerPtr entity_manager;
	Framework::BufferManagerPtr buffer_manager;
	Framework::ShaderManagerPtr shader_manager;
	Framework::TextureManagerPtr texture_manager;
	Framework::VaoManagerPtr vao_manager;

	Framework::Property<std::string> title;
	Framework::Property<unsigned int> width;
	Framework::Property<unsigned int> height;
	Framework::Property<bool> fullscreen;
	Framework::Property<bool> keep_running;

	clan::GameTime game_time;

	clan::SlotContainer slots;

	// This signal is invoked when the OpenGL context has been created
	clan::Signal<void(void)> initialize_sign;

	// The update signal is called at the start of every render loop
	clan::Signal<void(float)> update_sign;

	// This is called just before render, relevant for scene manager
	clan::Signal<void(void)> prepare_sign;

	// Called to perform or just signal that render is supposed to happen
	clan::Signal<void(void)> render_sign;

	// Called when run() is finishing, before context destruction
	clan::Signal<void(void)> clean_up_sign;
};

} // namespace Application
} // namespace GM
