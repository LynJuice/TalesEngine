#pragma once
#include "../Shader.h"
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

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

public:
    Sprite(); // default constructor
    Sprite(unsigned int texture, glm::vec2 position, glm::vec2 scale);
    void init(unsigned int textureID, glm::vec2 position, glm::vec2 scale);
    void Render();
    void SetTexture(unsigned int textureID);

    Shader shader;
    ~Sprite();
};