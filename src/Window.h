#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
    GLFWwindow* window;
    Window(unsigned int width, unsigned int height, const char* title);
    ~Window();
    void Update();
    
	int width, height;
};