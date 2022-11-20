//
//  lve_pipeline.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#ifndef lve_pipeline_hpp
#define lve_pipeline_hpp

#include "lve_model.hpp"
#include "lve_device.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace lve {

// Fixed Function PipeLine Stage
struct PipelineConfigInfo {
    PipelineConfigInfo() = default;
    PipelineConfigInfo(const PipelineConfigInfo&) = delete;
    PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

    VkPipelineViewportStateCreateInfo viewportInfo;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
    
    std::vector<VkDynamicState> dynamicStateEnables;
    VkPipelineDynamicStateCreateInfo dynamicStateInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
};

class LvePipeline{
public:
    LvePipeline(
        LveDevice& device,
        const std::string& vertFilepath,
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo);
    ~LvePipeline();
    
    LvePipeline(const LvePipeline&) = delete;
    LvePipeline& operator=(const LvePipeline&) = delete;
    
    void bind(VkCommandBuffer commandBuffer);
    
    static void defaultPipelineConfigInfo(PipelineConfigInfo& configInfo);

private:
    static std::vector<char> readFile(const std::string filepath);
    
    void createGraphicPipeline(
           const std::string& vertFilepath,
           const std::string& fragFilepath,
           const PipelineConfigInfo& configInfo);
    
    void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
    
    LveDevice& lveDevice;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
};

}

#endif /* lve_pipeline_hpp */
