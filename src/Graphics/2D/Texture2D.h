#pragma once

#include <glad/glad.h>
#include <iostream>
#include "../3D/Model.h"

class Texture2D
{
private:
    /* data */
public:
    unsigned int ID;
    unsigned int Width, Height;
    unsigned int Internal_Format;
    unsigned int Image_Format;
    unsigned int Wrap_S;
    unsigned int Wrap_T;
    unsigned int Filter_Min;
    unsigned int Filter_Max;
    
    Texture2D();

    void Generate(unsigned int width, unsigned int height, unsigned char* data);

    void Bind() const;

    unsigned char* LoadTextureFromFile(const char* file, bool alpha);
};
