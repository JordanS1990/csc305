#version 150
uniform sampler2D colormap;
uniform sampler2D bumpmap;
uniform vec4 lightCol;
uniform vec3 lightPos;

in vec3 nNormals;
in vec3 v;
in vec3 fTexCoord;
out vec4 fColor;
// comment

void main()
{
    vec4 diffuse = lightCol;
    vec4 ambient = lightCol * 0.1;
    vec4 specular = vec4(1.0, 1.0, 1.0, 0.4);
    float shininess = 50;

    vec3 normal = normalize(texture(bumpmap, fTexCoord.xy).rgb * 2.0 - 1.0);

    vec3 lamb = normalize(lightPos - v);

    vec4 diff = diffuse * max(dot(normal, lamb), 0.0);
    diff = clamp(diff, 0.0, 1.0);

    vec4 color = texture(colormap, fTexCoord.xy);

    vec3 refl = normalize(reflect(-lamb,normal));
    vec3 eye = normalize(-v);
    vec4 spec = specular * pow(max(dot(refl,eye), 0.0), 0.3*shininess);
    spec = clamp(spec, 0.0, 1.0);

    fColor = clamp(color + diff + ambient, 0.0, 1.0);
}
