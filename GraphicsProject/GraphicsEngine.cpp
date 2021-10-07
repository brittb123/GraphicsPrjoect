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

	m_shader = new aie::ShaderProgram();
}

GraphicsEngine::~GraphicsEngine()
{
	delete m_world;

}

int GraphicsEngine::run()
{
	int exitCode = 0;

	double currentTime = 0.0f;
	double previousTime = 0.0f;
	double deltaTime = 0.0f;

	// Start
	exitCode = start();
	if (exitCode) 
	{
		return exitCode;
	}

	//Update
	while (!getGameOver()) 
	{
	    // Get the current time
		currentTime = glfwGetTime();

	    // Find the change in time
		deltaTime = currentTime - previousTime;

		// Store the current time for the next loop
		previousTime = currentTime;

		exitCode = update(deltaTime);
		if (exitCode)
			return exitCode;

		exitCode = draw(m_shader);
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
	m_shader->loadShader
	(
		aie::eShaderStage::VERTEX,
		"simpleVert.shader"
	);

	m_shader->loadShader
	(
		aie::eShaderStage::FRAGMENT,
		"simpleFrag.shader"
	);
	if(!m_shader->link())
	{
		printf("Shader Error: %s\n", m_shader->getLastError());
			return -10;
	}

	m_world->setWindow(m_window);

	m_world->start();
	return 0;
}

int GraphicsEngine::update(double deltaTime)
{	
	if (!m_window) return -4;

	m_world->update(deltaTime);

	glfwPollEvents();	
	return 0;
}

int GraphicsEngine::draw(aie::ShaderProgram* shader)
{
	if (!m_window) return -5;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->bind();

	shader->bindUniform("projectionViewModel", m_world->getProjectionView());

	m_world->draw(shader);

	glfwSwapBuffers(m_window);

	return 0;
}

int GraphicsEngine::end()
{
	if (!m_window) return -6;

	m_world->end();

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
