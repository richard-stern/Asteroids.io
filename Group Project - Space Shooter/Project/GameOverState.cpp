// created : 22/07/2019
// Leanne Vorster
#include "GameOverState.h"
#include <iostream>
#include "GUI.h"
#include "Camera.h"
#include "StateMachine.h"
#include "Application.h"
GameOverState::GameOverState() : BaseState()
{
	m_font = new Font("./Fonts/hobo_32px.fnt");
	m_ExitButtuon = nullptr;
	m_PlayAgianButton = nullptr;
}
GameOverState::~GameOverState()
{
	// clean up the project
	delete m_font;
	delete m_PlayAgianButton;
	delete m_ExitButtuon;

}
void GameOverState ::Enter()
{
	std::cout << "enter game over state" << std::endl;
	int windowWidth = Camera::Instance()->GetWindowWidth();
	int windowHeight = Camera::Instance()->GetWindowHeight();

	m_PlayAgianButton = new Button("Play again?", windowWidth / 3.0f, windowHeight / 3.0f, 255, 85, 0, 255, 0, 255);
	m_ExitButtuon = new Button("Exit", windowWidth / 5.0f, windowHeight / 5.0f, 255, 85, 0, 255, 0, 255);

}
bool GameOverState ::Update(float deltaTime, StateMachine* p_StateMachine)
{
	std::cout << "update game over state" << std::endl;
	m_pStateMachine = p_StateMachine;
	if (m_PlayAgianButton->Update())
	{
		m_pStateMachine->ChangeState(ESTATE_GAME);
	}
	 else if (m_ExitButtuon->Update())
	{
		std::cout << "QUIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
		&Application::Quit; 
		return true;
	}
	 else
	return false;
}
void GameOverState ::Draw (RenderManager* pRenderManager)
{
	std::cout << "draw game over state" << std::endl;

	// score
	char endScoreText[32];
	int totalscore = GUI::Instance()->GetScore();
	sprintf_s(endScoreText,  "your score is %i", totalscore);
	//pRenderManager->DrawText(m_font, 0, 400, 500);

	//play again button
	//pRenderManager->DrawText(m_font, "play again?", 400, 500);
	m_PlayAgianButton->Draw(pRenderManager);
	
	// quit button
	//pRenderManager->DrawText(m_font, "Quit", 400, 600);
	m_ExitButtuon->Draw(pRenderManager);

}
void GameOverState ::Exit ()
{
	std::cout << "exit game over state" << std::endl;
	delete m_font;
	m_font = nullptr;

	delete m_PlayAgianButton;
	m_PlayAgianButton = nullptr;

	delete m_ExitButtuon;
	m_ExitButtuon = nullptr;
}