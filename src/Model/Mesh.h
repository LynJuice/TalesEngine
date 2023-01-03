#pragma once
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "Shader.h"
struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct TextureData {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<TextureData> textures;
	
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<TextureData> textures);
	void Draw(Shader& shader, Transform& transform, Camera& camera);
private:
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};