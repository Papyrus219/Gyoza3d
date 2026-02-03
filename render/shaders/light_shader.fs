#version 330

out vec4 FragColor;

in vec2 tex_cords;

uniform sampler2D texture_1;
uniform sampler2D texture_2;

void main()
{
    FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
