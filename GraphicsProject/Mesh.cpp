#include "Mesh.h"

Mesh::Mesh()
{
	m_transform = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	m_tricount = 0;
	m_vertexArrayObject = 0;
	m_vertexBufferObject = 0;
	m_indexBufferObject = 0;

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	glDeleteBuffers(1, &m_vertexBufferObject);
	glDeleteBuffers(1, &m_indexBufferObject);
}

void Mesh::start()
{

	assert(m_vertexArrayObject == 0);

	// Generate Buffers
	glGenBuffers(1, &m_vertexBufferObject);
	glGenVertexArrays(1, &m_vertexArrayObject);

	// Binds the vertex array
	glBindVertexArray(m_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

	// Defines the vertices for a quad
	Vertex vertices[6];

	// Triangle 0
	vertices[0].position = { -0.5, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5, 0.0f, 0.5, 1.0f };
	vertices[2].position = { -0.5, 0.0f, -0.5, 1.0f };

	// Triangle 1
	vertices[3].position = { 0.5, 0.0f, 0.5, 1.0f };
	vertices[4].position = { -0.5, 0.0f,-0.5, 1.0f };
	vertices[5].position = { 0.5, 0.0f, -0.5, 1.0f };

	// Fill vertex buffer
	glBufferData
	(
		GL_ARRAY_BUFFER,    // The Type of buffer
		sizeof(Vertex) * 6, // The size in bytes of all vertices
		vertices,			// All vertices
		GL_STATIC_DRAW		// How the data will be updated
	);

	// Enable vertex position as first attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer
	(
		0,					// The attribute index
		4,					// Number of values in attribute
		GL_FLOAT,			// Type of each value
		GL_FALSE,			// Whether to normalize
		sizeof(Vertex),     // Size in bytes of one vertex
		0					// Memory position of the attribute
	);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::draw()
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
