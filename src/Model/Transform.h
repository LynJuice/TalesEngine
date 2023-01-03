#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"

class Transform
{
public:
	Transform(glm::vec3 Positon, glm::vec3 Rotation, glm::vec3 Scale);
	void Update(Window& window);
	
	void SetRotation(float x, float y, float z);
	void SetRotation(glm::vec3 Rotation);
	void Rotate(float x, float y, float z);
	void Rotate(glm::vec3 Rotation);

	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 Position);
	void Translate(float x, float y, float z);
	void Translate(glm::vec3 Position);

	void SetScale(float x, float y, float z);
	void SetScale(glm::vec3 Scale);
	void Scale(float x, float y, float z);
	void Scale(glm::vec3 Scale);

	glm::mat4 proj = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 100.0f);
	glm::mat4 model = glm::mat4(1.0f);
};