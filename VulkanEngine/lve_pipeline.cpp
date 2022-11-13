//
//  lve_pipeline.cpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#include "lve_pipeline.hpp"
#include <fstream>
#include <cassert>


namespace lve {

LvePipeline::LvePipeline(
        LveDevice& device,
        const std::string& vertFilepath,
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo) : lveDevice(device){
    createGraphicPipeline(vertFilepath, fragFilepath, configInfo);
}
 
std::vector<char> LvePipeline::readFile(const std::string filepath){
    std::ifstream file{filepath, std::ios::ate | std::ios::binary};
    
    if (!file.is_open()) {
        throw std::runtime_error("failed to open file: " + filepath);
    }
    
    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize);
    
    file.seekg(0);
    file.read(buffer.data(), fileSize);
    
    file.close();
    
    return buffer;
}

void LvePipeline::createGraphicPipeline(
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo){
    
    auto vertCode = readFile(vertFilepath);
    auto fragCode = readFile(fragFilepath);
    
    std::cout << "Vertex shader Code Size: " << vertCode.size() << '\n';
    std::cout << "Fragment shader Code Size: " << fragCode.size() << '\n';
}

void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
    
    if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create shader module");
    }
}

PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height){
    
    PipelineConfigInfo configInfo{};
    return configInfo;
}

}
