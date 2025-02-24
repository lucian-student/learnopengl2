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
    vec3 lightViewPosition = (vec4(lightPositon,1.0)).xyz;
    vec3 position = fragPosition.xyz;
    vec3 lightDirection = normalize(position - lightViewPosition);

    float specularStrenght = 0.5;
    vec3 viewerDirection = normalize(position - vec3(2.0, 4.0, 5.0));
    vec3 reflectedLight = reflect(lightDirection,normal);
    float specBase = max(dot(reflectedLight,-viewerDirection),0.0);
    float spec = pow(specBase,32);
    vec3 specular = lightColor * spec * specularStrenght;

    float diff = max(dot(normal,-lightDirection),0.0);
    vec3 diffuse = lightColor * diff;

    float ambientStrength = 0.1;
    vec3 ambient = lightColor * ambientStrength;

    fragColor = color * vec4((specular),1.0);
}