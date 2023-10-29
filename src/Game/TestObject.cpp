#include "TestObject.h"



void TestObject::init()
{
    // load model using the resource manager
    
    model = Game::Game::ResManager.LoadModel("models/redbox.fbx");
    shader = Game::Game::ResManager.LoadShader("default");
    name = "testObject";
    
    GameObject::init();
}

void TestObject::update()
{
    GameObject::update();
}

void TestObject::render(glm::mat4 view, glm::mat4 projection)
{
    GameObject::render(projection, view);
}

