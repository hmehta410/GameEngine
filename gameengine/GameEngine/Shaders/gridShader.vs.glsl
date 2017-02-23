#version 400 core

// Uniforms
	uniform mat4 world_matrix;
	uniform mat4 view_matrix;
	uniform mat4 proj_matrix;
	uniform vec4 grid_color;

// Attributes
	layout (location = 0) in vec2 vert;
	  
// Varying
	out VS_OUT
	{
		vec4 vFragColor;
	} vs_out;


void main(void) 
{ 
	vs_out.vFragColor.a = grid_color.a;
	vec4 position = vec4(vert.x, 0.0, vert.y, 1.0);
	gl_Position = proj_matrix * view_matrix * world_matrix * position;  
}