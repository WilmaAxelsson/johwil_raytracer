

#pragma once
#include "Vertex.h"
#include "Pixel.h"



class Camera
{
	static const int size = 800;
	//std::array<std::array<Pixel, size>, size> matrix;

public:
	Camera(Vertex ve1 = Vertex(0,0,0), Vertex ve2 = Vertex(0,0,0));
	void createPixels();
	void switchEye(bool e);
	void render();

private:
	Vertex v1, v2;
	bool eye = false;
	Vertex currEye;

	//Pixel pixels[800][800];
};

