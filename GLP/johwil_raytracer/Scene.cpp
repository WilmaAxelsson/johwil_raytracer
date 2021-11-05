#include "Scene.h"
#include "Triangle.h"
#include <iostream>
#include "materialTypes.h"
#include <random>
#include <glm\geometric.hpp>

Scene::Scene() {
	createRoom();
}

void Scene::createRoom() {
	// Colors/materials 
	white = Material(ColorDbl{ 1.0f, 1.0f, 1.0f }, LAMBERTIAN);
	blue = Material(ColorDbl{ 0.0f, 0.0f, 1.0f }, LAMBERTIAN);
	red = Material(ColorDbl{ 1.0f, 0.0f, 0.0f }, LAMBERTIAN);
	green = Material(ColorDbl{ 0.0f, 1.0f, 0.0f }, LAMBERTIAN);
	yellow = Material(ColorDbl{ 1.0f, 1.0f, 0.0f }, LAMBERTIAN);
	pink = Material(ColorDbl{ 1.0f, 0.75f, 0.79f }, LAMBERTIAN);
	purple = Material(ColorDbl{0.62f, 0.12f, 0.94f}, LAMBERTIAN);


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

		//Add light to scene

		std::vector<Triangle> lightVec = light.getLight();

		triangleList[28] = lightVec.at(0);
		triangleList[29] = lightVec.at(1);

		spheresList.push_back(Sphere(Vertex(-5.0f, 3.5f, 1.0f), 1.0, Material(ColorDbl(0.0f,1.0f,0.0f),PERFECT_REFL)));


			}

void Scene::castRay(Ray &ray)
{
	ray.setColor(ColorDbl(0.0f, 0.0f, 0.0f));

	for (Triangle tri : triangleList) {
	//std::cout << "Triangle color: " << tri.getColor().red << ", "<< tri.getColor().blue << std::endl;
		if (tri.rayIntersection(ray)) {
			std::cout << "Color of triangle: " << tri.getMaterial().getColor().red << ", " << tri.getMaterial().getColor().green << ", " << tri.getMaterial().getColor().blue << std::endl;
			
		}
		//if (triangleList->rayIntersection(r)) {
			//r.setColor(tri.getColor());
		//}
	}

	for (Sphere sph : spheresList) {
		if (sph.rayIntersection(ray)) {
			
		}
	}

	// Vi vill inte räkna ut ytan om shadowray. Vi vill bara sätta rayens slutpunkt!

	if (ray.getMaterial().getType() != SHADOW) {

		//int test = ray.getMaterial().type;
		// Test what material the triangle has and compute accordingly
		switch (ray.getMaterial().getType())
		{
		case 0: // lightsource
		{
			break;
		}
		case 1: // Lambertian
		{
			ColorDbl directLight = DirectLight(ray, false);// direct light contribution
			// indirect light contribution
		}
		case 2: { //Perfect reflection
		}
		case 3: { // Transparent

		}
		case 4: { //Oren nayar
			ColorDbl directLight = DirectLight(ray, true);// direct light contribution

		}
		default: {
			break;
		}
		}
	}
}

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

ColorDbl Scene::DirectLight(Ray& ray, bool or_na)
{
	// Lambertian reflection 
	// Radiencen from pont x, with the out going direction phiOut equals
	// the incoming radiance from every possible direction multiplyed by the surface's reflectivity, divided by pi.

	ColorDbl directLight = ColorDbl(0.0f, 0.0f, 0.0f);

	//corners of area light
	Vertex v0 = Vertex(0.0f, 0.0f, 0.0f);
	Vertex v1 = Vertex(0.0f, 1.0f, 0.0f);
	Vertex v2 = Vertex(1.0f, 0.0f, 0.0f);
	Vertex v3 = Vertex(1.0f, 1.0f, 0.0f);
	Vertex edge1 = v1 - v0;
	Vertex edge2 = v2 - v0;

	Direction lightNormal = Direction(0.0f, 0.0f, -1.0f);

	int nrofShadowrays = 3;
	for (int i = 0; i < nrofShadowrays; i++) {

		//get random point on area light
		float u = distribution(generator);
		float v = distribution(generator);

		Vertex uv = Vertex(edge1*u +  edge2*v);

		uv = uv + Vertex(-1.5f, 2.0f, 4.95f);

		Vertex s_i = uv - ray.getEndingP();
		s_i.glmVertex = glm::vec3(s_i.x, s_i.y, s_i.z);

		float d_i = glm::length(s_i.glmVertex);
		float cosAlpha = glm::max(0.0f, glm::dot(-s_i.glmVertex, lightNormal.glmDirection));
		float cosBeta = glm::max(0.0f, glm::dot(s_i.glmVertex, ray.getObjectNormal().glmDirection));

		// shadow ray

		glm::vec3 shadowRayDir = glm::normalize(s_i.glmVertex);
		Ray shadowRay = Ray(ray.getEndingP(), Direction(shadowRayDir.x, shadowRayDir.y, shadowRayDir.z), Material(ColorDbl{ 0.0f,0.0f,0.0f }, SHADOW));
		
		castRay(shadowRay);

		//glm::vec3 glm_dirShadowray = glm::vec3(shadowRay.getDirection().x, shadowRay.getDirection().y, shadowRay.getDirection().z);
		//float shadowRayLength = glm::length(glm_dirShadowray);
		

	}

	return directLight;

}

