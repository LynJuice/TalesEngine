#pragma once
#include "../Shader.h"
#include <iostream>
#include <string>

class Sprite
{
private:
const float vertices[20] = {
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f,// top right
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,// bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f// top left 
};

const unsigned int indices[6] = {
    0,1,3,1,2,3
};

unsigned int VBO, VAO, EBO, texture;

unsigned int LoadTexture(std::string path);
glm::vec2 position;
public:
    Sprite(std::string texture, glm::vec2 position, glm::vec2 scale);
    void Render();
    void SetTexture(std::string path);

    Shader shader;
    ~Sprite();
};