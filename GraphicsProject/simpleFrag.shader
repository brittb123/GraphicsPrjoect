// A simple fragment shader
#version 410

in vec4 color;
out vec4 Fragcolor;

void main() 
{
	Fragcolor = color;
}