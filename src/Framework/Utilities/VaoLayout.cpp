#include "GM/Framework/Utilities/VaoLayout.h"

#include <algorithm>

// Remove when introducing GL
#ifndef GL_ARRAY_BUFFER
	#define GL_ARRAY_BUFFER 1
#endif

namespace GM {
namespace Framework {

VaoLayout::VaoLayout()
{
}

VaoLayout::~VaoLayout()
{
}

VaoLayout &VaoLayout::for_buffer(const unsigned int buffer_name)
{
	if (buffer_name == 0)
	{
		throw std::runtime_error("Can not bind to buffer 0");
	}

	active_buffer = buffer_name;
	active_type = 0;

	return *this;
}

VaoLayout &VaoLayout::use_as(const unsigned int buffer_type) {
	if (active_buffer == 0 || buffer_type == 0)
	{
		throw std::runtime_error("Can't use a 0-buffer or a buffer bound as nothing");
	}

	active_type = buffer_type;

	// We can register the buffer as used, and also with what type

	if (active_type == GL_ARRAY_BUFFER) // We can use multiple vertex buffers for vertex attributes
	{
		BufferUse buffer_use;
		buffer_use.name = active_buffer;
		buffer_use.type = active_type;

		auto iter = std::find(used_buffers.begin(), used_buffers.end(), buffer_use);

		if (iter == used_buffers.end())
		{
			used_buffers.push_back(buffer_use);
			std::sort(used_buffers.begin(), used_buffers.end());
		}
	}
	else
	{
		// We can only bind one buffer per type that is not GL_ARRAY_BUFFER
		auto iter = std::find_if(used_buffers.begin(), used_buffers.end(),
			[this](const BufferUse &buffer_use) { return buffer_use.type == active_type; });

		if (iter == used_buffers.end())
		{
			BufferUse buffer_use;
			buffer_use.name = active_buffer;
			buffer_use.type = active_type;

			used_buffers.push_back(buffer_use);
			std::sort(used_buffers.begin(), used_buffers.end());
		}
	}

	return *this;
}

VaoLayout &VaoLayout::bind(
	const unsigned int index,
	const unsigned int size_per_index,
	const unsigned int data_type,
	const bool normalized,
	const unsigned int stride,
	const unsigned int offset,
	const unsigned int divisor)
{

	// Can only bind if active_type is a vertex buffer

	if (active_type != GL_ARRAY_BUFFER)
	{
		// Silently ignore or throw exception?
		throw std::runtime_error("Can only bind vertex attributes if buffer is GL_ARRAY_BUFFER!");
	}

	BufferVertexAttribDefinition def;

	def.buffer_name = active_buffer;
	def.index = index;
	def.size_per_index = size_per_index;
	def.data_type = data_type;
	def.normalized = normalized;
	def.stride = stride;
	def.offset = offset;
	def.divisor = divisor;

	if (!std::binary_search(definitions.begin(), definitions.end(), def))
	{
		// No such definitions exists
		definitions.push_back(def);
		std::sort(definitions.begin(), definitions.end());
	}

	return *this;
}

const std::vector<BufferVertexAttribDefinition> &VaoLayout::get_definitions() const
{
	return definitions;
}


bool VaoLayout::operator< (const VaoLayout &other) const
{
	return (used_buffers < other.used_buffers) || (definitions < other.definitions);
}

} // namespace Framework
} // namespace GM
