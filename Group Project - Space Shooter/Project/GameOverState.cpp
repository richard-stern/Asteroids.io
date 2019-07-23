// created : 22/07/2019
// Leanne Vorster
#include "GameOverState.h"
#include <iostream>
#include "GUI.h"

GameOverState::GameOverState() : BaseState()
{
	m_font = new Font("./Fonts/hobo_32px.fnt");
	
}
GameOverState::~GameOverState()
{
	// clean up the project
	delete m_font;

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
	int totalscore = GUI::Instance()->GetScore();
	sprintf_s(endScoreText,  "your score is %i", totalscore);
	pRenderManager->DrawText(m_font, 0, 400, 500);
	//play again button
	pRenderManager->DrawText(m_font, "play again?", 400, 500);
	// quit button
	pRenderManager->DrawText(m_font, "Quit", 400, 600);
}
void GameOverState ::Exit ()
{
	std::cout << "exit game over state" << std::endl;
	delete m_font;
	m_font = nullptr;
}