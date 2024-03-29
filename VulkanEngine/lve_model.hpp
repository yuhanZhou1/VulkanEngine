//
//  lve_model.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/19.
//

#ifndef lve_model_hpp
#define lve_model_hpp

#include "lve_device.hpp"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

// std
#include <vector>

namespace lve{

    class LveModel{
    public:
        struct Vertex{
            glm::vec3 position{};
            glm::vec3 color{};
            
            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
        };
        
        LveModel(LveDevice &device, const std::vector<Vertex> &vertices);
        ~LveModel();
        
        LveModel(const LveModel &) = delete;
        LveModel &operator=(const LveModel &) = delete;
        
        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);
    private:
        void createVertexBuffers(const std::vector<Vertex> & vertices);
        
        LveDevice &lveDevice;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;
    };

}

#endif /* lve_model_hpp */
