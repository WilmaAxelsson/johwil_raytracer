#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Ray.h"
#include "materialTypes.h"
#include "Material.h"
class Sphere
{
private:
	Vertex position;
	double radius = 0.0f;
	Material material;

public:
	Sphere(Vertex spPos = Vertex{ 0.0f, 0.0f, 0.0f }, double r = 0.0, Material m = Material{ ColorDbl(0.0f, 0.0f, 0.0f), LAMBERTIAN });
    bool rayIntersection(Ray& r);
	Material getMaterial() { return material; }


};

