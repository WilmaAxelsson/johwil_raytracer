#include "Camera.h"
#include <glm\fwd.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <glm\common.hpp>
#include <glm\geometric.hpp>


Camera::Camera() 
{
	createPixels();
}

void Camera::createPixels()
{
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			pixels[j + i * HEIGHT] = Pixel{ topRight + Vertex{0.0f, -sideLength * j, -sideLength * i} };
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

	const int subPixels = 4; // SKA VARA 4!!!
	const float subPixelLengths = sideLength / (float)subPixels;
	Vertex point;
	Vertex center;

	int counter = 0;
	static std::default_random_engine generator;
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);

	
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {

			//Default color of pixel
			ColorDbl samplePixelColor = ColorDbl(0.0f, 0.0f, 0.0f);

			//Subpixels loop
			for (int o = 0; o < subPixels; o++) {
				for (int k = 0; k < subPixels; k++) {


						float min = o * subPixelLengths;
						float max = subPixelLengths + o * subPixelLengths;
						float diff = max - min;
						float y = min + (float)distribution(generator) * diff;

						min = k * subPixelLengths;
						max = subPixelLengths + k * subPixelLengths;
						diff = max - min;

						float z = min + (float)distribution(generator) * diff;

						point = Vertex(0.0f, y, z); // används för att flyttar ray intersection point i pixeln till ett random ställe i pixeln


						glm::vec3 normalized = glm::normalize(pixels[j + i * HEIGHT].getPos() - point - currEye);
						Direction directionNormalized = Direction(normalized.x, normalized.y, normalized.z);


						Ray ray{ currEye, directionNormalized, PRIMARY };

						scene.castRay(ray, 0);

						pixels[j + i * HEIGHT].addRay(ray);

						samplePixelColor += ray.getColor(); //Get new color for sample pixel
						

					
				}
			}

			pixels[j + i * HEIGHT].setColor(samplePixelColor); //set new color for pixels
			counter++;
			//Calculate new maximum color value out of red, green and blue values
			float newMaxVal = glm::max(glm::max(samplePixelColor.red, samplePixelColor.green), samplePixelColor.blue);
			if (newMaxVal > maxColorVal) {
				maxColorVal = newMaxVal;
			}
		}
	}

	

}

void Camera::createImage()
{

	FILE* f = fopen("testScene.ppm", "wb");

	fprintf(f, "P6\n %i %i 255\n", WIDTH, HEIGHT);
	std::cout << "\nFile open\n";

	
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {

			ColorDbl color = pixels[j + i * HEIGHT].getColor();
			
			//Normera till 255
			fputc((int)(sqrt((color.red / maxColorVal)) * 255.0), f);
			fputc((int)(sqrt((color.green / maxColorVal)) * 255.0), f);
			fputc((int)(sqrt((color.blue / maxColorVal)) * 255.0), f);
			
		}
	}
	fclose(f);

	std::cout << "Finished creating image. " << std::endl;

}
