#include "GraphicsEngine.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "glm/ext.hpp"
#include <iostream>

GraphicsEngine::GraphicsEngine() : GraphicsEngine(1280, 720, "Graphics") {};

GraphicsEngine::GraphicsEngine(int width, int height, const char* title)
{
	m_world = new World(width, height);
	m_width = width;
	m_height = height;
	m_title = title;
}

GraphicsEngine::~GraphicsEngine()
{
	delete m_world;
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
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
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

	// Initializes the screen
	glClearColor(0.2f, 0.2f, 0.2f, 0.1f);
	glEnable(GL_DEPTH_TEST);

	//Initialize the shader
	m_shader.loadShader
	(
		aie::eShaderStage::VERTEX,
		"simpleVert.shader"
	);

	m_shader.loadShader
	(
		aie::eShaderStage::FRAGMENT,
		"simpleFrag.shader"
	);
	if(!m_shader.link())
	{
		printf("Shader Error: %s\n", m_shader.getLastError());
			return -10;
	}

	m_world->start();
	return 0;
}

int GraphicsEngine::update()
{	
	if (!m_window) return -4;

	glfwPollEvents();	
	return 0;
}

int GraphicsEngine::draw()
{
	if (!m_window) return -5;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader.bind();

	glm::mat4 projectionViewModel = m_world->getProjectionViewModel();
	m_shader.bindUniform("projectionViewModel", projectionViewModel);

	m_world->draw();

	glfwSwapBuffers(m_window);

	return 0;
}

int GraphicsEngine::end()
{
	if (!m_window) return -6;

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
