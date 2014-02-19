#version 150

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;
// comment

struct lightSource
{
    vec4 position;
    vec4 diffuse;
};

lightSource light0 = lightSource(
                        vec4(-1.0,1.0,-1.0,0.0),
                        vec4(1.0,1.0,1.0,1.0)
                    );

struct material
{
    vec4 diffuse;
};

material mymaterial = material(vec4(1.0,0.8,0.8,1.0));

in vec3 vertex;
in vec4 color;
in vec3 normal;
// comment
out vec4 vColor;
// comment

void main()
{
    vec4 position = modelMatrix * vec4(vertex, 1.0);
    gl_Position = projectionMatrix * viewMatrix * position;
    // comment

    vec4 normal = normalMatrix * normal;
    normal = normalize(normal);
    // comment

    vec3 lightDirection = normalize(vec3(light0.position));

    vec3 diffuseReflection = vec3(light0.diffuse) * vec3(mymaterial.diffuse) * max(0.0, dot(normal, lightDirection));

    vColor = vec4(diffuseReflection, 1.0);
    // comment
}
