//
//  simple_render_system.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/12/3.
//

#ifndef simple_render_system_hpp
#define simple_render_system_hpp

#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_pipeline.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
class SimpleRenderSystem {
    
public:
    SimpleRenderSystem(LveDevice &device, VkRenderPass renderPass);
    ~SimpleRenderSystem();

    SimpleRenderSystem(const SimpleRenderSystem &) = delete;
    SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

    void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<LveGameObject> &gameObjects);

private:
    
    void createPipelineLayout();
    void createPipeline(VkRenderPass renderPass);

    LveDevice &lveDevice;

    std::unique_ptr<LvePipeline> lvePipeline;
    VkPipelineLayout pipelineLayout;
};
}  // namespace lve

#endif /* simple_render_system_hpp */
