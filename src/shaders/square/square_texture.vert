#version 330

layout (location=0) in vec3 inPosition;
layout (location=1) in vec2 inTexPosition;

out vec2 texturePosition;

void main(){
    texturePosition = inTexPosition;
    gl_Position = vec4(inPosition,1.0);
}