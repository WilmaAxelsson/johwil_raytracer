#include "Triangle.h"


Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl c, Direction d)
{
	vex1 = v1;
	vex2 = v2;
	vex3 = v3;
	color = c;
	normDirection = d;
}

void Triangle::rayIntersection(Ray ray)
{

}
