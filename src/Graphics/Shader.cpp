#include "Shader.h"

Shader::Shader(std::string shaderFile)
{
	// Read the Vertex Shader from shaderFile.vert
	std::string vertexShaderSource = readFile("shaders/" + shaderFile + ".vert");
	const char* vertexShaderSourcePointer = vertexShaderSource.c_str();
	// Read the Fragment Shader from shaderFile.frag
	std::string fragmentShaderSource = readFile("shaders/" + shaderFile + ".frag");
	const char* fragmentShaderSourcePointer = fragmentShaderSource.c_str();

	// Create the shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Compile Vertex Shader
	glShaderSource(vertexShader, 1, &vertexShaderSourcePointer, NULL);
	glCompileShader(vertexShader);

	// Check Vertex Shader
	GLint result = GL_FALSE;
	int infoLogLength;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		
		std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vertexShader, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		std::cout << "VERTEX::ERROR:: " << &vertexShaderErrorMessage[0] << std::endl;
	}

	// Compile Fragment Shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSourcePointer, NULL);
	glCompileShader(fragmentShader);

	// Check Fragment Shader
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0) {
		std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fragmentShader, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		std::cout << "FRAGMENT::ERROR:: " << &fragmentShaderErrorMessage[0] << std::endl;
	}

	// Link the program
	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexShader);
	glAttachShader(shaderID, fragmentShader);
	glLinkProgram(shaderID);

	// Check the program
	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
	glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0) {
		std::vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(shaderID, infoLogLength, NULL, &programErrorMessage[0]);
		std::cout << &programErrorMessage[0] << std::endl;
	}

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

std::string Shader::readFile(std::string file)
{
	// Open the file
	std::ifstream fileStream(file, std::ios::in);
	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << file << ". File does not exist." << std::endl;
		return "";
	}

	// Read the file
	std::string line = "";
	std::string fileContent = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		fileContent.append(line + "\n");
	}
	fileStream.close();

	return fileContent;
}

void Shader::use()
{
	glUseProgram(shaderID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUseProgram(shaderID);
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUseProgram(shaderID);
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUseProgram(shaderID);
	glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shader::setVec3(const std::string &name, glm::vec3 value) const
{
	glUseProgram(shaderID);
	glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]);
}

void Shader::setMat4(const std::string &name, glm::mat4 value) const
{
	glUseProgram(shaderID);
	glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}