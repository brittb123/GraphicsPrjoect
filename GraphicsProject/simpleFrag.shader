// A simple fragment shader
#version 410

in vec4 fColor;
in vec2 fTexCoord;
out vec4 pColor;

uniform sampler2D diffuseTexture;

void main() 
{
	pColor = fColor * texture(diffuseTexture, fTexCoord);
}