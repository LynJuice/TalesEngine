#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/common.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	unsigned int shaderProgram;
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	bool SetInt(const char* name, int value);
	bool SetFloat(const char* name, float value);
	bool SetVec3(const char* name, glm::vec3 value);
	bool SetMat4(const char* name, glm::mat4 value);
	
	

private:
    std::string ReadShaderFile(const char* path);
};