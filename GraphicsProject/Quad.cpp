#include "Quad.h"

Quad::Quad(glm::vec4 color) : Quad::Quad()
{
	m_color = color;
}

Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 6;
	triCount = 2;

	// Defines the vertices for a quad
	vertices = new Vertex[vertexCount];

	// Triangle 0
	vertices[0].position = { -0.5, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5, 0.0f, 0.5, 1.0f };
	vertices[2].position = { -0.5, 0.0f, -0.5, 1.0f };

	// Triangle 1
	vertices[3].position = { 0.5, 0.0f, 0.5, 1.0f };
	vertices[4].position = { -0.5, 0.0f,-0.5, 1.0f };
	vertices[5].position = { 0.5, 0.0f, -0.5, 1.0f };



	// Triangle 0
	vertices[0].TexCoord = { 0.0, 1.0f, };
	vertices[1].TexCoord = { 1.0f, 1.0f };
	vertices[2].TexCoord = { 0.0f, 0.0f};

	// Triangle 1
	vertices[3].TexCoord = { 1.0f, 1.0f };
	vertices[4].TexCoord = { 0.0f, 0.0f };
	vertices[5].TexCoord = { 1.0f, 0.0f };


	for (int i = 0; i < vertexCount; i++)
	{
		vertices[i].color = m_color;
	}

	return vertices;
}
