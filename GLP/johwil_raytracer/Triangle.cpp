#include "Triangle.h"
#include <glm\fwd.hpp>
#include <glm\ext\vector_float3.hpp>
#include <glm\detail\func_geometric.inl>
#include <iostream>


Triangle::Triangle(Vertex _v1, Vertex _v2, Vertex _v3, Material m)
{
	v0 = _v1;
	v1 = _v2;
	v2 = _v3;
	material = m;
	//normDirection = d;
	glm::vec3 directiontemp = glm::normalize(glm::cross(v1.glmVertex - v0.glmVertex, v2.glmVertex - v0.glmVertex));
	normDirection = Direction(directiontemp.x, directiontemp.y, directiontemp.z);

}



bool Triangle::rayIntersection(Ray& ray)
{
	//method to investiagte if ray hits triangle, return true or false

	float minDistance = 1000;

	//Lecture 6 möller trumbore algorithm
	glm::vec3 edge1 = v1.glmVertex - v0.glmVertex;
	glm::vec3 edge2 = v2.glmVertex - v0.glmVertex;
	glm::vec3 T = ray.getStartingP().glmVertex- v0.glmVertex; // T is a point in a triangle ??

	glm::vec3 D = ray.glmDirection; // Direction of ray

	//glm::normalize(D);

	// testar ett test för att se om triangelns normal är "åt rätt håll" för den nuvarande ray:en
	if (glm::dot(D, (glm::vec3(this->normDirection.x, this->normDirection.y, this->normDirection.z))) > 0.0f)
	{
		//std::cout << "Triangel DO face ray" << std::endl;
	}
	else
	{
		//std::cout << "Triangel DO NOT face ray" << std::endl;

	}


	//Kryssprodukten P mellan direction D och edge2
	glm::vec3 P = glm::cross(D, edge2);
	//glm::vec3 P = glm::cross(D, edge2);

	//Kryssprodukten Q mellan T och edge1
	glm::vec3 Q = glm::cross(T, edge1);
	//glm::vec3 Q = glm::cross(T, edge1);

	//Q = glm::normalize(Q);

	//calculate determinant
	float det = glm::dot(P, edge1);
	float epsilon = 0.0000000000001f;
	//if determinant is negative, we are facing the back of the trianlge
	if (det < epsilon) return false;
	
	//slide 9, lec 6
	float inverse = 1.0f / det;

	// We introdue barycentric coordinates. (thease coordinate system to specify ponits with references to a simplex)
	float u = glm::dot(P, T) * inverse;

	if (u < 0 || u > 1) { 
		return false; }
	else {
		//std::cout << "u is larger than 0" << std::endl;
	}
	

	float v = glm::dot(D, Q) * inverse;

	// u, v is the intersection point
	// we know that if triangle meets this u, v, the ray hits the triangle
	// slide 8, lec 6

	if ((u + v) > 1.0f || v < 0.0f) { 
		
		return false;
	}
	else {
		//std::cout << "u +v is smaller! " << std::endl;
	}
	
	//calculate variable t. we need to t "steps" on the ray to get to the intersectionpoint, i.e the end ponit of the ray
	float t = glm::dot(edge2, Q) * inverse;

	//if (t > 1.0f || t <= 0.0f)
	//	return false;
	
	//if (glm::length(Vertex(ray.getStartingP() + ray.glmDirection * t)) < minDistance) {
	// test: skicka tillbaka färgen färgen med rayen
	//if (ray.getMaterial().getType() != SHADOW) {
		ray.setMaterial(getMaterial());
	//}

	ray.setEndingP(ray.getStartingP() + ray.getDirection() );
	ray.setObjectNormal(this->normDirection);

	return true;

}

