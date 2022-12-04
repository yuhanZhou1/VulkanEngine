//
//  keyboard_movement_controller.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/12/4.
//

#ifndef keyboard_movement_controller_hpp
#define keyboard_movement_controller_hpp

#include "lve_game_object.hpp"
#include "lve_window.hpp"

namespace lve {

class KeyboardMovementController{

public:
    struct KeyMappings {
        int moveLeft = GLFW_KEY_A;
        int moveRight = GLFW_KEY_D;
        int moveForward = GLFW_KEY_W;
        int moveBackward = GLFW_KEY_S;
        int moveUp = GLFW_KEY_E;
        int moveDown = GLFW_KEY_Q;
        int lookLeft = GLFW_KEY_LEFT;
        int lookRight = GLFW_KEY_RIGHT;
        int lookUp = GLFW_KEY_UP;
        int lookDown = GLFW_KEY_DOWN;
    };
    
    void moveInPlaneXZ(GLFWwindow *window, float dt, LveGameObject& gameObject);
    
    KeyMappings keys{};
    float moveSpeed{3.f};
    float lookSpeed{1.5f};
    
private:
};

}

#endif /* keyboard_movement_controller_hpp */
