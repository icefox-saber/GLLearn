#version 330 core

out vec4 color;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D Texture1;
uniform sampler2D Texture2;

void main()
{
    color = mix(texture(Texture1, TexCoord), texture(Texture2, TexCoord), 0.2)*vec4(ourColor,1.0);
} 