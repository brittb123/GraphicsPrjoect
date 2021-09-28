#include "GraphicsEngine.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include <iostream>


GraphicsEngine::GraphicsEngine(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

GraphicsEngine::~GraphicsEngine()
{
}

int GraphicsEngine::run()
{
	int exitCode = 0;

	// Start
	exitCode = start();
	if (exitCode) 
	{
		return exitCode;
	}

	//Update
	while (!getGameOver()) {
		exitCode = update();
		if (exitCode)
			return exitCode;

		exitCode = draw();
		if (exitCode)
			return exitCode;

	}

	// End
	exitCode = end();
	if (exitCode) 
	{
		return exitCode;
	}
	return 0;
}

int GraphicsEngine::start()
{
	// Initalizes GLMW
	if (glfwInit() == GLFW_FALSE)
	{
		return -1;
	}

	// Creates a window
	m_window = glfwCreateWindow(m_height, m_width, m_title, nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(m_window);

	// Loads OpenGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("OpenGL Version: %i.%i\n", majorVersion, minorVersion);
	
	return 0;
}

int GraphicsEngine::update()
{	
	if (!m_window) return -4;
	glfwSwapBuffers(m_window);
	glfwPollEvents();	
	return 0;
}

int GraphicsEngine::draw()
{
	if (!m_window) return -5;
	glfwSwapBuffers(m_window);
	return 0;
}

int GraphicsEngine::end()
{
	if (!m_window) return -5;

	glfwDestroyWindow(m_window);
	glfwTerminate();


	return 0;
}

bool GraphicsEngine::getGameOver()
{
	if (!m_window) return true;

	bool isGameOver = glfwWindowShouldClose(m_window);
	isGameOver = isGameOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return isGameOver;
}
