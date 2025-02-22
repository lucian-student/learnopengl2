#version 330

layout (location=0) in vec3 inPosition;
layout (location=1) in vec2 textPosition;

out vec2 texturePosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    texturePosition = textPosition;
    gl_Position = projection * view * model * vec4(inPosition,1.0);
}