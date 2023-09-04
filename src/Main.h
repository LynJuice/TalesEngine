#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Graphics/Shader.h"
#include "Graphics/Display.h"
#include "Graphics/3D/Camera.h"
#include "Graphics/3D/Model.h"
#include "Graphics/2D/Camera2D.h"
#include "Graphics/2D/SpriteRenderer.h"
#include "Graphics/2D/Texture2D.h"
#include "Sound/SoundDevice.h"
#include "Sound/SoundSource.h"
#include "Sound/SoundBuffer.h"

#include <glm/glm.hpp>.

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const float sensitivity = 0.1f;
const float cameraSpeed = 0.05f;

// 3D Graphics
Camera camera(0.0f, 0.0f, 3.0f);
Display display(800, 600, "TalesEngine");
Shader shader("default");
Model Testmodel("models/AE86.fbx");

// 2D Graphics
Shader shader2D("default2D");
Camera2D camera2D(SCR_WIDTH, SCR_HEIGHT);
SpriteRenderer spriteRenderer(shader2D);
Texture2D texture;

// Sound
SoundSource speaker;


// The first Mouse Click
bool firstMouse = true;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

int main();
void init();
void update();