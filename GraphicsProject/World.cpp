#include "World.h"
#include "glm/ext.hpp"


World::World(int width, int height)
{
	m_width = width;
	m_height = height;
}
void World::start()
{
	// Initialize the quad
	m_quad.setTransfrom(glm::mat4(10.0f));
	m_quad.start();
	
	// Creayes camera transform
	m_viewMatrix = glm::lookAt
	(
		glm::vec3(10.0f, 10.0f, 10.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
	m_projectionMatrix = glm::perspective
	(
		glm::pi<float>() / 4.0f,
		(float)m_width / (float)m_height,
		0.001f,
		1000.0f
	);

}

void World::update()
{
}

void World::draw()
{
	m_quad.draw();
}

void World::end()
{
}

glm::mat4 World::getProjectionViewModel()
{
	return m_projectionMatrix * m_viewMatrix * m_quad.getTransform();
}
