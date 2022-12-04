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
    
    GLFWwindow *getGLFWwindow() const { return window; }
    
    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    
    bool shouldClose(){ return glfwWindowShouldClose(window); }
    bool wasWindowResized() {return framebufferResized;}
    void resetWindowResizedFlag() {framebufferResized = false; }
    
    VkExtent2D getExtent() {return
        { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };
    }
private:
    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
    void initWindow();
    
    int width;
    int height;
    bool framebufferResized = false;
    
    std::string windowName;
    GLFWwindow *window;
    
};

}

#endif /* lve_window_h */
