#pragma once
#include <glm\ext\vector_float3.hpp>


class Vertex
{
public:
	float x, y, z, w;
	glm::vec3 glmVertex;

	Vertex(float inX = 0.0f, float inY = 0.0f, float inZ = 0.0f);
	Vertex operator-(Vertex rhs) {
		return Vertex(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	Vertex operator+(Vertex rhs) {
		return Vertex(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Vertex operator*(float rhs) {
		return Vertex(x * rhs, y * rhs, z * rhs);
	}

};
