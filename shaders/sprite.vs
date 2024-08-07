#version 330 core
layout (location = 0) in vec4 vertex; 

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 projection;

void main()
{	//model downscaling?
	gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0); //x,y,z,w (z and w irrelevant for 2D)
	TexCoord = vertex.yz;
}