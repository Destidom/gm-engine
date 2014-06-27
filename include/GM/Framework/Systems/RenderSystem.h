#pragma once

#include <array>
#include <limits>
#include <memory>
#include <vector>


namespace GM {
namespace Framework {

class Camera; typedef std::shared_ptr<Camera> CameraPtr;
class IRenderable; typedef std::shared_ptr<IRenderable> IRenderablePtr;
class RenderSystem; typedef std::shared_ptr<RenderSystem> RenderSystemPtr;

class RenderSystem {
public:
	RenderSystem();
	~RenderSystem();

	void add_renderable(IRenderable *renderable);
	void remove_renderable(IRenderable *renderable);

	void add_camera(Camera *camera);
	void remove_camera(Camera *camera);

	void render();

	const std::vector<IRenderable*> &get_bucket(const unsigned int bucket_index);

public:

	// Should this be moved to a utility class?
	static std::vector<unsigned int> bit_index_maker(const unsigned int bits);

private:
	// Position is interpreted as layer. Position 0 is interpreted as layer 1,
	// position 1 is layer 2, and so forth.
	std::array<std::vector<IRenderable*>, std::numeric_limits<unsigned int>::digits> buckets;

	// Follows almost same structure as the buckets structure.
	// Position is determined by layer. The order in the layer's
	//  vector is depth sorted.
	std::array<std::vector<Camera*>, std::numeric_limits<unsigned int>::digits> cameras_in_layers;
};

} // namespace Framework
} // namespace GM
