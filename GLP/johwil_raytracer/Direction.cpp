#include "Direction.h"


Direction::Direction(float inX, float inY, float inZ) {
	x = inX;
	y = inY;
	z = inZ;
	glmDirection = glm::vec3(inX, inY, inZ);
}