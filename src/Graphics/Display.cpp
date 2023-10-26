/*
| Dependencies
|------------------
| Display.h - the header file for this file
*/
#include "Display.h"

/*
| Function: getProjection
|------------------------
| Gets the projection matrix for the current window
|------------------------
| @return - The projection matrix
*/
glm::mat4 Renderer::Display::getProjection()
{
	// get window size
	int width, height;
	glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);

	// return projection matrix
	return glm::perspective(glm::radians(90.0f), float(width) / float(height), 0.1f, 100.0f);
}

/*
| Class Constructor: Display
|---------------------------
| Creates a new display
|---------------------------
| @param SCR_WIDTH - The width of the window
| @param SCR_HEIGHT - The height of the window
| @param title - The title of the window
*/
Renderer::Display::Display(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT, const char *title)
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	// --------------------
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

/*
| Class Destructor: Display
|--------------------------
| Destroys the display
*/
Renderer::Display::~Display()
{
	glfwTerminate();
}