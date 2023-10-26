#pragma once

/*
| Dependencies
|------------------
| glad - glad.h
| GLFW - glfw3.h
| glm - glm.hpp, gtc/matrix_transform.hpp
| iostream - std::cout, std::endl
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Display
{
public:
	Display(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT, const char* title);
	~Display();
	static glm::mat4 getProjection();

	GLFWwindow* window;
private:
};