//
//  lve_camera.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/12/4.
//

#ifndef lve_camera_hpp
#define lve_camera_hpp

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace lve {

class LveCamera{
public:
    void setOrthographicProjection(float left, float right, float top, float bottom, float near, float far);
    
    void setPerspectiveProjection(float fovy, float aspect, float near, float far);
    const glm::mat4& getProjection() const { return projectionMatrix; }
private:
    glm::mat4 projectionMatrix{1.f};
};

}



#endif /* lve_camera_hpp */
