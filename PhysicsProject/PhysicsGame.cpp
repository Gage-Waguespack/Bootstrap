#include "PhysicsGame.h"
#include "Sphere.h"
#include "Plane.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include <glm/ext.hpp>

bool PhysicsGame::startup()
{
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_renderer = new aie::Renderer2D();
	setBackgroundColour(0.2f, 0.01f, 0.2f, 0.1f);

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	
	m_scene = new PhysicsScene();
	m_scene->setTimeStep(0.01f);
	m_scene->setGravity({ 0.0f, 0.0f });

	Sphere* cueBall = new Sphere(glm::vec2(-40.0f, 0.0f), glm::vec2(), 6, 2, glm::vec4(0.2f, 0.9f, 0.8f, 1.0f));
	m_scene->addActor(cueBall);
	cueBall->applyForce(glm::vec2(80.0f, 0.0f));

	Sphere* ball1 = new Sphere(glm::vec2(20.0f, 0.0f), glm::vec2(), 5.5f, 2, glm::vec4(0.9f, 0.3f, 0.5f, 1.0f));
	m_scene->addActor(ball1);
	Sphere* ball2 = new Sphere(glm::vec2(24.0f, 2.4f), glm::vec2(), 5.5f, 2, glm::vec4(0.9f, 0.3f, 0.5f, 1.0f));
	m_scene->addActor(ball2);
	Sphere* ball3 = new Sphere(glm::vec2(24.0f, -2.4f), glm::vec2(), 5.5f, 2, glm::vec4(0.9f, 0.3f, 0.5f, 1.0f));
	m_scene->addActor(ball3);
	Sphere* ball4 = new Sphere(glm::vec2(28.0f, 4.5f), glm::vec2(), 5.5f, 2, glm::vec4(0.9f, 0.3f, 0.5f, 1.0f));
	m_scene->addActor(ball4);
	Sphere* ball5 = new Sphere(glm::vec2(28.0f, 0.0f), glm::vec2(), 5.5f, 2, glm::vec4(0.9f, 0.3f, 0.5f, 1.0f));
	m_scene->addActor(ball5);
	Sphere* ball6 = new Sphere(glm::vec2(28.0f, -4.5f), glm::vec2(), 5.5f, 2, glm::vec4(0.9f, 0.3f, 0.5f, 1.0f));
	m_scene->addActor(ball6);


	Plane* topWall = new Plane(glm::vec2(0.0f, -1.8f), -53.0f, glm::vec4(0.2f, 0.9f, 0.5f, 1.0f));
	m_scene->addActor(topWall);
	Plane* bottomWall = new Plane(glm::vec2(0.0f, 1.8f), -53.0f, glm::vec4(0.2f, 0.9f, 0.5f, 1.0f));
	m_scene->addActor(bottomWall);
	Plane* leftWall = new Plane(glm::vec2(1.0f, 0.0f), -96.0f, glm::vec4(0.2f, 0.9f, 0.5f, 1.0f));
	m_scene->addActor(leftWall);
	Plane* rightWall = new Plane(glm::vec2(-1.0f, 0.0f), -96.0f, glm::vec4(0.2f, 0.9f, 0.5f, 1.0f));
	m_scene->addActor(rightWall);

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_renderer;
	delete m_scene;
	delete m_font;
}

void PhysicsGame::update(float deltaTime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();
	
	m_scene->update(deltaTime);

	//Exit on Esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) 
	{
		quit();
	}
}

void PhysicsGame::draw()
{
	clearScreen();

	m_renderer->begin();

	//Draw the scene
	m_scene->draw();

	//Draw the Gizmos
	static float aspectRatio = 16.0f / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100,				//left
		100,				//right
		-100 / aspectRatio,	//bottom
		100 / aspectRatio,	//top
		-1.0f,				//zNear
		1.0f				//zFar
		));

	//Draw FPS
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_renderer->drawText(m_font, fps, 0.0f, 0.0f);

	m_renderer->end();
}
