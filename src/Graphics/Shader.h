#pragma once
/*
| Dependencies
|------------------
| string - std::string
| fstream - std::ifstream
| iostream - std::cout, std::endl
| sstream - std::stringstream
| glad - glad.h
| vector - std::vector
| glm - glm.hpp, gtc/matrix_transform.hpp, gtc/type_ptr.hpp
*/
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Renderer
{
	/*
	|Class: Shader
	|--------------
	| This class is used to load and use shaders
	|--------------
	| Functions:
	|   readFile - Reads a file and returns the contents
	|   use - Uses the shader
	|   setBool - Sets a boolean uniform
	|   setInt - Sets an integer uniform
	|   setFloat - Sets a float uniform
	|   setVec2 - Sets a vec2 uniform
	|   setVec3 - Sets a vec3 uniform
	|   setMat4 - Sets a mat4 uniform
	*/
	class Shader
	{
	public:
		Shader(){};

		Shader(std::string shaderFile);

		void use();
		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void setVec2(const std::string &name, glm::vec2 value) const;
		void setVec3(const std::string &name, glm::vec3 value) const;
		void setMat4(const std::string &name, glm::mat4 value) const;

		GLuint shaderID;

	private:
		std::string readFile(std::string file);
	};
}