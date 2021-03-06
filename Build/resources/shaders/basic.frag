#version 430 core
in vec3 fs_color;
in vec2 fs_textcoord;

out vec4 outColor;
	
uniform sampler2D textureSampler;
	
void main()
{
    //outColor = vec4(fs_color, 1.0) * texture(textureSampler, fs_textcoord);
    outColor =  texture(textureSampler, fs_textcoord);
}