
#pragma once
#include "Vertex.h"
#include "Pixel.h"

#include <array>
#include <vector>
#include "Scene.h"

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
	
	const float sideLength = 0.0025; //one pixel has the side length 0.0025
	float maxColorVal = 0;

private:
	// Vertex eye2 = Vertex(eye1.x + 2, eye1.y, eye1.z)//??
	// scenens mittpunkt: Vertex(6.0f, 9.0f, 3.0f);
	Vertex eye1 = Vertex(-2.0f, 0.0f, 0.0f);
	Vertex eye2 = Vertex(-1.0f, 0.0f, 0.0f);

	// Camera plane
	Vertex topLeft{ 0.0f, -1.0f, 1.0f };
	Vertex topRight{0.0f, 1.0f, 1.0f};
	Vertex bottomLeft{0.0f, -1.0f, -1.0f};
	Vertex bottomRight{ 0.0f, 1.0f, -1.0f };

	bool eye = false;
	Vertex currEye = eye2;
	//std::array<std::array<Pixel, HEIGHT>, WIDTH> pixels; //brukade ge "incomplete type", vi behövde #include <array>
	//std::array<std::vector<Pixel>, WIDTH> pixels;

	std::vector<Pixel> pixels{WIDTH*HEIGHT}; //linder

	//std::vector<std::vector<Pixel> > pixels; //moren
	std::vector<Pixel> vec;
	const int samplePerPixel = 200;
};

