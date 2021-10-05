#pragma once
#include "Quad.h"
#include "glm/mat4x4.hpp"
#include "Camera.h"
class World
{
public:
	World(int width, int height);
	~World() {}

	void start();
	void update();
	void draw();
	void end();

	glm::mat4 getProjectionViewModel();

private:
	int m_width = 1280, m_height = 720;
	Quad m_quad = Quad(glm::vec4(0.4f, 0.8f, 0.6f, 1.0f));
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1);
};

