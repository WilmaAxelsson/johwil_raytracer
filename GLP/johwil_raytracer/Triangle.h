#pragma once

#include "definitions.h"
#include "ColorDbl.h"
#include "Ray.h"
#include "Material.h"
#include "materialTypes.h"


class Triangle
{
private:
	Vertex v0, v1, v2;
	Material material;
	Direction normDirection;

public:
	~Triangle();
	Triangle(Vertex _v1 = Vertex(0.0f, 0.0f, 0.0f), Vertex _v2 = Vertex(0.0f, 0.0f, 0.0f), Vertex _v3 = Vertex(0.0f, 0.0f, 0.0f), Material m = Material(ColorDbl{ 0.0f,0.0f,0.0f },LAMBERTIAN));
	Material getMaterial() { return material; }
	ColorDbl getColor() { return material.getColor(); }
	bool rayIntersection(Ray& ray);
};

