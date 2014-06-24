#pragma once

#include "../DefinitionsComponentNames.h"

// GLM
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// ClanLib
#include <ClanLib/core.h>

// Totem
#include <Totem/Component.h>

// STL
#include <memory>
#include <string>
#include <vector>

namespace GM {
namespace Framework {

class SceneManager; typedef std::shared_ptr<SceneManager> SceneManagerPtr; typedef std::weak_ptr<SceneManager> SceneManagerWeakPtr;
class Entity; typedef std::shared_ptr<Entity> EntityPtr; typedef std::weak_ptr<Entity> EntityWeakPtr;
class Transform; typedef std::shared_ptr<Transform> TransformPtr; typedef std::weak_ptr<Transform> TransformWeakPtr;

class Transform : public Totem::Component<Transform>, public std::enable_shared_from_this<Transform>
{
public:
	Transform(EntityPtr &owner, const SceneManagerPtr &scene_manager, const std::string &name = std::string());
	virtual ~Transform();

	const Entity *get_owner() const { return owner; }
	std::string get_type() const { return get_static_type(); }

	void add_child(const TransformPtr &child) { add_child( child.get() ); };
	void add_child(Transform * const child);

	void remove_child(const TransformPtr &child) { remove_child( child.get() ); };
	void remove_child(Transform * const child);


	// These signals are invoked when a child is added or removed from this transform.
	// Ther order of parameters: parent, then child
	clan::Signal<const Transform* const, const Transform* const> get_child_added_signal() const { return child_added_sig; };
	clan::Signal<const Transform* const, const Transform* const> get_child_removed_signal() const { return child_removed_sig; };

	Transform* get_parent() const;
	const std::vector<Transform*>& get_children() const;

	bool has_parent() const;
	bool has_children() const;

	const glm::vec3 &get_position() const { return position_property; }
	const glm::vec3 &get_scale() const { return scale_property; }
	const glm::quat &get_orientation() const { return orientation_property; }

	void set_position(const glm::vec3 &position) { position_property = position; }
	void set_scale(const glm::vec3 &scale) { scale_property = scale; }
	void set_orientation(const glm::quat &orientation) { orientation_property = orientation; }

	void translate(const glm::vec3 &position) { position_property += position; }
	void scale(const glm::vec3 &scale) { scale_property += scale; }
	void rotate(const glm::quat &orientation) { orientation_property *= orientation; }

	// Called by SceneManager
	bool is_dirty() const;
	void clear_dirty();

	const glm::mat4 &get_world_matrix() const { return world_matrix_property; };

	// Essentially goes world_matrix_property = make_world_matrix();
	// You need only call this to update, world and object
	void update_world_matrix();

	const glm::mat4 &get_object_matrix() const { return object_matrix_property; };

	// Essentially goes object_matrix_property = make_object_matrix() if
	// dependent properties (position, orientation, scale) has changed.
	void update_object_matrix();

public:
	static std::string get_static_type() { return COMPONENT_TRANSFORM; }

	// Called when a child is to be added to a parent
	static void add_callback(Transform * const child, Transform * const parent);

	// Called when a child is to be removed from a parent
	static void remove_callback(Transform * const child, Transform * const parent);

protected:
	glm::mat4 make_object_matrix() const;
	glm::mat4 make_world_matrix() const;

private:
	Entity* owner;
	SceneManagerPtr scene_manager;

	Transform * parent;
	std::vector<Transform *> children;

	// Signal is invoked when a new child is added to or removed from the transform
	// First argument is parent, second is child.
	clan::Signal<const Transform* const, const Transform* const> child_added_sig;
	clan::Signal<const Transform* const, const Transform* const> child_removed_sig;

	// TODO: Proper defs. of variables
	Totem::Property<glm::vec3> position_property;
	Totem::Property<glm::vec3> scale_property;
	Totem::Property<glm::quat> orientation_property;

	Totem::Property<glm::mat4> object_matrix_property;
	Totem::Property<glm::mat4> world_matrix_property;
};

} // namespace Framework
} // namespace GM