#version 330

in vec3 normal;
in vec4 fragPosition;
in vec2 texCoordinates;
in mat4 viewMatrix;

out vec4 fragColor;

struct Material{
    sampler2D diffuseMap;
    sampler2D specularMap;
    float shininess;
};

uniform Material material;

struct Light{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

void main()
{
    vec3 position = fragPosition.xyz;
    vec3 lightDirection = normalize(position - light.position);
    vec3 viewDirection = normalize(position - vec3(2.0, 2.0, 3.0));
    vec3 reflectLight = reflect(lightDirection,normal);
    float specBase = max(dot(reflectLight,-viewDirection), 0.0);
    float spec = pow(specBase,material.shininess);
    vec3 specular = vec3(texture(material.specularMap,texCoordinates)) * spec * light.specular;

    float diff = max(dot(normal,-lightDirection),0.0);
    vec3 diffuse = vec3(texture(material.diffuseMap,texCoordinates)) * diff * light.diffuse;

    vec3 ambient = light.ambient * vec3(texture(material.diffuseMap,texCoordinates));

    fragColor =  vec4((ambient + diffuse + specular),1.0);
}