#include "Shader.h"

std::string Shader::ReadShaderFile(const char* shaderPath)
{
	std::string shaderCode;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		shaderFile.open(shaderPath);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	return shaderCode.c_str();
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	this->vertexPath = vertexPath;
	this->fragmentPath = fragmentPath;
	std::string vertexShaderCode = ReadShaderFile(vertexPath);
	std::string fragmentShaderCode = ReadShaderFile(fragmentPath);
	const char* vertexShaderSource = vertexShaderCode.c_str();
	const char* fragmentShaderSource = fragmentShaderCode.c_str();
	// vertex shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED \n" << infoLog << std::endl;
	}

	// fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED \n" << infoLog << std::endl;
	}

	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED \n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
	glDeleteProgram(shaderProgram);
}

bool Shader::SetInt(const char* name, int value)
{
	int location = glGetUniformLocation(shaderProgram, name);
	if (location == -1)
	{
		std::cout << "ERROR::SHADER::UNIFORM::INT::NOT_FOUND" << std::endl;
		return false;
	}
	glUniform1i(location, value);
	return true;
}

bool Shader::SetFloat(const char* name, float value)
{
	int location = glGetUniformLocation(shaderProgram, name);
	if (location == -1)
	{
		std::cout << "ERROR::SHADER::UNIFORM::FLOAT::NOT_FOUND" << std::endl;
		return false;
	}
	glUniform1f(location, value);
	return true;
}

bool Shader::SetVec3(const char* name, glm::vec3 value)
{
	int location = glGetUniformLocation(shaderProgram, name);
	if (location == -1)
	{
		std::cout << "ERROR::SHADER::UNIFORM::VEC3::NOT_FOUND" << std::endl;
		return false;
	}
	glUniform3f(location, value.x, value.y, value.z);
	return true;
}

bool Shader::SetMat4(const char* name, glm::mat4 value)
{
	int location = glGetUniformLocation(shaderProgram, name);
	if (location == -1)
	{
		std::cout << "ERROR::SHADER::UNIFORM::MAT4::NOT_FOUND" << std::endl;
		return false;
	}
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	return true;
}