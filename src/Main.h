#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ResourceManager.h"

#include "Graphics/Shader.h"
#include "Graphics/Display.h"

#include "Graphics/3D/Camera.h"
#include "Graphics/3D/Model.h"

#include "Graphics/2D/Sprite.h"

#include "Sound/SoundDevice.h"
#include "Sound/SoundSource.h"
#include "Sound/SoundBuffer.h"

#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// settings
const unsigned int SCR_WIDTH = 800*2;
const unsigned int SCR_HEIGHT = 600*2;
const float sensitivity = 0.1f;
const float cameraSpeed = 0.05f;

// Resources
const ResourceManager ResManager;

// 3D Graphics
Camera camera(0.0f, 0.0f, 3.0f);
Display display(SCR_WIDTH, SCR_HEIGHT, "TalesEngine");
Model Testmodel;
Model Testmodel2;

// 2D Graphics
Sprite Crosshair;
Shader shader;



// The first Mouse Click
bool firstMouse = true;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

int main();
void init();
void update();