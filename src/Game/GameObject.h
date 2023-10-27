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

        virtual void init();
        virtual void update();
        virtual void render();
    private:
        ~GameObject();
        Renderer::Model *model;
        Renderer::Shader *shader;
    };
}