#version 430 core 
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 textcoord;

out vec3 fs_color;
out vec2 fs_textcoord;

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct Light
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform Light light;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vec3 ambient = material.ambient * light.ambient;
	
	fs_color = ambient;
	fs_textcoord = textcoord;
    gl_Position = projection * view * model * vec4(position, 1.0);
}