#pragma once
#include "Mesh.h"
#include "Shader.h"

#include <iostream>
#include <future>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Transform.h"
#include "Camera.h"

class Model
{
public:
	Model(char* path)
	{
		std::cout << "Loading: " << path << std::endl;
		loadModel(path);
	}
	void Draw(Shader& shader, Window& window,Camera& camera);

	Transform transformation = Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
private:
	std::vector<TextureData> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<TextureData> loadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName);
};