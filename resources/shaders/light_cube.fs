#version 330 core

out vec4 FragColor;

uniform float uLightIntensity;
uniform vec3 uLightColor;

void main(void) {
    
  //gl_FragColor = vec4(1,1,1, 1.0);
  FragColor = vec4(uLightColor, 1.0);
}