// A simple fragment shader
#version 410

in vec4 fColor;
in vec3 fNormal;

out vec4 Fragcolor;

void main() 
{
	Fragcolor = fColor;
}