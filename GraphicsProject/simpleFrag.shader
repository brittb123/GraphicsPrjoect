// A simple fragment shader
#version 410

in vec4 fColor;
in vec3 fNormal;

uniform vec3 lightDirection;

out vec4 Fragcolor;

void main() 
{
	
	vec3 surfaceNormal = normalize(fNormal);
	vec3 lightNormal = normalize(lightDirection);

	vec4 lightColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	lightNormal = normalize(vec3(-1.0f, -1.0f, -1.0f));

	// Color = ambientColor + diffuseColor + specularColor
	// Calculate diffuse color
	float lambertTerm = max(0, min(1, dot(-lightNormal, surfaceNormal)));
	vec4 diffuseColor = fColor * lightColor * lambertTerm;
		
	Fragcolor = diffuseColor;
}