#pragma once

#include "GameObject.h"
#include "Game.h"

class TestObject : public Game::GameObject
{
public:
    TestObject(){
        init();
    }

    void init() override;
    void update() override;
    void render(glm::mat4 view, glm::mat4 projection);
    ~TestObject() = default;
private:
};