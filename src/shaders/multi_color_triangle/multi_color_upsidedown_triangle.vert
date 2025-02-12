#version 330

layout (location=0) in vec3 inPosition;
layout (location=1) in vec4 inColor;
out vec4 vertexColor;

uniform float offset;

void main()
{
    vertexColor = inColor;
    gl_Position = vec4((inPosition * vec3(1,-1,1)) + vec3(offset,0,0),1.0);
}