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
in vec4 texcoord0;

out vec4 vColor;

void main()
{
	vec4 diffuse = lightCol;
	vec4 ambient = lightCol * 0.2;
	vec4 specular = vec4(1.0, 1.0, 1.0, 0.4);
	float shininess = 50;
	
	vec4 v = vec4(vertex, 1.0);
	mat4 modelView = viewMatrix * modelMatrix;
	vec3 thing = vec3(modelView * v);

	vec3 lamb = normalize(lightPos - thing);

	vec4 position = modelView * v;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * v;

	vec3 normal = normalMatrix * normal;
	normal = normalize(normal);

	vec3 lightDirection = normalize(vec3(lightPos));
	
	vec4 diff = clamp((diffuse + color), 0.0, 1.0) * max(dot(normal, lamb), 0.0);
	diff = clamp(diff, 0.0, 1.0);

	vec3 refl = normalize(reflect(-lamb,normal));
	vec3 eye = normalize(-thing);
	vec4 spec = specular * pow(max(dot(refl,eye), 0.0), 0.3*shininess);
	spec = clamp(spec, 0.0, 1.0);

	vColor = ambient + diff + spec;
}
