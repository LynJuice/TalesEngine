#include "TalesEngine.h"

Scene scene("assets/scenes/test.json");

int main()
{	
	Preload();
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
		int fpsInt = (int)fps;
		glfwSetWindowTitle(window.window, ("TalesEngine - FPS: " + std::to_string(fpsInt)).c_str());

		
		//PreDraw();
		scene.Render(shader, camera, window);
		//PostDraw();

		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}
	window.~Window();
	shader.~Shader();
	return 0;
}