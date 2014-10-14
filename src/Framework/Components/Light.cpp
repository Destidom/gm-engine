#include "GM/Framework/Components/Light.h"
#include "GM/Framework/Components/Camera.h"

#include "GM/Framework/Systems/RenderSystem.h"

#include "GM/Framework/DefinitionsPropertyNames.h"
#include "GM/Framework/Entity.h"

#include <glm/ext.hpp>
#include <GL/gl3w.h>

using namespace GM::Framework;

Light::Light(const EntityPtr &owner, const RenderSystemPtr &render_system, const std::string &name)
: Component(owner, name)
, render_system(render_system)
{
	world_matrix_property = owner->add(GM_PROPERTY_WORLD_MATRIX, glm::mat4(1));
	radius_property = owner->add(GM_PROPERTY_RADIUS, 0.0f);
	material_color_diffuse_property = owner->add(GM_PROPERTY_MATERIAL_COLOR_DIFFUSE, glm::vec3(1));
	material_color_specular_property = owner->add(GM_PROPERTY_MATERIAL_COLOR_SPECULAR, glm::vec3(1));
	material_color_ambient_property = owner->add(GM_PROPERTY_MATERIAL_COLOR_AMBIENT, glm::vec3(1));
    activated_property = owner->add(GM_PROPERTY_ACTIVATED, true);

	render_system->add_light(this);
}

Light::~Light() {
	render_system->remove_light(this);
}

glm::vec3 Light::get_position_in_viewspace(Camera *camera) const {
	return glm::vec3(camera->get_view_matrix() * glm::vec4(world_matrix_property.get()[3][0], world_matrix_property.get()[3][1], world_matrix_property.get()[3][2], 1.0f));
}