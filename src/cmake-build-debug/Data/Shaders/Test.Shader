# Vertex
#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;

void main()
{
    gl_Position = model * vec4(aPos, 1.0);
}
#End Vertex

# Fragment
#version 330 core

void main()
{
    gl_FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
#End Fragment