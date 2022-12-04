//
//  first_app.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/13.
//

#ifndef first_app_hpp
#define first_app_hpp

#include "lve_window.hpp"
#include "lve_model.hpp"
#include "lve_game_object.hpp"
#include "lve_device.hpp"
#include "lve_renderer.hpp"
#include <memory>

namespace lve{

class FirstApp{
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;
    
    FirstApp();
    ~FirstApp();
    
    FirstApp(const FirstApp &) = delete;
    FirstApp &operator=(const FirstApp &) = delete;
    
    void run();
    
private:
    
    void loadGameObjects();
    
    LveWindow lveWindow{WIDTH,HEIGHT,"Vulkan Engine"};
    LveDevice lveDevice{lveWindow};
    LveRenderer lveRenderer{lveWindow, lveDevice};
    std::vector<LveGameObject> gameObjects;
        
};
}

#endif /* first_app_hpp */
