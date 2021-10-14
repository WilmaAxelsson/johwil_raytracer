#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Triangle.h"

class Scene
{
public:
	Scene();
	void castRay(Ray& r);

	//the colors for the walls, floor and roof
	ColorDbl white = ColorDbl(1,1,1);
	ColorDbl blue = ColorDbl(0, 0, 1);
	ColorDbl red = ColorDbl(1, 0, 0);
	ColorDbl green = ColorDbl(0, 1, 0);
	ColorDbl yellow = ColorDbl(1, 1, 0);
	ColorDbl pink = ColorDbl(1, 0.75, 0.79);
	ColorDbl purple = ColorDbl(0.62, 0.12, 0.94);

	// the vertices of the floor
	Vertex p1 = Vertex(6, 0, 0);
	Vertex p2 = Vertex(0, 6, 0);
	Vertex p3 = Vertex(0, 12, 0);
	Vertex p4 = Vertex(6, 18, 0);
	Vertex p5 = Vertex(12, 12, 0);
	Vertex p6 = Vertex(12, 6, 0);
	Vertex p7 = Vertex(6, 9, 0);

	//the vertices of the roof
	Vertex p8 = Vertex(6, 0, 6);
	Vertex p9 = Vertex(0, 6, 6);
	Vertex p10 = Vertex(0, 12, 6);
	Vertex p11 = Vertex(6, 18, 6);
	Vertex p12 = Vertex(12, 12, 6);
	Vertex p13 = Vertex(12, 6, 6);
	Vertex p14 = Vertex(6, 9, 6);

	//directions
	Direction dirUp = Direction(0, 0, 1);
	Direction dirDown = Direction(0, 0, -1);
	Direction dirA = Direction(0.5, 0.5, 0); //diagonal left, closest wall
	Direction dirB = Direction(0.5, -0.5, 0); //diagonal left, farthest wall
	Direction dirC = Direction(-0.5, -0.5, 0); // diagonal right, farthest wall
	Direction dirD = Direction(-0.5, 0.5, 0); // diagonal right, closest wall

	Direction dirE = Direction(1, 0, 0); //left wall
	Direction dirF = Direction(-1, 0, 0); //right wall

	static const int size = 24;
	// 24 trianglar
	//kanske namnge trianglar? för att senare veta vilken triangel som träffas?
	
	Triangle triangleList[size] = { 
	// Floor, 6 trianglar
	Triangle(p1, p7, p2, white, dirUp), //a
	Triangle(p2, p7, p3, white, dirUp), //b
	Triangle(p7, p4, p3, white, dirUp), //c
	Triangle(p7, p5, p4, white, dirUp), //d
	Triangle(p7, p5, p6, white, dirUp), //e
	Triangle(p7, p6, p1, white, dirUp), //f

	//Roof, 6 trianglar
	Triangle(p8, p14, p9, white, dirDown),
	Triangle(p9, p14, p10, white, dirDown),
	Triangle(p14, p11, p10, white, dirDown),
	Triangle(p14, p12, p11, white, dirDown),
	Triangle(p14, p12, p13, white, dirDown),
	Triangle(p14, p13, p8, white, dirDown),


	//Six walls, 12 trianglar (2 för varje vägg)
	Triangle(p1, p9, p8, red, dirA),
	Triangle(p1, p2, p9, red, dirA),

	Triangle(p2, p10, p9, blue, dirE),
	Triangle(p2, p10, p3, blue, dirE),

	Triangle(p3, p11, p10, green, dirB),
	Triangle(p3, p11, p4, green, dirB),

	Triangle(p4, p12, p11, yellow, dirC),
	Triangle(p4, p12, p5, yellow, dirC),

	Triangle(p5, p13, p12, purple, dirF),
	Triangle(p5, p13, p6, purple, dirF),

	Triangle(p6, p8, p13, pink, dirD),
	Triangle(p6, p8, p1, pink, dirD) };

};

