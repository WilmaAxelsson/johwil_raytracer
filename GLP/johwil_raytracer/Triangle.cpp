#include "Triangle.h"

#include <iostream>


Triangle::Triangle(Vertex _v1, Vertex _v2, Vertex _v3, Material m)
{
	v0 = _v1;
	v1 = _v2;
	v2 = _v3;
	material = m;
	normDirection = glm::normalize(glm::cross(v1 - v0, v2 - v0));

}

Triangle::~Triangle() = default;


bool Triangle::rayIntersection(Ray& ray)
{
	//Method to investiagte if ray hits triangle, return true or false

	float minimumDistance = 1000;

	//Möller trumbore algorithm
	glm::vec3 edge1 = v1 - v0;
	glm::vec3 edge2 = v2 - v0;
	glm::vec3 T = ray.getStartingP()- v0;

	glm::vec3 D = ray.getDirection(); // Direction of ray


	//Crossproduct P between direction D and edge2
	glm::vec3 P = glm::cross(D, edge2);

	//Crossproduct Q between T and edge1
	glm::vec3 Q = glm::cross(T, edge1);

	//Calculate determinant
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
	

	float v = glm::dot(D, Q) * inverse;

	// u, v is the intersection point
	// we know that if triangle meets this u, v, the ray hits the triangle
	// slide 8, lec 6

	if ((u + v) > 1.0f || v < 0.0f) { 
		
		return false;
	}
	
	//calculate variable t. we need to t "steps" on the ray to get to the intersectionpoint, i.e the end ponit of the ray
	float t = glm::dot(edge2, Q) * inverse;

	if (glm::length(Vertex(ray.getStartingP() + ray.getDirection() * t)) < minimumDistance) {
		ray.setObjectNormal(this->normDirection);
		ray.setEndingP(ray.getStartingP() + ray.getDirection() * t + this->normDirection * 0.001f);
		ray.setColor(getColor());
		minimumDistance = glm::length(ray.getDirection() * t);
		ray.setMaterial(getMaterial());
		
	}

	return true;

}

