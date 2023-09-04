#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera2D
{
private:
    /* data */
public:
    Camera2D(int width, int height);
    ~Camera2D();

    void Update(int width, int height);

    glm::mat4 projection;
};
