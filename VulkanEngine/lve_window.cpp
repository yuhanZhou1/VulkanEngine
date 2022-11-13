//
//  lve_window.cpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//
#include "lve_window.hpp"
#include <stdexcept>


namespace lve{

LveWindow::LveWindow(int w, int h, std::string name) : width{w}, height(h), windowName{name}{
    initWindow();
}

LveWindow::~LveWindow(){
    // 销毁窗口
    glfwDestroyWindow(window);
    // 终止 glfw
    glfwTerminate();
}

void LveWindow::initWindow(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);   // 表示和OPENGL API无关
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);     // 暂时不调整窗口
    
    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface){
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("filed to create window surface");
    }
}

} // namespace lve
