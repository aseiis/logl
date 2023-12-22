#version 330 core

in vec3 vertexColor;

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D fragTexture;

void main()
{
	//FragColor = vec4(vertexColor, 1.0f);
	FragColor = texture(fragTexture, TexCoord);
}