#pragma once

/*
| Dependencies:
|------------------
| glad - glad.h
| string - std::string
| fstream - std::ifstream
| sstream - std::stringstream
| iostream - std::cout, std::endl
| map - std::map
| vector - std::vector
| assimp - assimp/Importer.hpp, assimp/scene.h, assimp/postprocess.h
| glm - glm/common.hpp, glm/gtc/matrix_transform.hpp
| Shader - Shader.h
| Mesh - Mesh.h
*/
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Shader.h"
#include "Mesh.h"

/*
| Class: Model
|----------------
| A class that represents a model
|----------------
| @function Model - Default constructor
| @function Model - Creates a new model
| @function Draw - Draws the model
| @function Translate - Translates the model
| @function Rotate - Rotates the model
| @function Scale - Scales the model
*/
class Model
{
public:
    // model data 
    std::vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    std::vector<Mesh>    meshes;
    std::string directory;
    bool gammaCorrection;

    Model::Model(bool gamma = false) : gammaCorrection(gamma) { }; // default constructor

    // constructor, expects a filepath to a 3D model.
    Model::Model(std::string const& path, bool gamma = false) : gammaCorrection(gamma)
    {
        loadModel(path);
    }

    // draws the model, and thus all its meshes
    void Draw(Renderer::Shader& shader, glm::mat4 proj, glm::mat4 view);

    // Transformations
    void Translate(glm::vec3 translation);
    void Rotate(float angle, glm::vec3 axis);
    void Scale(glm::vec3 scale);

private:
    // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
    void loadModel(std::string const& path);

    // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
    void processNode(aiNode* node, const aiScene* scene);

    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

    unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);

    glm::mat4 model = glm::mat4(1.0f);
};