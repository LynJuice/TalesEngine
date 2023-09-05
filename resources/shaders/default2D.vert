#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform vec2 Pos;
uniform vec2 Scale;

out vec2 TexCoord;

void main()
{
    gl_Position = vec4((aPos.x + Pos.x) * Scale.x, (aPos.y + Pos.y) * Scale.y, aPos.z, 1.0);
    TexCoord = aTexCoord;
}