#pragma once
// Camera for Development of 3D Graphics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:
	Camera(GLFWwindow* window);
	void Update(GLFWwindow* window);
	glm::mat4 GetView();
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
private:
	glm::mat4 view = glm::mat4(1.0f);
};