#include "Gameobject.h"

namespace Game
{
    GameObject::GameObject()
    {
        model = new Renderer::Model();
        shader = new Renderer::Shader("default");
    }

    GameObject::GameObject(const GameObject &other)
    {
        model = new Renderer::Model(*other.model);
        shader = new Renderer::Shader(*other.shader);
    }

    GameObject &GameObject::operator=(const GameObject &other)
    {
        if (this != &other)
        {
            delete model;
            model = new Renderer::Model(*other.model);
            delete shader;
            shader = new Renderer::Shader(*other.shader);
        }
        return *this;
    }

    void GameObject::init()
    {

    }

    void GameObject::update()
    {
    
    }

    void GameObject::render()
    {
        
        model->Draw(*shader, glm::mat4(1.0f), glm::mat4(1.0f));
    }

    GameObject::~GameObject()
    {
        delete model;
    }
}
