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
	/*
	for (int i = 0; i < HEIGHT; i++) {

		for (int j = 0; j < WIDTH; j++) {
			
			vec.push_back(Pixel());
			
		}
		pixels.push_back(vec);
		vec.clear();
		
	}
	*/
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
	const float subPixelLengths = sideLength / (float)subPixels;
	Vertex point;
	Vertex center;

	//generator of random numbers
	/*std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_real_distribution<float> distribution(-0.5, 0.5);
	*/

	static std::default_random_engine generator;
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {

			//Default color of pixel
			ColorDbl samplePixelColor = ColorDbl(0.0f, 0.0f, 0.0f);
			//center = Vertex(0.0f, ((float)HEIGHT / 2.0f - (float)i + 0.5f) * sideLength, ((float)WIDTH / 2.0f - (float)j + 0.5f) * sideLength);
			
			//center = Vertex(0.0f, i*sideLength - 0.99875, j*sideLength - 0.99875);

			//std::cout << "Center: " << "X: "<< center.x << ", y: "<< center.y << ", z: "<< center.z << std::endl;
			//Subpixels loop
			for (int o = 0; o < subPixels; o++) {
				for (int k = 0; k < subPixels; k++) {

					//for (int n = 0; n < samplePerPixel; n++) {

						float min = o * subPixelLengths;
						float max = subPixelLengths + o * subPixelLengths;
						float diff = max - min;
						float y = min + distribution(generator) * diff;

						min = k * subPixelLengths;
						max = subPixelLengths + k * subPixelLengths;
						diff = max - min;

						float z = min + distribution(generator) * diff;

						point = Vertex(0.0f, y, z); // används för att flyttar ray intersection point i pixeln till ett random ställe i pixeln

						point.glmVertex = glm::vec3(point.x, point.y, point.z);

						glm::vec3 normalized = glm::normalize(pixels[j + i * HEIGHT].pixelVec - point.glmVertex - currEye.glmVertex);
						Direction directionNormalized = Direction(normalized.x, normalized.y, normalized.z);


						Ray ray{ currEye, directionNormalized, Material(ColorDbl{0.0f,0.0f,0.0f}, LAMBERTIAN) };

						scene.castRay(ray);

						//pixels[i][j].addRay(ray);
						pixels[j + i * HEIGHT].addRay(ray);

						samplePixelColor += ray.getColor(); //Hämta ny färg för sample pixel färgen
					//}
					//float y = (((float)subPixels / 2.0f) - o + distribution(generator)* sideLength);

					//float z = (((float)subPixels / 2.0f) - k + distribution(generator)* sideLength);
						
					//point = center + Vertex(0.0f, y, z);

					/*point.glmVertex = glm::vec3(point.x, point.y, point.z);

					glm::vec3 normalized = glm::normalize(point.glmVertex - currEye.glmVertex);
					Direction normalizedV = Direction(normalized.x,normalized.y,normalized.z);
				
					Ray ray(currEye, normalizedV, ColorDbl{0.0f,0.0f,0.0f});
				
					scene.castRay(ray);

					pixels[i][j].addRay(ray);

					samplePixelColor += ray.getColor(); //Hämta ny färg för sample pixel färgen
				//	}
				*/
				}
			}

			//ColorDbl pixelColor = samplePixelColor/(((float)subPixels * (float)subPixels) * (1.0f / 0.75f)); //kan behöva ändras här???

			//pixels[i][j].setColor(pixelColor); //set new color for pixels
			pixels[j + i * HEIGHT].setColor(samplePixelColor);

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

			//ColorDbl color = pixels[i][j].getColor();
			ColorDbl color = pixels[j + i * HEIGHT].getColor();
			
			//Normera till 255
			fputc((int)(sqrt((color.red / maxColorVal)) * 255.0), f);
			fputc((int)(sqrt((color.green / maxColorVal)) * 255.0), f);
			fputc((int)(sqrt((color.blue / maxColorVal)) * 255.0), f);
			
		}
	}
	fclose(f);

	std::cout << "Finished creating image. " << std::endl;

	//std::array<std::array<glm::vec3, HEIGHT>, WIDTH> image;
}
