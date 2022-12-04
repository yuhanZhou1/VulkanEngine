//
//  lve_renderer.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/12/3.
//

#ifndef lve_renderer_hpp
#define lve_renderer_hpp


#include "lve_window.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

#include <memory>
#include <vector>
#include <cassert>

namespace lve{

class LveRenderer{
public:
    
    LveRenderer(LveWindow &window, LveDevice &device);
    ~LveRenderer();
    
    LveRenderer(const LveRenderer &) = delete;
    LveRenderer &operator=(const LveRenderer &) = delete;
    
    VkRenderPass getSwapChainRenderPass() const { return lveSwapChain->getRenderPass();}
    
    float getAspectRatio() const { return lveSwapChain->extentAspectRatio(); }
    
    VkCommandBuffer getCurrentCommandBuffer() const{
        assert(isFrameStarted && "Cannot get command buffer when frame not in progress");
        return commandBuffers[currentFrameIndex];
    }
    
    int getFrameIndex() const{
        assert(isFrameStarted && "Cannot get frame index when frame not in progress");
        return currentFrameIndex;
    }
    
    VkCommandBuffer beginFrame();
    void endFrame();
    void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
    void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

private:
    
    void createCommandBuffers();
    void freeCommandBuffers();
    void recreateSwapChain();
    
    LveWindow &lveWindow;
    LveDevice &lveDevice;
    std::unique_ptr<LveSwapChain> lveSwapChain;
    std::vector<VkCommandBuffer> commandBuffers;
    
    uint32_t currentImageIndex;
    int currentFrameIndex;
    bool isFrameStarted;
};
}

#endif /* lve_renderer_hpp */
