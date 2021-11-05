#pragma once

#include "Vertex.h"

class Direction
{
private:
	

public:
	Direction(float inX = 0.0f, float inY = 0.0f, float inZ = 0.0f);
	float x, y, z;
	glm::vec3 glmDirection;

	
};

