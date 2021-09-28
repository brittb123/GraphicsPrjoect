#include "GraphicsEngine.h"
#include"GLFW/glfw3.h"

GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}

int GraphicsEngine::run()
{
	int exitCode = 0;

	exitCode = start();

	if (exitCode) 
	{
		return exitCode;
	}



	exitCode = end();
	if (exitCode) 
	{
		return exitCode;
	}
	return 0;
}

int GraphicsEngine::start()
{
	return 0;
}

int GraphicsEngine::update()
{
	return 0;
}

int GraphicsEngine::end()
{
	return 0;
}

bool GraphicsEngine::getGameOver()
{
	bool isGameOver = glfwWindowShouldClose(m_window);
	isGameOver = isGameOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return isGameOver;
}
