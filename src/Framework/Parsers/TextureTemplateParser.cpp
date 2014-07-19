
#include <GM/Framework/Parsers/TextureTemplateParser.h>
#include <GM/Framework/Utilities/PropertySerializer.h>

#include <ClanLib/core.h>

using namespace GM;
using namespace Framework;
using namespace clan;

#if defined(_MSC_VER)
#	pragma warning (disable:4701) // Avoid warning about uninitialized forced_type
#endif

TextureTemplateParser::TextureTemplateParser()
{
}

void TextureTemplateParser::parse_templates(const std::string &data/*, std::function<void(const TemplateManager::Template &)> func*/)
{
	/*if (func == nullptr)
		throw Exception("Func callback is required to use TemplateParser's parse_templates!");
		*/
	auto json_data = JsonValue::from_json(data);

	if (!json_data.is_array())
		throw Exception("Failed to load template data");

	for (size_t i = 0; i < json_data.get_size(); i++)
	{
		//TemplateManager::Template t;

		auto json_entry = json_data[i];
		if (!json_entry.is_object())
			throw Exception("Array in json data should only hold objects");

		auto &json_members = json_entry.get_members();

		auto it = json_members.find("texture");
		if (it == json_members.end())
			throw Exception("texture is required");
		if (!it->second.is_string())
			throw Exception("texture must be a string");
		//t.name = it->second.to_string();

		//		std::cout << t.name << std::endl;

		it = json_members.find("image");
		if (it == json_members.end())
			throw Exception("image is required");
		if (!it->second.is_string())
			throw Exception("image must be a string");
		//t.image = it->second.to_string();

		it = json_members.find("format");
		if (it == json_members.end())
			throw Exception("format is required");
		if (!it->second.is_string())
			throw Exception("format must be a string");
		//t.format = it->second.to_string();

		//func(t);
	}
}
