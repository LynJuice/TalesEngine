#include "Camera.h"

/*
| Function: Camera
|-----------------
| Creates a new camera
|-----------------
| @param X - The X position of the camera
| @param Y - The Y position of the camera
| @param Z - The Z position of the camera
*/
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
