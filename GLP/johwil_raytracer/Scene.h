#pragma once

#include "definitions.h"
#include "ColorDbl.h"
#include "Triangle.h"
#include "Material.h"
#include "Lightsource.h"
#include "Sphere.h"
#include "materialTypes.h"

class Scene
{
private:
	int scene_rayDepth = 0;
public:
	Scene();
	~Scene();
	void castRay(Ray& r, int rayDepth);

	ColorDbl DirectLight(Ray& ray, int rayDepth);

	ColorDbl IndirectLight(Ray& ray, int rayDepth);

	void createRoom();
	static const int size = 35;
	Lightsource light;
	Triangle triangleList[size];
	std::vector<Sphere> spheresList;
	Material white, blue, red, green, yellow, pink, purple;
	Vertex p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, move;
	Vertex tp0, tp1, tp2, tp3, tp4, tp5, tp6, tp7;

		
		


};

