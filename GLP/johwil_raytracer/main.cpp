
// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include "Scene.h"
#include "Camera.h"
using namespace glm;

int main(void)
{
	Scene scene;
	Camera camera;

	camera.render(scene);
	camera.createImage(); //Creates image and stores it in project files

	return 0;
}