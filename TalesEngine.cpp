#include "TalesEngine.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

Window window(1920 / 2, 1080 / 2, "TalesEngine");
Camera camera(window.window);

Shader shader("assets/shaders/vertexShader.glsl", "assets/shaders/fragmentShader.glsl");
Model Skybox("assets/models/SkyBox.fbx");
Model Scene("assets/models/scene.fbx");

int main()
{	
	Scene.transformation.Rotate(glm::vec3(-90, 0, 60+180+90));
	Skybox.transformation.Rotate(glm::vec3(-90, 0, 0));
	
	double deltaTime = 0.0f;
	double lastFrame = 0.0f;
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glCullFace(GL_BACK);
		
	while (!glfwWindowShouldClose(window.window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		window.Update();
		camera.Update(window.window);

		double currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		double fps = 1.0 / deltaTime;
		glfwSetWindowTitle(window.window, ("TalesEngine - FPS: " + std::to_string(fps)).c_str());
		
		Skybox.Draw(shader, window, camera);
		Scene.Draw(shader, window, camera);
		
		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}
	window.~Window();

	return 0;
}
