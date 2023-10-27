#pragma once

/*
| Dependencies:
|------------------
| iostream - std::cout, std::endl
| glm - glm.hpp, gtc/matrix_transform.hpp, gtc/type_ptr.hpp
| Display.h
| Camera.h
| ResourceManager.h
*/
#include <iostream>
#include <glm/glm.hpp>
#include "../Graphics/Display.h"
#include "../Graphics/3D/Camera.h"
#include "../ResourceManager.h"

/*
| Class: Game
|----------------
| A class that represents the game
|----------------
| @function Game - Default constructor
| @function Game - Creates a new game
| @function ~Game - Default destructor
| @function init - Initializes all the game's variables
| @function update - Updates the game
| @function render - Renders the game
| @function processInput - Processes the input
| @function framebuffer_size_callback - The callback function for when the window is resized
| @function mouse_callback - The callback function for when the mouse is moved
| @function scroll_callback - The callback function for when the mouse wheel is scrolled
*/
namespace Game
{
    class Game
    {
    public:
        // constructor/destructor
        Game(int width, int height);
        ~Game();

        // game loop
        void init();
        void update();
        void render();
        void processInput(GLFWwindow *window);

    private:
        // timing
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        // camera
        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
        glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    };
}