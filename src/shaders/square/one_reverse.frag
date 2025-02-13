#version 330

in vec2 texturePosition;
out vec4 fragmentColor;

uniform sampler2D fragmentTexture1;
uniform sampler2D fragmentTexture2;
uniform float mixture;

void main(){
    vec4 fragmentTextureColor2 = texture(fragmentTexture2,texturePosition * vec2(-1,1));
    fragmentColor = mix(texture(fragmentTexture1,texturePosition),fragmentTextureColor2,mixture);
}