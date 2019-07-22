// created : 22/07/2019
// Leanne Vorster
#include "GameOverState.h"
#include <iostream>
#include "Button.h"
#include "GUI.h"

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
	char endScoreText[32];
	int totalscore = GUI::Instance->GetScore();
	sprintf(endScoreText,   "your score is %i", totalscore);
	pRenderManager->DrawText(m_font, 0, 400, 500);
	//play again button
	pRenderManager->DrawText(m_font, "play again?", 400, 500);

}
void GameOverState ::Exit ()
{
	std::cout << "exit game over state" << std::endl;
}