#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(unsigned int width, unsigned int height, const char* title)
{
    this->width = width;
    this->height = height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        throw std::invalid_argument("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::invalid_argument("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwTerminate();
}

void Window::Update()
{
    glfwGetWindowSize(window, &width, &height);
}
