//
//  first_app.cpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#include "first_app.hpp"

namespace lve{

FirstApp::FirstApp() {
  createPipelineLayout();
  createPipeline();
  createCommandBuffers();
}

FirstApp::~FirstApp() {
  vkDestroyPipelineLayout(lveDevice.device(), pipelineLayout, nullptr);
}

void FirstApp::run(){
    while (!lveWindow.shouldClose()) {
        glfwPollEvents();
    }
}

void FirstApp::createPipelineLayout(){
    
    VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
    pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutInfo.setLayoutCount = 0;
    pipelineLayoutInfo.pSetLayouts = nullptr;
    pipelineLayoutInfo.pushConstantRangeCount = 0;
    pipelineLayoutInfo.pPushConstantRanges = nullptr;
    
    if (vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) !=
        VK_SUCCESS) {
      throw std::runtime_error("failed to create pipeline layout!");
    }
}
void FirstApp::createPipeline(){
    auto pipelineConfig = LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT);
    pipelineConfig.renderPass = lveSwapChain.getRenderPass();
    pipelineConfig.pipelineLayout = pipelineLayout;
    lvePipeline = std::make_unique<LvePipeline>(
        lveDevice,
        "/Users/yuhan/XcodeProject/VulkanEngine/Shaders/simple_shader.vert.spv",
        "/Users/yuhan/XcodeProject/VulkanEngine/Shaders/simple_shader.frag.spv",
        pipelineConfig);
}
void FirstApp::createCommandBuffers(){
}
void FirstApp::drawFrame(){
    
}
}
