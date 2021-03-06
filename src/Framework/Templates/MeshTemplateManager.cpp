#include <GM/Framework/Templates/MeshTemplateManager.h>
#include <GM/Framework/Templates/MeshTemplateParser.h>
#include <GM/Framework/IO/TextIO.h>

#include <GM/Framework/Utilities/Mesh.h>

#include <ClanLib/core.h>

using namespace GM;
using namespace Framework;
using namespace clan;

#if defined(_MSC_VER)
#	pragma warning (disable:4701) // Avoid warning about uninitialized forced_type
#endif

MeshTemplateManager::MeshTemplateManager() {

}

void MeshTemplateManager::get(const std::string &template_name, std::function<void(const MeshTemplateManager::Template &)> func) {
	if (func == nullptr)
		return;

	for (auto &it_template : templates)
	{
		if (StringHelp::compare(template_name, it_template.name, true) == 0)
		{
			for (const auto &it_require : it_template.requires)
			{
				apply_requirement(it_require, it_template);
			}

			func(it_template);

			return;
		}
	}
}

void MeshTemplateManager::apply_requirement(const std::string &template_name, MeshTemplateManager::Template &t) {
	for (const auto &it_template : templates)
	{
		if (StringHelp::compare(template_name, it_template.name, true) == 0)
		{
			if (t.filename.empty()) t.filename = it_template.filename;
			if (t.mesh_index == 0) t.mesh_index = it_template.mesh_index;
			return;
		}
	}
}

void MeshTemplateManager::add_templates(const std::string &template_filename) {
	try
	{
		MeshTemplateParser::parse_templates(
			TextIO::load_contents(template_filename),
			[this](const MeshTemplateManager::Template &t)
		{
			templates.push_back(t);
		});
	}
	catch (Exception &e)
	{
		throw Exception(string_format("%1: %2", template_filename, e.what()));
	}
}
