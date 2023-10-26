#include "Game.h"

// functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// settings
const unsigned int SCR_WIDTH = 800 * 2;
const unsigned int SCR_HEIGHT = 600 * 2;
const float sensitivity = 0.1f;
const float cameraSpeed = 0.05f;

// mouse
bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

// variables
const ResourceManager ResManager;
Camera camera(0.0f, 0.0f, 3.0f);
Display display(SCR_WIDTH, SCR_HEIGHT, "TalesEngine");

Game::Game(int width, int height)
{
    // set the callback functions
    glfwSetFramebufferSizeCallback(display.window, framebuffer_size_callback);
    glfwSetCursorPosCallback(display.window, mouse_callback);
    glfwSetScrollCallback(display.window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(display.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // initialize the game
    init();

    // game loop
    while (!glfwWindowShouldClose(display.window))
    {
        // per-frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // process input
        processInput(display.window);

        // update
        update();

        // render
        render();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(display.window);
        glfwPollEvents();
    }
}

Game::~Game()
{
    // terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
}

void Game::init()
{

}

void Game::update()
{
    // projection matrix and view matrix
    glm::mat4 proj = display.getProjection();
    glm::mat4 view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);
}

void Game::render()
{
    // clear the screen
    glClearColor(0.0f, 0.3f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // render the game

    // clear the depth buffer
    glClear(GL_DEPTH_BUFFER_BIT);
    // render the UI
}

void Game::processInput(GLFWwindow *window)
{
    // close the window when the escape key is pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // move the camera
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.cameraPos += cameraSpeed * camera.cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.cameraPos -= cameraSpeed * camera.cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.cameraPos.y += cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.cameraPos.y -= cameraSpeed;
}






// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the cursor position is changed this callback function executes
// -----------------------------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        camera.lastX = xpos;
        camera.lastY = ypos;
        firstMouse = false;
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    float xoffset = xpos - camera.lastX;
    float yoffset = camera.lastY - ypos;
    camera.lastX = xpos;
    camera.lastY = ypos;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera.yaw += xoffset;
    camera.pitch += yoffset;

    if (camera.pitch > 89.0f)
        camera.pitch = 89.0f;
    if (camera.pitch < -89.0f)
        camera.pitch = -89.0f;

    camera.direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.direction.y = sin(glm::radians(camera.pitch));
    camera.direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.cameraFront = glm::normalize(camera.direction);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.fov -= (float)yoffset;
    if (camera.fov < 1.0f)
        camera.fov = 1.0f;
    if (camera.fov > 45.0f)
        camera.fov = 45.0f;
}