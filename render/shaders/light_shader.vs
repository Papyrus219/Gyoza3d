#version 330

layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 a_normals;
layout (location = 2) in vec2 a_tex_cords;

out vec2 tex_cords;
out vec3 possitions;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(a_pos, 1.0f);

    tex_cords = a_tex_cords;
    possitions = a_pos;
}
