#version 330
#define DIFFUSE		0
#define POSITION	1
#define NORMAL		2
#define TEXCOORD	3
#define TANGENT		4
#define BITANGENT	5

layout(location = POSITION) in vec3 position;
layout(location = NORMAL) in vec3 normal;
layout(location = TEXCOORD) in vec2 texcoord;

out vec4 position_in_viewspace;
out vec3 normal_in_viewspace;

uniform mat4 WorldMatrix;		// object_to_world
uniform mat4 ViewMatrix;		// world_to_view
uniform mat4 ProjectionMatrix;	// view_to_clip
uniform mat3 NormalMatrix;		// normal_to_view

void main() {
	position_in_viewspace = ViewMatrix * WorldMatrix * vec4(position, 1.0);
	normal_in_viewspace = NormalMatrix * normal;
	gl_Position = ProjectionMatrix * position_in_viewspace;
}
