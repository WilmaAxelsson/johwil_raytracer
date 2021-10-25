#include "Vertex.h"



Vertex::Vertex(float inX, float inY, float inZ) {
	w = 1;
	x = inX;
	y = inY;
	z = inZ;
	glmVertex = glm::vec3(inX, inY, inZ);
}
