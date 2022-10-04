#include "Ray.h"

Ray::Ray(Vertex sP, Direction dir, RayType rt)
{
	startingPoint = sP;
	direction = dir;
	rayType  = rt;
	
}

Ray::Ray() = default;

Ray::~Ray() = default;
