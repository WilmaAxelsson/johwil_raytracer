#pragma once

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Ray.h"
#include "Material.h"
#include "materialTypes.h"

class Triangle
{
private:
	Vertex v0, v1, v2; // Skapa vertices med inte default constructors?
	Material material;
	Direction normDirection;

public:
	//Triangle(Vertex _v1, Vertex _v2, Vertex _v3, ColorDbl c, Direction d);
	Triangle(Vertex _v1 = Vertex(0.0f, 0.0f, 0.0f), Vertex _v2 = Vertex(0.0f, 0.0f, 0.0f), Vertex _v3 = Vertex(0.0f, 0.0f, 0.0f), Material m = Material(ColorDbl{ 0.0f,0.0f,0.0f },LAMBERTIAN));
	//bool rayIntersection(Ray& ray);
	Material getMaterial() { return material; }
	bool rayIntersection(Ray& ray);
};

