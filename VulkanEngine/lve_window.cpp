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
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);     // 调整窗口
    
    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface){
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("filed to create window surface");
    }
}

void LveWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
   auto lveWindow = reinterpret_cast<LveWindow *>(glfwGetWindowUserPointer(window));
   lveWindow->framebufferResized = true;
   lveWindow->width = width;
   lveWindow->height = height;
 }

} // namespace lve
