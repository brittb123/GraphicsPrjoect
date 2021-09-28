#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include <iostream>

int main() 
{

	// Initalizes GLMW
	if (glfwInit() == GLFW_FALSE) 
	{
		return -1;
	}

	// Creates a window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Test Window", nullptr, nullptr);
	if (!window) 
	{
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(window);

	// Loads OpenGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) 
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("OpenGL Version: %i.%i\n", majorVersion, minorVersion);

	// Removes waste and exits program
	glfwDestroyWindow(window);
	glfwTerminate();



	return 0;
}