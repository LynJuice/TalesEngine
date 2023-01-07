#include "Scene.h"

Scene::Scene(char* path)
{
	json data;
	try
	{
		std::ifstream f(path);
		data = json::parse(f);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error loading scene: " << path << " Error: " << e.what() << std::endl;
	}
	
	// First load all the models, we need to load every model before translations and rotations are applied
	for (auto& model : data["models"])
	{
		models.push_back(CheckIfLoaded(model["ModelPath"].get<std::string>().c_str()));
	}

	// Then apply the transformations
	//for (auto& model : data["models"])
	//{
	//	models[model["id"]].transformation.Translate(glm::vec3(model["translation"]["x"], model["translation"]["y"], model["translation"]["z"]));
	//	models[model["id"]].transformation.Rotate(glm::vec3(model["rotation"]["x"], model["rotation"]["y"], model["rotation"]["z"]));
	//	models[model["id"]].transformation.Scale(glm::vec3(model["scale"]["x"], model["scale"]["y"], model["scale"]["z"]));
	//}
}

void Scene::Render(Shader shader, Camera camera, Window window)
{
	for (auto& model : models)
	{
		model.Draw(shader,window, camera);	
	}
}

Model Scene::CheckIfLoaded(const char* path)
{
	for (auto& model : models)
	{
		if (model.path == path)
		{
			std::cout << "Model " << path << " Already loaded - Reusing" << std::endl;
			return model;
		}
	}
	return Model(path);
}