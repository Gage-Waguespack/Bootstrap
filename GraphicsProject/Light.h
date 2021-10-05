#pragma once
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

class Light
{
public:
	Light() {}
	Light(glm::vec3 direction, glm::vec4 color)
		: m_direction{ direction }, m_color{ color } {}
	~Light() {}

	glm::vec3 getDirection() { return m_direction; }
	void setDirection(glm::vec3 direction) { m_direction = direction; }
	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:
	glm::vec3 m_direction = glm::vec3(0.0f);
	glm::vec4 m_color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
};

