#pragma once
#include <iostream>
#include "../thirdparty/stb_image.h"
#include <glad/glad.h>

class Texture
{
public:
	Texture(const char* path);
	unsigned int ID;
};