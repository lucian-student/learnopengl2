#version 330

in vec2 texturePosition;
out vec4 fragmentColor;

uniform sampler2D fragmentTexture1;
uniform sampler2D fragmentTexture2;

void main(){
    fragmentColor = mix(texture(fragmentTexture1,texturePosition),texture(fragmentTexture2,texturePosition),0.2);
}

