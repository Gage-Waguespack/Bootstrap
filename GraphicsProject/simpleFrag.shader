//A simple fragment shader
#version 410

in vec4 fColor;
in vec3 fNormal;

uniform vec3 lightDirection;
uniform vec4 lightAmbient;
uniform vec4 lightDiffuse;
uniform vec4 lightSpecular;

out vec4 FragColor;

void main() {
	vec3 surfaceNormal = normalize(fNormal);
	vec3 lightNormal = normalize(lightDirection);

	//vec4 lightColor = vec4(0.8f, 0.2f, 0.2f, 1.0f);

	//color = ambientColor + diffuseColor + specularColor

	//calculate ambient color
	vec4 ambientColor = fColor * lightAmbient;

	//calculate diffuse color
	float lambertTerm = dot(-lightNormal, surfaceNormal);
	lambertTerm = max(0, min(1, lambertTerm));
	vec4 diffuseColor = fColor * lightDiffuse * lambertTerm;


	FragColor = ambientColor + diffuseColor;
}