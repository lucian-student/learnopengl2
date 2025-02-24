#version 330

in vec3 normal;
in vec4 fragPosition;
in mat4 viewMatrix;

out vec4 fragColor;

uniform vec4 color;
uniform vec3 lightColor;
uniform vec3 lightPositon;

void main()
{
    float specularStrength = 0.5;
    vec3 position = fragPosition.xyz;
    vec3 lightDirection = normalize(position - lightPositon);
    vec3 viewDirection = normalize(position - vec3(2.0, 2.0, 3.0));
    vec3 reflectLight = reflect(lightDirection,normal);
    float specBase = max(dot(reflectLight,-viewDirection), 0.0);
    float spec = pow(specBase,128);
    vec3 specular = specularStrength * spec * lightColor;

    float diff = max(dot(normal,-lightDirection),0.0);
    vec3 diffuse = diff * lightColor;

    float ambientStrength = 0.1;
    vec3 ambient = lightColor * ambientStrength;

    fragColor = color * vec4((ambient + diffuse + specular),1.0);
}