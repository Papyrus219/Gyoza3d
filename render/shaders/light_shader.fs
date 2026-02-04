#version 330

out vec4 FragColor;

in vec2 tex_cords;
in vec3 possitions;

uniform sampler2D texture_1;
uniform sampler2D texture_2;

void main()
{
    FragColor = vec4(possitions, 1.0f);
}
