#version 150
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;

uniform vec3 lightPos;
uniform vec4 lightCol;

in vec3 vertex;
in vec3 normal;
in vec3 texcoord0;

out vec3 nNormals;
out vec3 v;
out vec3 fTexCoord;

void main()
{
    nNormals = normalize(normalMatrix * normal);
    v = vec3(modelMatrix * viewMatrix * vec4(vertex, 1.0));
    fTexCoord = texcoord0;

    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertex, 1.0);
}
