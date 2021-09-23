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
	Scene scene = Scene();
	Camera camera = Camera(Vertex(0, 0, 0), Vertex(1, 0, 0));

	return 0;
}