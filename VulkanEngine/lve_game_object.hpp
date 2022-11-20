//
//  lve_game_object.hpp
//  VulkanEngine
//
//  Created by Yuhan's Macbook on 2022/11/20.
//

#ifndef lve_game_object_hpp
#define lve_game_object_hpp

#include <stdio.h>
#include "lve_model.hpp"

namespace lve {

struct Transform2dComponent{
    glm::vec2 translation{};
    glm::vec2 scale {1.f,1.f};
    float rotation;
    
    glm::mat2 mat2(){
        const float s = glm::sin(rotation);
        const float c = glm::cos(rotation);
        glm::mat2 rotMatrix{{c, s}, {-s, c}};
        
        glm::mat2 scaleMat{{scale.x, .0f}, {.0f, scale.y}};
        
        return rotMatrix * scaleMat;
    }
};

class LveGameObject{
public:
    using id_t = unsigned int;
    
    static LveGameObject createGameObject() {
         static id_t currentId = 0;
         return LveGameObject{currentId++};
    }
    
    LveGameObject(const LveGameObject &) = delete;
    LveGameObject &operator=(const LveGameObject &) = delete;
    LveGameObject(LveGameObject &&) = default;
    LveGameObject &operator=(LveGameObject &&) = default;
    
    id_t getId() {return id;}
    
    std::shared_ptr<LveModel> model{};
    glm::vec3 color{};
    Transform2dComponent transform2d{};
    
private:
    LveGameObject(id_t objId) : id{objId} {}
    id_t id;
};

}

#endif /* lve_game_object_hpp */
