// created : 22/07/2019
// Leanne Vorster
#include "GameOverState.h"
#include <iostream>


GameOverState::GameOverState() : BaseState()
{
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
}
void GameOverState ::Exit ()
{
	std::cout << "exit game over state" << std::endl;
}