#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	unsigned int shaderProgram;
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

private:
    std::string ReadShaderFile(const char* path);
};