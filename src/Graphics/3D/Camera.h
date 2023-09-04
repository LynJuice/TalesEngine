#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
private:
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection;
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight;
public:
    Camera(float X, float Y, float Z);
    ~Camera();

    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0);
    glm::vec3 cameraUp;

    float yaw = -90.0f;
    float pitch = 0.0f;
    float roll = 0.0f;

    float lastX = 400, lastY = 300;
};