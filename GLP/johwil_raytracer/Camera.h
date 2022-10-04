
#pragma once
#include "Pixel.h"

#include <array>
#include <vector>
#include "Scene.h"
#include "definitions.h"

const int HEIGHT = 800;
const int WIDTH = 800;

class Camera
{
public:
	Camera();
	~Camera() {};
	void switchEye(bool e);
	void render(Scene scene);
	void createImage();
	void createPixels();
	
	const float sideLength = 0.0025f; //one pixel has the side length 0.0025
	float maxColorVal = 0.0f;

private:
	Vertex eye1 = Vertex(-2.0f, 0.0f, 0.0f);
	Vertex eye2 = Vertex(-1.0f, 0.0f, 0.0f);

	// Camera plane
	Vertex topLeft{ 0.0f, -1.0f, 1.0f };
	Vertex topRight{0.0f, 1.0f, 1.0f};
	Vertex bottomLeft{0.0f, -1.0f, -1.0f};
	Vertex bottomRight{ 0.0f, 1.0f, -1.0f };

	bool eye = false;
	Vertex currEye = eye2;

	std::vector<Pixel> pixels{WIDTH*HEIGHT};

	std::vector<Pixel> vec;
	const int samplePerPixel = 200;
};

