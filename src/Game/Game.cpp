#include "Game.h"

// Test Include
#include "TestObject.h"

// functions
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

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
static Renderer::Camera camera(0.0f, 0.0f, 3.0f);
static Renderer::Display display(SCR_WIDTH, SCR_HEIGHT, "TalesEngine");

/*
| Function: Game
|----------------
| Default constructor
|----------------
| @param width - The width of the window
| @param height - The height of the window
*/
Game::Game::Game(int width, int height)
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

/*
| Destructor: Game
*/
Game::Game::~Game()
{
    glfwTerminate();
}

/*
| Function: init
|---------------
| Initializes all the game's variables
*/
void Game::Game::init()
{
    // create and add the game objects
    TestObject *testObject = new TestObject();
    gameObjects.push_back(testObject);
    
}

/*
| Function: update
|-----------------
| Updates the game
*/
void Game::Game::update()
{
    // projection matrix and view matrix
    projection = display.getProjection();
    view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);
    for (GameObject *object : gameObjects)
    {
        object->update();
    }

    try
    {
        GameObject* testObject = getGameObjectByName("testObject");
        testObject->model->Rotate(1, glm::vec3(1.0f, 0.0f, 0.0f));
    }
    catch (const std::exception&)
    {
        std::cout << "Error: Could not find game object with name TestObject" << std::endl;
    }
}

/*
| Function: render
|-----------------
| Renders the game
*/
void Game::Game::render()
{
    // clear the screen
    glClearColor(0.0f, 0.3f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // render the game
    for (GameObject *object : gameObjects)
    {
        object->render(view, projection);
    }

    // clear the depth buffer
    glClear(GL_DEPTH_BUFFER_BIT);
    // render the UI
}

/*
| Function: processInput
|-----------------------
| Processes the input
|-----------------------
| @param window - The window to process the input for
*/
void Game::Game::processInput(GLFWwindow *window)
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

Game::GameObject* Game::Game::getGameObjectByName(std::string name)
{
    for (GameObject* object : gameObjects)
    {
        if (object->name == name)
        {
			return object;
		}
	}
    std::cout << "GameObject with name " << name << " not found" << std::endl;
	return nullptr;
}

// callback functions

/*
| Function: framebuffer_size_callback
|------------------------------------
| Callback function for when the window is resized
|-------------------------------------------------
| @param window - The window that was resized
| @param width - The new width of the window
| @param height - The new height of the window
*/
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

/*
| Function: mouse_callback
|-------------------------
| Callback function for when the mouse is moved
|----------------------------------------------
| @param window - The window that the mouse was moved in
| @param xpos - The new x position of the mouse
| @param ypos - The new y position of the mouse
*/
void mouse_callback(GLFWwindow *window, double xpos, double ypos)
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

/*
| Function: scroll_callback
|--------------------------
| Callback function for when the mouse wheel is scrolled
|-------------------------------------------------------
| @param window - The window that the mouse was scrolled in
| @param xoffset - The x offset of the scroll
| @param yoffset - The y offset of the scroll
*/
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    camera.fov -= (float)yoffset;
    if (camera.fov < 1.0f)
        camera.fov = 1.0f;
    if (camera.fov > 45.0f)
        camera.fov = 45.0f;
}