#include "Ray.h"

Ray::Ray(Vertex sP, Direction dir, Material m)
{
	startingPoint = sP;
	direction = dir;
	material  = m;
	color = material.getColor();
	glmDirection = glm::vec3(dir.x, dir.y, dir.z);
	
}
