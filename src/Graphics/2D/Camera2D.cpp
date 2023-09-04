#include "Camera2D.h"

Camera2D::Camera2D(int width, int height)
{
    projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
}

Camera2D::~Camera2D()
{
}

void Camera2D::Update(int width, int height)
{
    projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
}