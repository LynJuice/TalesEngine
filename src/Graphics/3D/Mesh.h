#pragma once

/*
| Dependencies
|------------------
| glad - glad.h
| glm - glm.hpp, gtc/matrix_transform.hpp
| string - std::string
| vector - std::vector
| Shader - Shader.h
*/
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <vector>
#include "../Shader.h"

#define MAX_BONE_INFLUENCE 4

/*
| Struct: Vertex
|---------------
| A struct that represents a vertex
|---------------
| @param Position - The position of the vertex
| @param Normal - The normal of the vertex
| @param TexCoords - The texture coordinates of the vertex
| @param Tangent - The tangent of the vertex
| @param Bitangent - The bitangent of the vertex
| @param m_BoneIDs - The bone IDs of the vertex
| @param m_Weights - The weights of the vertex
*/
struct Vertex
{
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
    // bone indexes which will influence this vertex
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    // weights from each bone
    float m_Weights[MAX_BONE_INFLUENCE];
};

/*
| Struct: Texture
|----------------
| A struct that represents a texture
|----------------
| @param id - The id of the texture
| @param type - The type of the texture
| @param path - The path of the texture
*/
struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

namespace Renderer
{
    /*
    | Class: Mesh
    |------------
    | A class that represents a mesh
    |------------
    | @function Mesh - Creates a new mesh
    | @function Draw - Draws the mesh
    */
    class Mesh
    {
    public:
        // mesh Data
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        unsigned int VAO;

        // constructor
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

        // render the mesh
        void Draw(Renderer::Shader &shader);

    private:
        // render data
        unsigned int VBO, EBO;

        // initializes all the buffer objects/arrays
        void setupMesh();
    };
}