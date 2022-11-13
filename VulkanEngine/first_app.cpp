//
//  first_app.cpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#include "first_app.hpp"

namespace lve{

void FirstApp::run(){
    while (!lveWindow.shouldClose()) {
        glfwPollEvents();
    }
}
}
