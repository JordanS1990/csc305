#version 150

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;

uniform vec3 lightPos;
uniform vec4 lightCol;

in vec4 vColor;
in vec3 vert;
in vec3 nNormals;

out vec4 fColor;

void main()
{
	vec4 diffuse = lightCol;
	vec4 ambient = lightCol * 0.2;
	vec4 specular = vec4(1.0, 1.0, 1.0, 0.4);
	float shininess = 50;
	
	vec3 lamb = normalize(lightPos - vert);	
	
	vec4 diff = clamp((diffuse + vColor), 0.0, 1.0) * max(dot(nNormals, lamb), 0.0);
	diff = clamp(diff, 0.0, 1.0);

	vec3 refl = normalize(reflect(-lamb,nNormals));
	vec3 eye = normalize(-vert);
	vec4 spec = specular * pow(max(dot(refl,eye), 0.0), 0.3*shininess);
	spec = clamp(spec, 0.0, 1.0);

	fColor = ambient + diff + spec;
}
