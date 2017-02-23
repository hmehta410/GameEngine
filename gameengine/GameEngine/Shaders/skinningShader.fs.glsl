#version 400 core

uniform vec4 baseColor  = vec4(1.0f, 1.0f, 1.0f, 1.0f);
//uniform sampler2D textureUnit0;

// Varying
	in VS_OUT
	{
		vec4 vFragColor;
		//vec2 vTex;
	} fs_in;

	out vec4 color;

void main(void) 
{ 
	color = fs_in.vFragColor * baseColor;// * texture(textureUnit0, fs_in.vTex);
}
 