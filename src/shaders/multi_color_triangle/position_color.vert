#version 330

layout (location=0) in vec3 inPosition;

out vec4 vertexColor;

void main()
{
    vertexColor = vec4(inPosition,1.0);
    gl_Position = vec4(inPosition,1.0);
}