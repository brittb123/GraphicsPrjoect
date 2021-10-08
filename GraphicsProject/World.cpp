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
	//m_camera.setTransform(glm::lookAt
	//(
	//	glm::vec3(1.0f, 1.0f, 1.0f),
	//	glm::vec3(0.0f),
	//	glm::vec3(0.0f, 1.0f, 0.0f)
	//));
	m_camera.setPosition(glm::vec3(1.0f, 1.0f, 1.0f));
	m_camera.setYaw(-135.0f);
	m_camera.setPitch(-35.0f);

	m_projectionMatrix = glm::perspective
	(
		m_camera.getFieldOfView() * glm::pi<float>() / 180.0f,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
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
	return m_projectionMatrix * m_camera.getViewMatrix() * m_quad.getTransform();
}
