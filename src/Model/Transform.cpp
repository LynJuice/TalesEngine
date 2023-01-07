#include "Transform.h"


void Transform::Translate(float x, float y, float z)
{
	model = glm::translate(model, glm::vec3(x, y, z));
}
void Transform::Translate(glm::vec3 Position)
{
	model = glm::translate(model, Position);
}

void Transform::Rotate(float x, float y, float z)
{
	model = glm::rotate(model, glm::radians(x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));

}
void Transform::Rotate(glm::vec3 Rotation)
{
	model = glm::rotate(model, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Transform::Scale(float x, float y, float z)
{
	model = glm::scale(model, glm::vec3(x, y, z));
}
void Transform::Scale(glm::vec3 Scale)
{
	model = glm::scale(model, Scale);
}



Transform::Transform(glm::vec3 Position, glm::vec3 Rotation, glm::vec3 Size)
{
	Translate(Position);
	Rotate(Rotation);
	Scale(Size);
}

void Transform::Update(Window& window)
{
	proj = glm::perspective(glm::radians(45.0f), (float)window.width / (float)window.height, 0.1f, 1000.0f);
}
