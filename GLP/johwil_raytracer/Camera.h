
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

	float maxColorVal = 0;

private:
	Vertex eye1 = Vertex(-3.0f, 0.0f, 0.0f);
	Vertex eye2 = Vertex(-1.0f, 0.0f, 0.0f);
	
	bool eye = false;
	Vertex currEye = eye1;
	//std::array<std::array<Pixel, HEIGHT>, WIDTH> pixels; //brukade ge "incomplete type", vi behövde #include <array>
	//std::array<std::vector<Pixel>, WIDTH> pixels;
	std::vector<Pixel> pixels{WIDTH*HEIGHT};
	
	const int samplePerPixel = 200;
};

