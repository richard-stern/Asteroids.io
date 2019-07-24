#include "Game.h"
#include "RenderManager.h"
#include "StateMachine.h"
#include "CollisionManager.h"
#include "GUI.h"
#include "Camera.h"
#include "TextureManager.h"
#include "Blackboard.h"
Game::Game(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	// Create the collision manager.
	CollisionManager::Create();
	Camera::Create(windowWidth, windowHeight);
	TextureManager::Create();
	m_pStateMachine = new StateMachine();

	//Create the Blackboard for game use
	Blackboard::Create();

}

Game::~Game()
{
	delete m_pStateMachine;
	TextureManager::Destroy();
	Camera::Destroy();
	// Delete the collision manager.
	CollisionManager::Destroy();

	//Delete the Blackboard
	Blackboard::Destroy();
}

void Game::Update(float deltaTime)
{
	//Moved to gameState
	//CollisionManager::GetInstance()->Update(deltaTime);
	if (m_pStateMachine->Update(deltaTime))
		Quit();
	//Update the Collision Manager
}

void Game::Draw()
{
	RenderManager* pRenderManager = RenderManager::Instance();

	// clear the back buffer
	ClearScreen();
	
	//Begin the render pass.
	pRenderManager->Begin();

	//Render everything.
	m_pStateMachine->Draw(pRenderManager);

	// Displays FPS
	//GUI::Instance()->DisplayFPS(pRenderManager);

	//End the render pass.
	pRenderManager->End();
}