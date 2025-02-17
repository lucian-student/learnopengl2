#version 330

layout (location=0) in vec3 inPosition;
layout (location=1) in vec2 textPosition;

out vec2 texturePosition;

uniform mat4 transform;

void main()
{
    texturePosition = textPosition;
    gl_Position = transform * vec4(inPosition,1.0);
}