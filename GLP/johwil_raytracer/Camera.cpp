#include "Camera.h"


Camera::Camera(Vertex ve1, Vertex ve2)
{
	v1 = ve1;
	v2 = ve2;
	currEye = ve1;
}

void Camera::createPixels()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			pixels[i][j] = Pixel();
		}
		
	}
}

void Camera::switchEye(bool e)
{
	eye = e;
	if (eye == false) {
		currEye = v1;
	}
	else {
		currEye = v2;
	}
}

void Camera::render()
{
}
