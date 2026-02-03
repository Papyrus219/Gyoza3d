#version 330

out vec4 FragColor;

in vec2 tex_cords;

uniform sampler2D texture_1;
uniform sampler2D texture_2;

void main()
{
    FragColor = vec4( vec3( vec3(tex_cords.xyx) + vec3(0.3, 0.4, 0.2) ) , 1.0f);
}
