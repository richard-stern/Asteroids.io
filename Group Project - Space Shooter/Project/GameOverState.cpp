// created : 22/07/2019
// Leanne Vorster
#include "GameOverState.h"
#include <iostream>
#include "Button.h"

GameOverState::GameOverState() : BaseState()
{
	m_font = new Font("./font/consalas.ttf");
}
GameOverState::~GameOverState()
{
	// clean up the project
}
void GameOverState ::Enter()
{
	std::cout << "enter game over state" << std::endl;
}
void GameOverState ::Update(float deltaTime, StateMachine* p_StateMachine)
{
	std::cout << "update game over state" << std::endl;
}
void GameOverState ::Draw (RenderManager* pRenderManager)
{
	std::cout << "draw game over state" << std::endl;
	// score
	pRenderManager->DrawText(m_font, "play again?", 400, 500);

}
void GameOverState ::Exit ()
{
	std::cout << "exit game over state" << std::endl;
}