#pragma once

#include "../Graphics/3D/Model.h"
#include "../Graphics/Shader.h"

namespace Game
{
    class GameObject
    {
    public:
        GameObject();
        GameObject(const GameObject &other);
        GameObject &operator=(const GameObject &other);
        ~GameObject();

        virtual void init();
        virtual void update();
        virtual void render(glm::mat4 view, glm::mat4 projection);
        
        Renderer::Model *model;
        Renderer::Shader *shader;

        std::string name;
    private:
    };
}