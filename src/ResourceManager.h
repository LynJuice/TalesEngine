#pragma once

/*
|Dependancies:
|--------------------
| map - std::map
| string - std::string
| Shader - Shader.h
| Model - Model.h
| iostream - std::cout, std::endl
| glad - glad.h
*/
#include <map>
#include <string>
#include "Graphics/Shader.h"
#include "Graphics/3D/Model.h"
#include <iostream>
#include <glad/glad.h>
// Static variables
static std::map<std::string, unsigned int> textures;
static std::map<std::string, Renderer::Shader> shaders;
static std::map<std::string, Model> models;

/*
| Class: ResourceManager
|------------------------
| A static class that manages resources
|------------------------
| @function LoadTexture - Loads a texture from a file path
| @function LoadShader - Loads a shader from a file path
| @function LoadModel - Loads a model from a file path
*/
namespace Resources
{
    class ResourceManager
    {
    public:
        static unsigned int LoadTexture(std::string path);
        static Renderer::Shader LoadShader(std::string path);
        static Model LoadModel(std::string path);

    private:
    };
}