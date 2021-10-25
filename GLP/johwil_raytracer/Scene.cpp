#include "Scene.h"
#include "Triangle.h"
#include <iostream>

Scene::Scene() {
	createRoom();
}

void Scene::createRoom() {
	white = ColorDbl(1.0f, 1.0f, 1.0f);
	blue = ColorDbl(0.0f, 0.0f, 1.0f);
	red = ColorDbl(1.0f, 0.0f, 0.0f);
	green = ColorDbl(0.0f, 1.0f, 0.0f);
	yellow = ColorDbl(1.0f, 1.0f, 0.0f);
	pink = ColorDbl(1.0f, 0.75f, 0.79f);
	purple = ColorDbl(0.62f, 0.12f, 0.94f);

	move = Vertex(0.0f, 0.0f, 0.0f);

	// the vertices of the floor
	 p1 = Vertex(-3.0f, 0.0f, -5.0f) + move;
	 p2 = Vertex(0.0f, 6.0f, -5.0f) + move;
	 p3 = Vertex(10.0f, 6.0f, -5.0f) + move;
	 p4 = Vertex(13.0f, 0.0f, -5.0f) + move;
	 p5 = Vertex(10.0f, -6.0f, -5.0f) + move;
	 p6 = Vertex(0.0f, -6.0f, -5.0f) + move;
	 p7 = Vertex(5.0f, 0.0f, -5.0f) + move;

	//the vertices of the roof
	 p8 = Vertex(-3.0f, 0.0f, 5.0f) + move;
	 p9 = Vertex(0.0f, 6.0f, 5.0f) + move;
	 p10 = Vertex(10.0f, 6.0f, 5.0f) + move;
	 p11 = Vertex(13.0f, 0.0f, 5.0f) + move;
	 p12 = Vertex(10.0f, -6.0f, 5.0f) + move;
	 p13 = Vertex(0.0f, -6.0f, 5.0f) + move;
	 p14 = Vertex(5.0f, 0.0f, 5.0f) + move;

	

	 //directions
	  /*dirUp = Direction(0.0f, 0.0f, 1.0f);
	  dirDown = Direction(0.0f, 0.0f, -1.0f);
	  dirA = Direction(0.5f, 0.5f, 0.0f); //diagonal left, closest wall
	  dirB = Direction(0.5f, -0.5f, 0.0f); //diagonal left, farthest wall
	  dirC = Direction(-0.5f, -0.5f, 0.0f); // diagonal right, farthest wall
	  dirD = Direction(-0.5f, 0.5f, 0.0f); // diagonal right, closest wall

	  dirE = Direction(1.0f, 0.0f, 0.0f); //left wall
	  dirF = Direction(-1.0f, 0.0f, 0.0f); //right wall
	  */


	 //Ger grön triangel:
	// triangleList[0] =
		 // Floor, 6 trianglar

	//	 Triangle(Vertex(7.0f, -0.1f, -0.1f), Vertex(7.0f, 0.1f, -0.1f), Vertex(7.0f, 0.0f, 0.1f), green); //a // dirUp
	 //  Triangle(Vertex(-3.0f, -3.0f, -1.0f), Vertex(-3.0f, 3.0f, -1.0f), Vertex(-3.0f, 0.0f, 1.0f), green); //a // dirUp
	  
	 
	/////__THE ROOM__//////////////////////////
	triangleList[0] =
		  // Floor, 6 trianglar
		  Triangle(p7, p2, p1, white); //a // dirUp
	triangleList[1] =
		  Triangle(p7, p3, p2, white); //b
	triangleList[2] =
		  Triangle(p7, p4, p3, white); //c
	triangleList[3] =
		  Triangle(p7, p5, p4, white); //d
	triangleList[4] =
		  Triangle(p7, p6, p5, white); //e
	triangleList[5] =
		  Triangle(p7, p1, p6, white); //f

	triangleList[6] =
		// roof, 6 trianglar
		Triangle(p14, p8, p9, white); // dirDown
	triangleList[7] =
		Triangle(p14, p9, p10, white);
	triangleList[8] =
		Triangle(p14, p10, p11, white);
	triangleList[9] =
		Triangle(p14, p11, p12, white);
	triangleList[10] =
		Triangle(p14, p12, p13, white);
	triangleList[11] =
		Triangle(p14, p13, p8, white);

		// walls 
		triangleList[12] =
			Triangle(p1, p9, p8, red); //dirA
		triangleList[13] =
			Triangle(p1, p2, p9, red);

		triangleList[14] =
			Triangle(p2, p10, p9, blue); // dirE
		triangleList[15] =
			Triangle(p2, p3, p10, blue);

		triangleList[16] =
			Triangle(p3, p11, p10, green); //dirB
		triangleList[17] =
			Triangle(p3, p4, p11, green);


		triangleList[18] =
			Triangle(p4, p12, p11, yellow); //dirC
		triangleList[19] =
			Triangle(p4, p5, p12, yellow);


		triangleList[20] =
			Triangle(p5, p13, p12, purple); //dirF
		triangleList[21] =
			Triangle(p5, p6, p13, purple);


		triangleList[22] =
			Triangle(p6, p8, p13, pink);
		triangleList[23] =
			Triangle(p6, p1, p8, pink);
		/////////////////////////////////////////////

	/////__THE tetrahedron_//////////////////////////

	//Vertex 
		tp0 = Vertex(6.0f, 2.0f, 0.0f);
		tp1 = Vertex(6.0f, 5.0f, 0.0f);
		tp2 = Vertex(3.0f, 3.5f, 0.0f);
		tp3 = Vertex(4.5f, 3.5f, 3.0f);

		triangleList[24] =
			Triangle(tp0, tp1, tp3, red);
		triangleList[25] =
			Triangle(tp0, tp3, tp2, red);
		triangleList[26] =
			Triangle(tp1, tp2, tp3, red);
		triangleList[27] =
			Triangle(tp0, tp1, tp2, red);
			}

void Scene::castRay(Ray &r)
{
	r.setColor(ColorDbl(0.0f, 0.0f, 0.0f));
	for (Triangle tri : triangleList) {
	//std::cout << "Triangle color: " << tri.getColor().red << ", "<< tri.getColor().blue << std::endl;
		if (tri.rayIntersection(r)) {
			std::cout << "Color of triangle: " << tri.getColor().red << ", " << tri.getColor().green << ", " << tri.getColor().blue << std::endl;
			
		}
		//if (triangleList->rayIntersection(r)) {
			//r.setColor(tri.getColor());
		//}
	}


}

