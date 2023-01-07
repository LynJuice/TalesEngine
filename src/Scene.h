#pragma once

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Model/Model.h"
using json = nlohmann::json;

class Scene
{
public:
	Scene(char* path);
	void Render(Shader shader, Camera camera, Window window); // TODO: each model can have a diffrent shader
private:
	std::vector<Model> models;
	Model CheckIfLoaded(const char* path);
};