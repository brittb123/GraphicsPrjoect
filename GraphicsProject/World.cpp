#include "World.h"
#include "glm/ext.hpp"
#include "GLFW/glfw3.h"

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

	// Initializes the light
	m_light.setDirection(glm::vec3(-1.0f));
	m_light.setAmbient(glm::vec4(0.6f, 0.6f, 0.0f, 1.0f));
	m_light.setDiffuse(glm::vec4(0.8f, 0.6f, 1.0f, 1.0f));
	m_light.setSpecular(glm::vec4(1.0f));
	m_light.setSpecularPower(2.0f);
	
	// Creates camera transform
	Transform cameraTransform = m_camera.getTransform();
	cameraTransform.setPosition(glm::vec3(1.0f));
	cameraTransform.setRotation(glm::vec3(-45.0f, 45.0f, 0.0f));
	/*m_camera.setTransform(glm::lookAt
	(
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	));*/

	m_projectionMatrix = glm::perspective
	(
		m_camera.getFieldOfView() * glm::pi<float>() / 180.0f,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
	);

}

void World::update(double deltaTime)
{
	int keyForward = GLFW_KEY_W;
	int keyBack = GLFW_KEY_S;
	int keyLeft = GLFW_KEY_A;
	int keyRight = GLFW_KEY_D;
	int keyUp = GLFW_KEY_E;
	int keyDown = GLFW_KEY_Q;

	float cameraSpeed = 1.0f;
	double cameraSensitivity = 0.5f;

	Transform cameraTransform = m_camera.getTransform();

	// Get current mouse conditions
	glfwGetCursorPos(m_window, &m_currentMouseX, &m_currentMouseY);

	// Rotate camera using change in mouse position
	double deltaMouseX = m_currentMouseX - m_previousMouseX;
	double deltaMouseY = m_currentMouseY - m_previousMouseY;

	if (deltaMouseX != 0.0 && deltaMouseY != 0.0) 
	{
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.rotate(glm::vec3(deltaMouseY, deltaMouseY, 0.0f) * (float)(deltaTime * cameraSensitivity));
		m_camera.setTransform(cameraTransform);
	}
	
	//Store previouse mouse coordinates
	m_previousMouseX = m_currentMouseX;
	m_previousMouseY = m_currentMouseY;

	// Calculate the camera's forward vector
	glm::vec3 cameraForward = glm::vec3(0.0f, 0.0f, 1.0f);

	// Calculate the camera's right vector
	glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);

	// Calculate the camera's up vector
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);



	// Get Input 
	if (glfwGetKey(m_window, keyForward)) 
	{
		// Move Forawrd
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(cameraForward * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}

	if (glfwGetKey(m_window, keyBack))
	{
		// Move Back
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(-cameraForward * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyRight))
	{
		// Move Right
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(cameraRight * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}

	if (glfwGetKey(m_window, keyLeft))
	{
		// Move Left
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(-cameraRight * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}

	if (glfwGetKey(m_window, keyUp))
	{
		// Move Up
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(cameraUp * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}

	if (glfwGetKey(m_window, keyDown))
	{
		// Move Down
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(-cameraUp * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}


}

void World::draw(aie::ShaderProgram* shader)
{
	shader->bindUniform("lightDirection", m_light.getDirection());
	shader->bindUniform("lightAmbient", m_light.getAmbient());
	shader->bindUniform("lightDiffuse", m_light.getDiffuse());
	shader->bindUniform("lightSpecular", m_light.getSpecular());
	shader->bindUniform("cameraPosition", m_camera.getTransform().getPosition());
	shader->bindUniform("specularPower", m_light.getSpecularPower());
	m_quad.draw(shader);
}

void World::end()
{
}

glm::mat4 World::getProjectionView()
{
	return m_projectionMatrix * m_camera.getTransform().getMatrix();
}
