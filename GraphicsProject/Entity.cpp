#include "Entity.h"

Entity::Entity(glm::mat4 transform)
{
	m_transform = transform;
}

Entity::~Entity()
{
}

void Entity::start()
{


	//Generate the vertices
	Vertex* vertices{};
	int vertexCount;
	//generateVertices(vertices, vertexCount);

	vertexCount = 6;
	//Define the vertices for a quad
	vertices = new Vertex[vertexCount];

	//triangle 0
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	//triangle 1
	vertices[3].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[4].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[5].position = { 0.5f, 0.0f, -0.5f, 1.0f };

	//Fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,	//type of buffer
		sizeof(Vertex) * 6, //size in bytes of all vertices
		vertices,			//all vertices
		GL_STATIC_DRAW		//how the data will update
	);

	//Deallocate vertices
	delete[] vertices;
}

void Entity::update()
{

}

void Entity::draw()
{

}

void Entity::end()
{

}

glm::mat4 Entity::getTransform()
{
	return glm::mat4();
}

void Entity::setTransform(glm::mat4 newTransform)
{
	m_transform = newTransform;
}
