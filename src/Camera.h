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
private:
	glm::mat4 view = glm::mat4(1.0f);
};