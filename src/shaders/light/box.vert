#version 330

layout(location=0) in vec3 inPosition;
layout(location=2) in vec3 inNormal;

out vec3 normal;
out vec4 fragPosition;
out mat4 viewMatrix;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    mat4 modelView = model;
    normal = normalize(mat3(transpose(inverse(modelView))) * inNormal);
    viewMatrix = view;
    fragPosition = modelView * vec4(inPosition,1.0);
    gl_Position = projection * view * model * vec4(inPosition,1.0);
}