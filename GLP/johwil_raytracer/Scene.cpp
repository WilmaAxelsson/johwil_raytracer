#include "Scene.h"
#include "Triangle.h"
#include <iostream>

Scene::Scene(){

}

void Scene::castRay(Ray& r)
{
	for (Triangle tri : triangleList) {

		if (triangleList->rayIntersection(r)) {
			std::cout << "hau" << std::endl;
		}
	}


}

