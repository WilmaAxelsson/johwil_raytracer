#include "Ray.h"

Ray::Ray(Vertex sP, Direction dir, ColorDbl c)
{
	startingPoint = sP;
	direction = dir;
	color  = c;
	glmDirection = glm::vec3(dir.x, dir.y, dir.z);
	
}
