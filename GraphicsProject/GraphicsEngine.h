#pragma once
#include "Shader.h"
#include "Mesh.h"
#include "glm/mat4x4.hpp"

struct GLFWwindow;

class GraphicsEngine
{
public:
	GraphicsEngine(int width, int height, const char* title);
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
	Mesh m_quad;
	
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;
};

