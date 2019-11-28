#version 130

in vec2 uv_interp;

uniform sampler2D texture_map;

void main() 
{
	gl_FragColor = texture(texture_map, uv_interp);
}