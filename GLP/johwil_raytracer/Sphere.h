#pragma once

#include "definitions.h"
#include "ColorDbl.h"
#include "Ray.h"
#include "materialTypes.h"
#include "Material.h"
class Sphere
{
private:
	Vertex position;
	float radius = 0.0f;
	Material material;
	ColorDbl color;

public:
	Sphere();
	~Sphere();

	Sphere(Vertex spPos = Vertex{ 0.0f, 0.0f, 0.0f }, float r = 0.0f, Material m = Material{ ColorDbl(0.0f, 0.0f, 0.0f), LAMBERTIAN });
    bool rayIntersection(Ray& r);
	Material getMaterial() { return material; }
	ColorDbl getColor() { return color; }


};

