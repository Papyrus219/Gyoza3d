#version 330

out vec4 FragColor;

in vec2 tex_cords;

uniform sampler2D texture_1;
uniform sampler2D texture_2;

void main()
{
    FragColor = mix( texture(texture_1, tex_cords), texture(texture_2, tex_cords), 0.4);
}
