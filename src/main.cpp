#define DEBUG_MODE

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/WindowManager.hpp"
#include "Engine/Shader.hpp"

#include "Engine/Objects/GameObject.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

int main(int, char**) {
    WindowManager display(800, 600, "Hello World");
    GameObject gameObject(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    #ifdef DEBUG_MODE
    std::cout << "Debug mode enabled" << std::endl;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(display.window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();
    #endif
    #ifndef DEBUG_MODE std::cout << "Debug mode disabled" << std::endl;
    #endif

    while (!glfwWindowShouldClose(display.window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        gameObject.render();

        glfwPollEvents();
        glfwSwapBuffers(display.window);
    }
}