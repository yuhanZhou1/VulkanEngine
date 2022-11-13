//
//  first_app.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#ifndef first_app_hpp
#define first_app_hpp

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
#include <memory>

namespace lve{

class FirstApp{
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;
    
    FirstApp();
    ~FirstApp();
    
    FirstApp(const FirstApp &) = delete;
    FirstApp &operator=(const FirstApp &) = delete;
    
    void run();
    
private:
    
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();
    
    LveWindow lveWindow{WIDTH,HEIGHT,"Hello Vulkan"};
    LveDevice lveDevice{lveWindow};
    LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
    std::unique_ptr<LvePipeline> lvePipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    
//    LvePipeline lvePipeline{
//        lveDevice,
//        "/Users/yuhan/XcodeProject/VulkanEngine/Shaders/simple_shader.vert.spv",
//        "/Users/yuhan/XcodeProject/VulkanEngine/Shaders/simple_shader.frag.spv",
//        LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
//    };
    
};


}

#endif /* first_app_hpp */
