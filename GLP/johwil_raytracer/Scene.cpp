#include "Scene.h"
#include "Triangle.h"
#include <iostream>
#include "materialTypes.h"
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

Scene::Scene() {
	createRoom();
}

Scene::~Scene() = default;

void Scene::createRoom() {
	// Colors with material Lambertian
	white = Material(ColorDbl{ 1.0f, 1.0f, 1.0f }, LAMBERTIAN);
	blue = Material(ColorDbl{ 0.0f, 0.0f, 1.0f }, LAMBERTIAN);
	red = Material(ColorDbl{ 1.0f, 0.0f, 0.0f }, LAMBERTIAN);
	green = Material(ColorDbl{ 0.0f, 1.0f, 0.0f }, LAMBERTIAN);
	yellow = Material(ColorDbl{ 1.0f, 1.0f, 0.0f }, LAMBERTIAN);
	pink = Material(ColorDbl{ 1.0f, 0.75f, 0.79f }, LAMBERTIAN);
	purple = Material(ColorDbl{0.62f, 0.12f, 0.94f}, LAMBERTIAN);


	// the vertices of the floor
	 p1 = Vertex(-3.0f, 0.0f, -5.0f);
	 p2 = Vertex(0.0f, 6.0f, -5.0f);
	 p3 = Vertex(10.0f, 6.0f, -5.0f);
	 p4 = Vertex(13.0f, 0.0f, -5.0f);
	 p5 = Vertex(10.0f, -6.0f, -5.0f);
	 p6 = Vertex(0.0f, -6.0f, -5.0f);
	 p7 = Vertex(5.0f, 0.0f, -5.0f);

	//the vertices of the roof
	 p8 = Vertex(-3.0f, 0.0f, 5.0f);
	 p9 = Vertex(0.0f, 6.0f, 5.0f);
	 p10 = Vertex(10.0f, 6.0f, 5.0f);
	 p11 = Vertex(13.0f, 0.0f, 5.0f);
	 p12 = Vertex(10.0f, -6.0f, 5.0f);
	 p13 = Vertex(0.0f, -6.0f, 5.0f);
	 p14 = Vertex(5.0f, 0.0f, 5.0f);
	 
	/////  THE ROOM //////////////////////////

	triangleList[0] =
		  // Floor, 6 triangles
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
		// Roof, 6 triangles
		Triangle(p14, p8, p9, white);
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
			Triangle(p1, p9, p8, red);
		triangleList[13] =
			Triangle(p1, p2, p9, red);

		triangleList[14] =
			Triangle(p2, p10, p9, blue); 
		triangleList[15] =
			Triangle(p2, p3, p10, blue);

		triangleList[16] =
			Triangle(p3, p11, p10, Material(ColorDbl{ 0.0f, 1.0f, 0.0f }, PERFECT_REFL));
		triangleList[17] =
			Triangle(p3, p4, p11, Material(ColorDbl{ 0.0f, 1.0f, 0.0f }, PERFECT_REFL));


		triangleList[18] =
			Triangle(p4, p12, p11, yellow);
		triangleList[19] =
			Triangle(p4, p5, p12, yellow);


		triangleList[20] =
			Triangle(p5, p13, p12, purple);
		triangleList[21] =
			Triangle(p5, p6, p13, purple);


		triangleList[22] =
			Triangle(p6, p8, p13, pink);
		triangleList[23] =
			Triangle(p6, p1, p8, pink);

	/////////// Tetrahedrons_//////////////////////////
		//tetrahedron 1
		tp0 = Vertex(8.0f, 3.0f, -4.5f);
		tp1 = Vertex(8.0f, 6.0f, -4.5f);
		tp2 = Vertex(5.0f, 4.5f, -4.5f);
		tp3 = Vertex(6.5f, 4.5f, -1.5f);

		triangleList[24] =
			Triangle(tp0, tp1, tp3, red);
		triangleList[25] =
			Triangle(tp0, tp3, tp2, red);
		triangleList[26] =
			Triangle(tp1, tp2, tp3, red);
		triangleList[27] =
			Triangle(tp0, tp2, tp1, red);

		//tetrahedron 2
		tp4 = Vertex(6.0f, 0.0f, -4.9f);
		tp5 = Vertex(6.0f, 3.0f, -4.9f);
		tp6 = Vertex(5.0f, 1.5f, -4.9f);
		tp7 = Vertex(5.5f, 1.5f, -2.9f);

		triangleList[28] =
			Triangle(tp4, tp5, tp7, pink);
		triangleList[29] =
			Triangle(tp4, tp7, tp6, pink);
		triangleList[30] =
			Triangle(tp5, tp6, tp7, pink);
		triangleList[31] =
			Triangle(tp4, tp6, tp5, pink);

		triangleList[32] =
			Triangle(Vertex(5.0f, 2.0f, 1.0f), Vertex(4.0f, 4.0f, 2.0f), Vertex(6.0f, 3.0f, 2.0f), yellow);

		//Add light to scene

		std::vector<Triangle> lightVec = light.getLight();

		triangleList[33] = lightVec.at(0);
		triangleList[34] = lightVec.at(1);
		

		spheresList.push_back(Sphere(Vertex(9.0f, -3.5f, 1.0f), 2.0, Material(ColorDbl(0.0f,1.0f,0.0f),PERFECT_REFL)));
		spheresList.push_back(Sphere(Vertex(5.0f, -5.5f, -2.0f), 1.5, Material(ColorDbl(1.0f, 1.0f, 0.0f), PERFECT_REFL)));
		spheresList.push_back(Sphere(Vertex(5.0f, -1.5f, -4.5f), 1.0, red));


			}

