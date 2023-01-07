#pragma once

#include <iostream>
#include <future>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Window.h"
#include "Camera.h"
#include "Scene.h"
#include "Model/Shader.h"
#include "Model/Texture.h"
#include "Model/Transform.h"
#include "Model/Model.h"

double deltaTime = 0.0f;
double lastFrame = 0.0f;
glm::vec3 LightPos = glm::vec3(25, 50, 50);

Window window(1920 / 2, 1080 / 2, "TalesEngine");
Camera camera(window.window);
Shader shader("assets/shaders/vertexShader.glsl", "assets/shaders/fragmentShader.glsl");

void Preload()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glCullFace(GL_BACK);
	glUseProgram(shader.shaderProgram);

	shader.SetVec3("lightPos", LightPos);
	shader.SetVec3("viewPos", camera.cameraPos);
}

void PreDraw()
{
}

void PostDraw()
{

}