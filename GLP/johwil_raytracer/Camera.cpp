#include "Camera.h"
#include <glm\fwd.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <glm\common.hpp>


Camera::Camera()
{
	createPixels();
}

void Camera::createPixels()
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			pixels[j + (i * HEIGHT)] = Pixel(); 
		}
		
	}
}

void Camera::switchEye(bool e)
{
	eye = e;
	if (eye == false) {
		currEye = eye1;
	}
	else {
		currEye = eye2;
	}
}

void Camera::render(Scene scene)
{
	std::cout << "Rendering scene." << std::endl;

	const int subPixels = 2;
	const float sideLength = 0.0025; //one pixel has the side length 0.0025
	Vertex point;

	//generator of random numbers
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_real_distribution<float> distribution(-0.5, 0.5);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			//Default color of pixel
			ColorDbl samplePixelColor = ColorDbl(0.0f, 0.0f, 0.0f);

			//Subpixels loop
			for (int o = 0; o < subPixels; o++) {
				for (int k = 0; k < subPixels; k++) {

				//	for (int n = 0; n < samplePerPixel; n++) {
						double y = distribution(generator);
						y = (y + o)*sideLength;
						double z = distribution(generator);
						z = (z + k)*sideLength;
						
				//	float y = (HEIGHT / 2.0f - (float)i + 0.5f)*sideLength;

				//	float z = (WIDTH / 2.0f - (float)j + 0.5f)*sideLength;

						point = Vertex(0.0f, y, z);
						
						Ray ray(currEye, (point - currEye), ColorDbl{1.0f,1.0f,1.0f});
						
						scene.castRay(ray);

						pixels[j + i * HEIGHT].addRay(ray);

						samplePixelColor += ray.getColor(); //Hämta ny färg för rayen
				//	}
				}
			}

			ColorDbl pixelColor = samplePixelColor; //kan behöva ändras här???

			pixels[j + i * HEIGHT].setColor(pixelColor); //set new color for pixels

			//Calculate new maximum color value out of red, green and blue values
			float newMaxVal = glm::max(glm::max(pixelColor.red, pixelColor.green), pixelColor.blue);
			if (newMaxVal > maxColorVal) {
				maxColorVal = newMaxVal;
			}
		}
	}
}

void Camera::createImage()
{
	/*
	std::ofstream ofs("./testScene.ppm", std::ios::out | std::ios::binary);
	ofs << WIDTH << " " << HEIGHT;
	std::cout << "File is open " << std::endl;

	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			ColorDbl color = pixels[j + i * HEIGHT].getColor();
			ofs << (unsigned char)(((color.red * 255.0) / maxColorVal)) <<
				(unsigned char)(((color.green * 255.99) / maxColorVal)) <<
				(unsigned char)(((color.blue * 255.99) / maxColorVal));
		}
	}
	ofs.close();*/


	FILE* f = fopen("testScene.ppm", "wb");

	fprintf(f, "P6\n %i %i 255\n", WIDTH, HEIGHT);
	std::cout << "\nFile open\n";

	
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			ColorDbl color = pixels[j + i * HEIGHT].getColor();

			//Normera till 255
			fputc((int)(sqrt((color.red / maxColorVal)) * 255.0), f);
			fputc((int)(sqrt((color.blue / maxColorVal)) * 255.0), f);
			fputc((int)(sqrt((color.green / maxColorVal)) * 255.0), f);
			
		}
	}
	fclose(f);

	std::cout << "Finished creating image. " << std::endl;

	//std::array<std::array<glm::vec3, HEIGHT>, WIDTH> image;
}
