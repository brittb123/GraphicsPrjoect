#pragma once
#include "glm/mat4x4.hpp"

class Entity
{
public:
	Entity() {}
	~Entity() {}

	void start();
	void update();
	void draw();
	void end();

private:
	glm::mat4 m_transform;

};

