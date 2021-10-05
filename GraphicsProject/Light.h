#pragma once
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

class Light
{
public:
	Light() {}
	Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
		: m_direction{ direction }, m_ambient{ ambient }, m_diffuse{ diffuse }, m_specular{ specular } {}
	~Light() {}

	glm::vec3 getDirection() { return m_direction; }
	void setDirection(glm::vec3 direction) { m_direction = direction; }

	glm::vec4 getAmbient() { return m_ambient; }
	void setAmbient(glm::vec4 ambient) { m_ambient = ambient; }

	glm::vec4 getDiffuse() { return m_diffuse; }
	void setDiffuse(glm::vec4 diffuse) { m_diffuse = diffuse; }

	glm::vec4 getSpecular() { return m_specular; }
	void setSpecular(glm::vec4 specular) { m_specular = specular; }

private:
	glm::vec3 m_direction = glm::vec3(0.0f);
	glm::vec4 m_ambient = glm::vec4(0.0f);
	glm::vec4 m_diffuse = glm::vec4(1.0f);
	glm::vec4 m_specular = glm::vec4(1.0f);
};

