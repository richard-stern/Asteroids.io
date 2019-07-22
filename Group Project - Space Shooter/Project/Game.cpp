#include "Game.h"
#include "RenderManager.h"
#include "StateMachine.h"

Game::Game(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_pStateMachine = new StateMachine();
}

Game::~Game()
{
	delete m_pStateMachine;
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

	//End the render pass.
	pRenderManager->End();
}