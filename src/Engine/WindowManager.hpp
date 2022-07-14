#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
/**
 * @brief WindowManager class
 * This class is used to create a window and manage it.
 */
class WindowManager
{
    public:
        WindowManager(int width, int height, const char* title);
        ~WindowManager();
        GLFWwindow* window;
    };
    /**
     * @brief WindowManager::WindowManager
     * @param width
     * @param height
     * @param title
     */
    WindowManager::WindowManager(int width, int height, const char* title)
    {
        glfwInit();
        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, 8);    
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif  
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (window == nullptr)
        {
            std::cout <<"Failed to create GLFW window \n";
            glfwTerminate();
        }   
        glfwMakeContextCurrent(window); 
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout <<"Failed to Initialize GLAD \n";
        }   
        glViewport(0, 0, width, height);

        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        glfwSwapInterval(0);
        glEnable(GL_DEPTH_TEST);
//        glEnable(GL_CULL_FACE);
        glEnable(GL_MULTISAMPLE);
//        glCullFace(GL_BACK);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    }
    /**
     * @brief WindowManager destructor
     * This function is used to destroy the window.
     */
    WindowManager::~WindowManager()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }    

    
#endif