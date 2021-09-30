#pragma once
#include "Mesh.h"

class Entity
{
public:
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};

public:
	Entity() {}
	Entity(glm::mat4 transform);
	~Entity();

	void start();
	void update();
	void draw();
	void end();

	glm::mat4 getTransform();
	void setTransform(glm::mat4 newTransform);

private:
	glm::mat4 m_transform = glm::mat4(0);
};

