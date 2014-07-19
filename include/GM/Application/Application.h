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
		GM_SCENE_SYSTEM = (1<<0),
		GM_RENDER_SYSTEM = (1<<1),
		GM_ENTITY_MANAGER = (1<<2),
		GM_BUFFER_MANAGER = (1<<3),
		GM_SHADER_MANAGER = (1<<4),
		GM_TEXTURE_MANAGER = (1<<5),
		GM_VAO_MANAGER = (1<<6),

		GM_NO_DEFAULTS = 0,
		GM_FRAMEWORK_DEFAULTS = ((1<<30) - 1)
	};

public:
	Application(const std::string &title, Application::Flags flags, unsigned int width = 800, unsigned int height = 640, bool fullscreen = false);
	virtual ~Application();

	void run();

	clan::Signal<void()> &on_initialize() { return initialize_sign; }
	clan::Signal<void(double)> &on_update() { return update_sign; }
	clan::Signal<void()> &on_prepare() { return prepare_sign; }
	clan::Signal<void()> &on_render() { return render_sign; }
	clan::Signal<void()> &on_clean_up() { return clean_up_sign; }


	bool has_scene_system() const { return scene_system != nullptr; }
	const Framework::SceneSystemPtr &get_scene_system() const { return scene_system; }

	bool has_render_system() const { return render_system != nullptr; }
	const Framework::RenderSystemPtr &get_render_system() const { return render_system; }

	bool has_entity_manager() const { return entity_manager != nullptr; }
	const Framework::EntityManagerPtr &get_entity_manager() const { return entity_manager; }

	bool has_buffer_manager() const { return buffer_manager != nullptr; }
	const Framework::BufferManagerPtr &get_buffer_manager() const { return buffer_manager; }

	bool has_shader_manager() const { return shader_manager != nullptr; }
	const Framework::ShaderManagerPtr &get_shader_manager() const { return shader_manager; }

	bool has_texture_manager() const { return texture_manager != nullptr; }
	const Framework::TextureManagerPtr &get_texture_manager() const { return texture_manager; }

	bool has_vao_manager() const { return vao_manager != nullptr; }
	const Framework::VaoManagerPtr &get_vao_manager() const { return vao_manager; }

protected:
	GLFWwindow *window;

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

	clan::SlotContainer slots;

	// This signal is invoked when the OpenGL context has been created
	clan::Signal<void(void)> initialize_sign;

	// The update signal is called at the start of every render loop
	clan::Signal<void(double)> update_sign;

	// This is called just before render, relevant for scene manager
	clan::Signal<void(void)> prepare_sign;

	// Called to perform or just signal that render is supposed to happen
	clan::Signal<void(void)> render_sign;

	// Called when run() is finishing, before context destruction
	clan::Signal<void(void)> clean_up_sign;
};

} // namespace Application
} // namespace GM