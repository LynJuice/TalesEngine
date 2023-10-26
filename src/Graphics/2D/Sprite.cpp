/*
| Dependecies:
| Shader.h - the header file for sprite
| stb_image.h - used to load images
*/
#include "Sprite.h"
#include <stb_image.h>

/*
| Function: Sprite
|-----------------
| Creates a new sprite
|-----------------
| @param textureID - The texture ID
| @param position - The position of the sprite
| @param scale - The scale of the sprite
*/
Sprite::Sprite(unsigned int textureID, glm::vec2 position, glm::vec2 scale)
{
    init(textureID, position, scale);
}

/*
| Function: Init
|-----------------
| Initializes the sprite
|-----------------
| @param texturePath - The path to the texture
| @param position - The position of the sprite
| @param scale - The scale of the sprite
*/
void Sprite::init(unsigned int textureID, glm::vec2 position, glm::vec2 scale)
{
    shader = Shader("Default2D");
    texture = textureID;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO); // Bind VAO

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Bind VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copy vertices to VBO

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // Bind EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); // Copy indices to EBO

    // Position Attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); // Set attribute pointer
    glEnableVertexAttribArray(0); // Enable attribute

    // Texture Attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3)); // Set attribute pointer
    glEnableVertexAttribArray(1); // Enable attribute

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind VBO
    glBindVertexArray(0); // Unbind VAO

    int width, height;
    glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
    float aspect = (float)width / (float)height;

    scale.x /= aspect;

    shader.setVec2("Pos", position);
    shader.setVec2("Scale", scale);
}

/*
| Function: Render
|-----------------
| Renders the sprite
*/
void Sprite::Render()
{
    glCullFace(GL_FRONT);

    shader.use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


    glCullFace(GL_BACK);
}

/*
| Function: SetTexture
|-----------------
| Sets the texture of the sprite
|-----------------
| @param texture - The texture ID
*/
void Sprite::SetTexture(unsigned int texture)
{
    this->texture = texture;
}

Sprite::~Sprite()
{
}

Sprite::Sprite()
{
}