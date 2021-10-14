#include "Triangle.h"
#include <glm\fwd.hpp>
#include <glm\ext\vector_float3.hpp>
#include <glm\detail\func_geometric.inl>


Triangle::Triangle(Vertex _v1, Vertex _v2, Vertex _v3, ColorDbl c, Direction d)
{
	v0 = _v1;
	v1 = _v2;
	v2 = _v3;
	color = c;
	normDirection = d;
	// normDirection = glm::normalize(glm::cross(vex2-vex1, vex3-vex1));

}

bool Triangle::rayIntersection(Ray& ray)
{
	//method to investiagte if ray hits triangle, return true or false

	float minDistance = 10000;

	//Lecture 6 möller trumbore algorithm
	glm::vec3 edge1 = v1.glmVertex - v0.glmVertex;
	glm::vec3 edge2 = v2.glmVertex - v0.glmVertex;
	glm::vec3 T = ray.getStartingP().glmVertex- v0.glmVertex;
	glm::vec3 D = ray.getEndingP().glmVertex - ray.getStartingP().glmVertex; // Direction of ray

	glm::normalize(D);

	//Kryssprodukten P mellan direction D och edge2
	glm::vec3 P = glm::cross(D, edge2);

	//Kryssprodukten Q mellan T och edge1
	glm::vec3 Q = glm::cross(T, edge1);

	//calculate determinant
	float det = glm::dot(P, edge1);
	float epsilon = 0.0000000000001f;
	//if determinant is very small, the ray misses the triangle
	if (det < epsilon) return false;
	
	
	//slide 9, lec 6
	float inverse = 1.0f / det;

	float u = float(glm::dot(P, T) * inverse);

	float v = float(glm::dot(Q, D) * inverse);

	// u, v is the intersection point
	// we know that if triangle meets this u, v, the ray hits the triangle
	// slide 8, lec 6

	if ( (u + v) > 1.0f || u < 0.0f || v < 0.0f) return false;
	
	//calculate variable t. we need to t "steps" on the ray to get to the intersectionpoint, i.e the end ponit of the ray
	float t = glm::dot(Q, edge2) * inverse;

	if (t > epsilon) return true;
	
	// test: skicka tillbaka färgen färgen med rayen
	ray.setColor(getColor());


	return true;

}

