#include "GM/Framework/Managers/MaterialManager.h"
#include "GM/Framework/Managers/ShaderManager.h"
#include "GM/Framework/Utilities/Material.h"
#include "GM/Framework/Templates/MaterialTemplateManager.h"
#include "GM/Framework/IO/TextIO.h"
#include "GM/Core/GL/Shader.h"
#include "ClanLib/core.h"

namespace GM {
namespace Framework {

MaterialManager::MaterialManager(const ShaderManagerPtr &shader_manager) 
: shader_manager(shader_manager)
{
	template_manager = MaterialTemplateManagerPtr(new MaterialTemplateManager());
}

MaterialManager::~MaterialManager() {

}

bool MaterialManager::contains(const std::string &name) const
{
	return (materials.end() !=  materials.find(name));
}

void MaterialManager::add(const std::string &name, const MaterialPtr &material)
{
	auto iter = materials.find(name);
	if (iter == materials.end())
	{
		materials.insert(std::make_pair(name, material));
	}
	else
	{
		clan::StringFormat message = clan::StringFormat("Material manager already contains a material by name (%1)");
		message.set_arg(1, name);
		throw clan::Exception(message.get_result());
	}
}

MaterialPtr MaterialManager::get(const std::string &name) const
{
	MaterialPtr material = nullptr;

	auto iter = materials.find(name);
	if (iter != materials.end())
	{
		material = iter->second;
	}

	return material;
}

MaterialPtr MaterialManager::get_or_create(const std::string &name)
{
	// First, test if the name has been cached.
	// FIXME: This call suggests there should be at least an internal get(name) method that only looks for cached shaders.
	auto material = get(name);
	if (material) {
		return material;
	}

	//If not cached, let's see if there is a template description for this name.
	template_manager->get(name, [this, name, &material](const MaterialTemplateManager::Template &t) {
		material = get_or_create(name, t.shader);
		return material;
	});

	if (!material)
		throw clan::Exception(clan::string_format("Failed to get or create the material %1.", name));

	return material;
}

MaterialPtr MaterialManager::get_or_create(const std::string& name, const std::string& shader_name)
{
	auto material = get(name);
	if (material) {
		//if (material->get_shader()->get_name() != shader_name) {
		//	throw Exception(string_format(
		//		"The shader of material %1 did not match the material and shader name (%2) combination asked for", 
		//		name, shader_name));
		//}
		return material;
	}

	auto shader = shader_manager->get_or_create(shader_name);
	material = MaterialPtr(new Material(shader, name));
	add(name, material);
	return material;
}

void MaterialManager::add_templates(const std::string &template_filename)
{
	template_manager->add_templates(template_filename);
}

} // namespace Framework
} // namespace GM
