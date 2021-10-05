#pragma once
#include "gl_core_4_4.h"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "Shader.h"
class Mesh
{
public: 
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
		glm::vec4 normal;
	};


public:
	Mesh();
	~Mesh();

	void draw(aie::ShaderProgram* shader);
	void start();

	virtual Vertex* generateVertices(unsigned int& vertexCount, unsigned int& triCount) = 0;
	
	glm::mat4 getTransform() { return m_transform; }
	void setTransfrom(glm::mat4 Transform) { m_transform = Transform; }
private:
	glm::mat4 m_transform;
	unsigned int m_tricount;
	unsigned int m_vertexArrayObject, m_vertexBufferObject, m_indexBufferObject;
};

