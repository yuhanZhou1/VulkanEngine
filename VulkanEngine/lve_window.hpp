//
//  lve_window.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#ifndef lve_window_h
#define lve_window_h

#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
namespace lve{

class LveWindow{
    
public:
    LveWindow(int w, int h, std::string name);
    ~LveWindow();
    
    LveWindow(const LveWindow &) = delete;
    LveWindow &operator=(const LveWindow &) = delete;
    
    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    
    bool shouldClose(){
        return glfwWindowShouldClose(window);
    }
private:
    void initWindow();
    
    const int width;
    const int height;
    
    std::string windowName;
    GLFWwindow *window;
    
};

}

#endif /* lve_window_h */
