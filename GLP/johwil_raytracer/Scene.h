#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Triangle.h"
#include "Material.h"
#include "Lightsource.h"
#include "Sphere.h"
#include "materialTypes.h"

class Scene
{
public:
	Scene();
	void castRay(Ray& r);

	ColorDbl DirectLight(Ray& ray, bool or_na);

	void createRoom();
	static const int size = 30;
	Lightsource light;
	Triangle triangleList[size];
	std::vector<Sphere> spheresList;
	Material white, blue, red, green, yellow, pink, purple; //the colors for the walls, floor and roof
	Vertex p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, move;
	Vertex tp0, tp1, tp2, tp3;
	//Direction dirUp, dirDown, dirA, dirB, dirC, dirD, dirE, dirF;

		// 24 trianglar
		//kanske namnge trianglar? för att senare veta vilken triangel som träffas?

		


};

