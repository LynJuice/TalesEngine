#include "Camera.h"
#include <iostream>

Camera::Camera(float X, float Y, float Z)
{
	cameraTarget = glm::vec3(X, Y, Z);
	cameraDirection = glm::normalize(cameraPos - cameraTarget);
	cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	cameraUp = glm::cross(cameraDirection, cameraRight);
}

Camera::~Camera()
{

}
