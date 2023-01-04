#include "TalesEngine.h"

Window window(1920 / 2, 1080 / 2, "TalesEngine");
Camera camera(window.window);

Shader shader("assets/shaders/vertexShader.glsl", "assets/shaders/fragmentShader.glsl");
Model Skybox("assets/models/SkyBox.fbx");

Model CubeA("assets/models/Box.fbx");
Model CubeB("assets/models/Box.fbx");
Model CubeC("assets/models/Box.fbx");

int main()
{	
	Skybox.transformation.Rotate(glm::vec3(-90, 0, 0));
	
	CubeA.transformation.Translate(glm::vec3(0, 1, 3));
	CubeA.transformation.Rotate(glm::vec3(0, 45, 0));
	CubeB.transformation.Translate(glm::vec3(0, 1, 5.5f));
	CubeB.transformation.Rotate(glm::vec3(0, -25, 0));
	CubeC.transformation.Translate(glm::vec3(0, 3, 4.25));
	CubeC.transformation.Rotate(glm::vec3(0, 15, 0));
	
	double deltaTime = 0.0f;
	double lastFrame = 0.0f;
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glCullFace(GL_BACK);
		
	shader.SetVec3("lightPos", glm::vec3(5, 3, 7));
	shader.SetVec3("viewPos", camera.cameraPos);
	
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
		CubeA.Draw(shader, window, camera);
		CubeB.Draw(shader, window, camera);
		CubeC.Draw(shader, window, camera);
		
		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}
	window.~Window();

	return 0;
}
