#include "Sprite.h"
#include <stb_image.h>

Sprite::Sprite(std::string texturePath, glm::vec2 position, glm::vec2 scale)
{
    this->position = position;
    shader = Shader("Default2D");
    texture = LoadTexture(texturePath);

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

    shader.setVec2("Pos", this->position);
    shader.setVec2("Scale", scale);
}

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

void Sprite::SetTexture(std::string path)
{
    texture = LoadTexture(path);
}

unsigned int Sprite::LoadTexture(std::string path)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture wrapping/filtering options (on the currently bound texture object)
    // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // S = X
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // T = Y
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Minification filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Magnification filter

    // Load image, create texture and generate mipmaps
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0); // Load image
    if (data) // If image loaded successfully
    {
        if (nrChannels == 3) // If image is RGB
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); // Create texture
        }
        else if (nrChannels == 4) // If image is RGBA
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); // Create texture
        }
        else // If image is not RGB or RGBA
        {
            std::cout << "Error: Image is not RGB or RGBA" << std::endl;
        }
        glGenerateMipmap(GL_TEXTURE_2D); // Generate mipmaps
    }
    else // If image failed to load
    {
        std::cout << "Error: Failed to load texture" << std::endl;
    }

    stbi_image_free(data); // Free image memory

    return texture;
}

Sprite::~Sprite()
{
}
