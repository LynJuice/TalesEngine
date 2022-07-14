#ifndef TALESENGINE_GAMEOBJECT_HPP
#define TALESENGINE_GAMEOBJECT_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

class GameObject
{
public:
    GameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    virtual ~GameObject();
    virtual void render();
//    virtual void init() = 0;
//    virtual void destroy() = 0;

private:
    Shader shader = Shader("Data/Shaders/Test.Shader");

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    uint VBO, VAO, EBO;

    float vertices[12] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
    };
    uint indices[6] = {
            0, 1,3,
            1,2,3
    };

    virtual void update();
};

GameObject::GameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

GameObject::~GameObject()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void GameObject::update() {
    #ifdef DEBUG_MODE
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    //Create ImGUI window
    ImGui::Begin("GameObject");
    ImGui::Text("Position");
    ImGui::SliderFloat3("##Position", &position[0], -1.0f, 1.0f);
    ImGui::Text("Rotation");
    ImGui::SliderFloat3("##Rotation", &rotation[0], -180.0f, 180.0f);
    ImGui::Text("Scale");
    ImGui::SliderFloat3("##Scale", &scale[0], -10.0f, 10.0f);
    ImGui::End();
    #endif
}

void GameObject::render() {

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);

    shader.Use();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"),1, false, glm::value_ptr(model));
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    update();
    #ifdef DEBUG_MODE
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    #endif
}

#endif