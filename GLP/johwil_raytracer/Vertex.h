#pragma once
#include <glm\ext\vector_float3.hpp>


class Vertex
{
public:
	float x, y, z, w;
	glm::vec3 glmVertex = glm::vec3(x, y, z);

	Vertex(float inX = 0, float inY = 0, float inZ = 0);
	Vertex operator-(Vertex rhs) {
		return Vertex(x - rhs.x, y - rhs.y, z - rhs.z);
	}

};
