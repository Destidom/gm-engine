#pragma once

#include "../../Framework/Utilities/Tools.h"

#include <GL/gl3w.h>

#include <functional>
#include <memory>
#include <sstream>

namespace GM {
namespace Core {

class BufferOperations
{
public:
	static void upload_unsafe(const GLenum target,
		std::function<void(void *destination, size_t size)> upload_function,
		GLsizeiptr length, GLintptr offset = 0);

	template<class... DataStructures>
	static void upload(const GLenum target,	GLsizeiptr length, GLintptr offset,
		const std::vector<DataStructures>&... data_structures)
	{
		size_t data_size = Framework::total_size(data_structures...);

		if (data_size > length)
		{
			std::stringstream ss;
			ss << "Total size of data structures (" << data_size << ") is bigger than requested upload size (" << length << ")";
			throw std::runtime_error(ss.str());
		}

		auto upload_function = [data_structures...] (void *destination, size_t /*mapped_size*/) {
			copy_func(destination, data_structures...);
		};

		upload_unsafe(target, upload_function, data_size, offset);
	}

private:

	template <class Single>
	static void copy_func(void *destination, const std::vector<Single>& single);

	template <class Head, class... Tail>
	static void copy_func(void *destination, const Head& head, const Tail&... tail);
};

//
// Implementations
//

template <class Single>
void BufferOperations::copy_func(void *destination, const std::vector<Single>& single)
{
	Single* destination_with_type = reinterpret_cast<Single*>(destination);
	std::copy(single.begin(), single.end(), destination_with_type);
}

template <class Head, class... Tail>
void BufferOperations::copy_func(void *destination, const Head& head, const Tail&... tail)
{
	copy_func(destination, head);
	copy_func(destination + Framework::total_size(head), tail...);
}

} // namespace Core
} // namespace GM