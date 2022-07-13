#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>


/**
 * @brief The Shader Include struct
 * 
 */
struct ShaderInclude
{
    bool Vertex{};
    std::string Path;
};


class Shader
{
public:
    Shader(const char* ShaderFile);
    ~Shader();
    void Use();

private:
    std::string readfile(const char* filename);
    void compile(unsigned int shader, const char* type);

    GLuint ID;
};

Shader::Shader(const char* ShaderFile)
{
    bool Vertex;
    bool Fragment;
    bool inc;

    std::string VertexShaderCode;
    std::string FragmentShaderCode;
    std::vector<ShaderInclude> Includes;

    std::ifstream file(ShaderFile);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            if(line.find("# Vertex") != std::string::npos)
            {
                Vertex = true;
                continue;
            }
            if(line.find("#End Vertex") != std::string::npos)
            {
                Vertex = false;
                continue;
            }
            if(line.find("# Fragment") != std::string::npos)
            {
                Fragment = true;
                continue;
            }
            if(line.find("#End Fragment") != std::string::npos)
            {
                Fragment = false;
                continue;
            }
            if(line.find("# Include") != std::string::npos)
            {
                inc = true;
            }
            if(line.find("#End Include") != std::string::npos)
            {
                inc = false;
            }
            if(Vertex && Fragment || Vertex && inc || Fragment && inc)
            {
                std::cout << "Error: Cannot read multiple shaders at the same time (Did you forget to close the Shader?)" << std::endl;
                printf("Vertex: %s", Vertex ? "true" : "false");
                printf("Fragment: %s", Fragment ? "true" : "false");
                printf("Inclusion: %s", inc ? "true" : "false");
                return;
            }
            

            if(Vertex)
            {
                VertexShaderCode += line + "\n";
            }
            if(Fragment)
            {
                FragmentShaderCode += line + "\n";
            }
            if(inc)
            {
                ShaderInclude include;
                if(line.find(".vert"))
                include.Vertex = true;
                else if(line.find(".frag"))
                include.Vertex = false;
                else
                {
                    std::cout << "Error: Include file must be .vert or .frag" << std::endl;
                    return;
                }
                include.Path = line.substr(line.find(" ") + 1);
                Includes.push_back(include);
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file " << ShaderFile << std::endl;
    }
    while(!Includes.empty())
    {
        ShaderInclude include = Includes.back();
        Includes.pop_back();
        if(include.Vertex)
        {
            VertexShaderCode += readfile(include.Path.c_str());
        }
        else
        {
            FragmentShaderCode += readfile(include.Path.c_str());
        }
    }

    const char* VSC = VertexShaderCode.c_str();
    const char* FSC = FragmentShaderCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &VSC, NULL);
	glCompileShader(vertexShader);
	compile(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &FSC, NULL);
	glCompileShader(fragmentShader);
	compile(fragmentShader, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	compile(ID, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

std::string Shader::readfile(const char* filename)
{
    std::string result;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            result += line + "\n";
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file " << filename << std::endl;
        return "";
    }
    return result;
}

void Shader::compile(unsigned int shader, const char* type)
{
	// Stores status of compilation
	GLint hasCompiled;
	// Character array to store error message in
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
			return;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}

void Shader::Use()
{
    glUseProgram(ID);
}
#endif // SHADER_HPP