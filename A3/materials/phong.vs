#version 150
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;

uniform vec3 lightPos;
uniform vec4 lightCol;

in vec3 vertex;
in vec4 color;
in vec3 normal;

out vec4 vColor;
out vec3 nNormals;
out vec3 vert;

void main()
{
    vColor = color;
    nNormals = normalize(normalMatrix * normal);
    vert = vec3(modelMatrix * viewMatrix * vec4(vertex, 1.0));

    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertex, 1.0);
}
