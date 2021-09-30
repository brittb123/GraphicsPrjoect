#pragma once
#include "Shader.h"
#include "glm/mat4x4.hpp"
#include "World.h"
struct GLFWwindow;

class GraphicsEngine
{
public:
	GraphicsEngine(int width, int height, const char* title);
	GraphicsEngine();
	~GraphicsEngine();

	int run();

private:
	int start();
	int update();
	int draw();
	int end();

	bool getGameOver();

private:
	GLFWwindow* m_window = nullptr;
	int m_width, m_height;
	const char* m_title;

	aie::ShaderProgram m_shader;

	World* m_world;
};

