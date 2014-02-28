#version 150
const vec4 diffuse_color = vec4(1.0, 0.0, 0.0, 1.0);
out float diffuse_intensity;
in vec4 vColor;
out vec4 fColor;
// comment

void main()
{
    fColor = vColor * diffuse_intensity;
}
