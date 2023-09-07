#include "ResourceManager.h"
#include <stb_image.h>

unsigned int ResourceManager::LoadTexture(std::string path)
{
    if (textures.find(path) != textures.end()) // If texture already exists
    {
        return textures[path]; // Return texture
    }

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

    textures[path] = texture; // Add texture to map
    
    return texture;
}

Shader ResourceManager::LoadShader(std::string path)
{
    // Check if shader has already loaded
    if (shaders.find(path) != shaders.end())
	{
		return shaders[path];
	}

    shaders[path] = Shader(path); // Add shader to map

    return Shader(path);
}

Model ResourceManager::LoadModel(std::string path)
{
    if (models.find(path) != models.end())
    {
		return models[path];
    }

    models[path] = Model(path);
    return Model(path);
}