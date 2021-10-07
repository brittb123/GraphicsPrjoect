#include "Transform.h"
#include "glm/ext.hpp"

void Transform::setScale(glm::vec3 Scale)
{
}

glm::mat4 Transform::getMatrix()
{	
	glm::mat4 matrix = m_matrix;

	if (m_shouldUpdateMatrix)
	{
		glm::mat4 matrix = glm::mat4(1.0f);
		matrix = glm::translate(matrix, m_position);
		matrix = glm::rotate(matrix, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		matrix = glm::rotate(matrix, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		matrix = glm::rotate(matrix, m_rotation.z, glm::vec3(1.0f, 0.0f, 1.0f));
		matrix = glm::scale(matrix, m_scale);
		m_matrix = matrix;
		m_shouldUpdateMatrix = false;
	}
	return matrix;
}