void Scene::castRay(Ray &ray, int rayDepth)
{
	ray.setColor(ColorDbl(0.0f, 0.0f, 0.0f));

	if (rayDepth > 9) { return; } //originally rayDepth > 9
	

	for (Triangle tri : triangleList) {
		if (tri.rayIntersection(ray)) {
		}
	}

	for (Sphere sph : spheresList) {
		if (sph.rayIntersection(ray)) {
		}
	}


	if (ray.getRayType() != SHADOW) {

		// Test what material the triangle has and compute accordingly
		switch (ray.getMaterial().getType())
		{
		case 0: // lightsource
		{
			break;
		}
		case 1: // Lambertian
		{
			
			ColorDbl directLight = DirectLight(ray, rayDepth); //direct light contribution
			
			
			ColorDbl indirectLight = IndirectLight(ray, rayDepth); // indirect light contribution
			
			ray.setColor(directLight + indirectLight);
			break;
		}
		case 2: { //Perfect reflection / Mirror
			if (ray.getRayType() == SECONDARY) {
				ray.setColor(ColorDbl(0.0f, 0.0f, 0.0f));
				break;
			}
			float kr = 0.95; // 95% light reflecteed
			Ray reflectionRay(ray.getEndingP(), glm::normalize(reflect(ray.getDirection(), ray.getObjectNormal())), REFLECTION);
			castRay(reflectionRay, rayDepth + 1);
			ray.setColor(reflectionRay.getColor() * kr);
			break;
		}
		
		default: {
			break;
		}
		}
	}
}

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

ColorDbl Scene::DirectLight(Ray& ray, int current_rayDepth)
{
	// Lambertian reflection 
	// Radiance from point x, with the outgoing direction phiOut equals
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
		float vk;
		//get random point on area light
		float u = distribution(generator);
		float v = distribution(generator);

		Vertex uv = Vertex(edge1*u +  edge2*v);

		uv = uv + Vertex(5.5f, -0.5f, 4.85f);

		Vertex s_i = uv - ray.getEndingP();

		float d_i = glm::length(s_i);
		float cosAlpha = glm::max(0.0f, glm::dot(-s_i, lightNormal)); 
		float cosBeta = glm::max(0.0f, glm::dot(s_i, ray.getObjectNormal()));

		// Form shadow ray
		Direction shadowRayDir = glm::normalize(s_i);
		Ray shadowRay = Ray(ray.getEndingP(), shadowRayDir, SHADOW);
		
		castRay(shadowRay, 0);

		
		float shadowRayLength = glm::length(shadowRay.getEndingP() - shadowRay.getStartingP());
		if (shadowRayLength < d_i) {
			vk = 0.0;
		}
		else {
			vk = 1.0;
		}
		

		directLight +=  ray.getColor() * 0.8f * vk * (cosAlpha * cosBeta / (d_i * d_i));
			
			
	}
	float area = glm::length(glm::cross(v1 - v0, v3 - v0));

	return (directLight*area)/(float)nrofShadowrays;

}

ColorDbl Scene::IndirectLight(Ray &ray, int rayDepth) {

	ColorDbl indirectLight = ColorDbl( 0.0f,0.0f,0.0f );

	// Russian roulette
	float R = 0.25f;
	float random = (float)rand() / RAND_MAX;

	if (random < R) { //If true, we terminate 1/4 of the ray
		return indirectLight;
	}

	//Create local coordinate system
	Direction N = ray.getObjectNormal();
	Direction Nt, Nb;

	if (std::fabs(N.x) > std::fabs(N.y))
		Nt = Direction(N.z, 0.0f, -N.x) / (float)sqrt(N.x * N.x + N.z * N.z);
	else
		Nt = Direction(0.0f, -N.z, N.y) / (float)sqrt(N.y * N.y + N.z * N.z);
	Nb = glm::cross(N, Nt);

	
	float r1 = distribution(generator);
	float r2 = distribution(generator);

	float sinTheta = sqrt(1.0f - r1 * r1);
	float phi = 2.0 * M_PI * r2;
	float x = sinTheta * cosf(phi);
	float z = sinTheta * sinf(phi);
	Direction sampleDirection = Direction(x, r1, z);

	Direction sampleDirectionWorld(
		sampleDirection.x * Nb.x + sampleDirection.y * N.x + sampleDirection.x + sampleDirection.z * Nt.x,
		sampleDirection.x * Nb.y + sampleDirection.y * N.x + sampleDirection.y + sampleDirection.z * Nt.y,
		sampleDirection.x * Nb.z + sampleDirection.y * N.x + sampleDirection.z + sampleDirection.z * Nt.z
	);

	Ray sampleRay = Ray(ray.getEndingP(), glm::normalize(sampleDirectionWorld), SECONDARY);
	castRay(sampleRay, rayDepth + 1);
	indirectLight = (ray.getColor() * 0.6f) * sampleRay.getColor();
	
	return indirectLight;
}

