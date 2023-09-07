#pragma once
#include <map>
#include <string>
#include "Graphics/Shader.h"
#include "Graphics/3D/Model.h"
#include <iostream>
#include <glad/glad.h>

static std::map<std::string, unsigned int> textures;
static std::map<std::string, Shader> shaders;
static std::map<std::string, Model> models;

class ResourceManager
{
public:
    static unsigned int LoadTexture(std::string path);
    static Shader LoadShader(std::string path);
    static Model LoadModel(std::string path);

private:
};

