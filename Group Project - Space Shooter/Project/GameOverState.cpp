// created : 22/07/2019
// Leanne Vorster
#include "GameOverState.h"
#include <iostream>
//#include "GUI.h"
#include "Camera.h"
#include "StateMachine.h"
#include "Application.h"
#include "Texture.h"
#include "Blackboard.h"
GameOverState::GameOverState() : BaseState()
{
	m_font = new Font("./Fonts/hobo_32px.fnt");
	m_ExitButton = nullptr;
	m_PlayAgainButton = nullptr;
	m_Richard = nullptr;
	m_fWindowWidth = (float)Camera::Instance()->GetWindowWidth();
	m_fWindowHeight = (float)Camera::Instance()->GetWindowHeight();

}
GameOverState::~GameOverState()
{
	// clean up the project
	delete m_font;
	delete m_PlayAgainButton;
	delete m_ExitButton;
	delete m_Richard;

}
void GameOverState::Enter()
{
	//std::cout << "enter game over state" << std::endl;
	int windowWidth = Camera::Instance()->GetWindowWidth();
	int windowHeight = Camera::Instance()->GetWindowHeight();

	m_PlayAgainButton = new Button("Play again?", windowWidth / 3.0f, windowHeight / 3.0f, 255, 85, 0, 255, 0, 255);
	m_ExitButton = new Button("Exit", windowWidth / 1.5f, windowHeight / 3.0f, 255, 85, 0, 255, 0, 255);
	m_Richard = new Texture("./Images/Richard.png");
}
bool GameOverState::Update(float deltaTime, StateMachine* p_StateMachine)
{
	// dont think this right
	Camera::Instance()->SetPosition(0.0f, 0.0f);

	//std::cout << "update game over state" << std::endl;
	m_pStateMachine = p_StateMachine;
	if (m_PlayAgainButton->Update())
	{
		m_pStateMachine->ChangeState(ESTATE_GAME);
		return false;
	}
	else if (m_ExitButton->Update())
	{
		std::cout << "QUIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

		return true;
	}
	else
		return false;

}
void GameOverState::Draw(RenderManager* pRenderManager)
{
	//std::cout << "draw game over state" << std::endl;

	// score
	char endScoreText[32];
	int totalscore = Blackboard::Instance()->GetScore();
	sprintf_s(endScoreText, "your score is %i", totalscore);
	pRenderManager->DrawText(m_font, endScoreText, 400, 500);


	//play again button
	//pRenderManager->DrawText(m_font, "play again?", 400, 500);
	m_PlayAgainButton->Draw(pRenderManager);

	// quit button
	//pRenderManager->DrawText(m_font, "Quit", 400, 600);
	m_ExitButton->Draw(pRenderManager);
	////richard
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(m_Richard, m_fWindowWidth / 2.0f, m_fWindowHeight / 2.0f, 100, 100, 0.0f);
}
void GameOverState::Exit()
{
	//std::cout << "exit game over state" << std::endl;
	delete m_font;
	m_font = nullptr;

	delete m_PlayAgainButton;
	m_PlayAgainButton = nullptr;

	delete m_ExitButton;
	m_ExitButton = nullptr;

	delete m_Richard;
	m_Richard = nullptr;
}