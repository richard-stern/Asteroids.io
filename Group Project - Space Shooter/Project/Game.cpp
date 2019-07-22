#include "Game.h"
#include "RenderManager.h"
#include "StateMachine.h"
#include "CollisionManager.h"
#include "GUI.h"

Game::Game(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_pStateMachine = new StateMachine();

	// Create the collision manager.
	CollisionManager::Create();
}

Game::~Game()
{
	delete m_pStateMachine;

	// Delete the collision manager.
	CollisionManager::Destroy();
}

void Game::Update(float deltaTime)
{
	m_pStateMachine->Update(deltaTime);
}

void Game::Draw()
{
	RenderManager* pRenderManager = RenderManager::Instance();

	// clear the back buffer
	ClearScreen();
	
	//Begin the render pass.
	pRenderManager->Begin();

	//Render everything.
	m_pStateMachine->Draw();





	// Displays FPS
	GUI::Instance()->DisplayFPS(pRenderManager);

	//End the render pass.
	pRenderManager->End();
}