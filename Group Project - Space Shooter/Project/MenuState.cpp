#include "MenuState.h"
#include "Button.h"
#include "Camera.h"
#include "Texture.h"
#include "StateMachine.h"

MenuState::MenuState() 
{
	m_PlayButton = nullptr;
	m_QuitButton = nullptr;
	m_Font = nullptr;
	m_PlyShip = nullptr;
	m_RockLarge = nullptr;
	m_RockMed = nullptr;
}


MenuState::~MenuState()
{
	if (m_PlayButton)
	{
		m_PlayButton;
		m_PlayButton = nullptr;
	}
	if (m_QuitButton)
	{
		delete m_QuitButton;
		m_QuitButton = nullptr;
	}
	if (m_Font)
	{
		delete m_Font;
		m_Font = nullptr;
	}
	if (m_PlyShip)
	{
		delete m_PlyShip;
		m_PlyShip = nullptr;
	}
	if (m_RockLarge)
	{
		delete m_RockLarge;
		m_RockLarge = nullptr;
	}
	if (m_RockMed)
	{
		delete m_RockMed;
		m_RockMed = nullptr;
	}
}

void MenuState::Enter() 
{
	int windowWidth = Camera::Instance()->GetWindowWidth();
	int windowHeight = Camera::Instance()->GetWindowHeight();

	m_PlayButton = new Button("Play", windowWidth / 3.0f, windowHeight / 3.0f, 255, 85, 0, 255, 0, 255);
	m_QuitButton = new Button("Quit", windowWidth / 1.5f, windowHeight / 3.0f, 255, 85, 100, 255, 0, 255);
	m_Font = new Font("./Fonts/hobo_32px.fnt");
	m_PlyShip = new Texture("./Images/player.png");
	m_RockLarge = new Texture("./Images/rock_large.png");
	m_RockMed = new Texture("./Images/rock_medium.png");
	m_Menu = new Texture("./Images/Menu.png");
}

void MenuState::Update(float deltaTime, StateMachine* p_StateMachine) 
{
	m_pStateMachine = p_StateMachine;

	if (m_QuitButton->Update())
		m_pStateMachine->ChangeState(ESTATE_GAMEOVER);

	if (m_PlayButton->Update())
		m_pStateMachine->ChangeState(ESTATE_GAME);
}

void MenuState::Draw(RenderManager* pRenderManager)
{
	// Background
	pRenderManager->SetRenderColor(155, 155, 155, 200);
	pRenderManager->DrawSprite(m_Menu, Camera::Instance()->GetWindowWidth() / 2.0f, Camera::Instance()->GetWindowHeight() / 2.0f, (float)Camera::Instance()->GetWindowWidth(), (float)Camera::Instance()->GetWindowHeight());
	pRenderManager->SetRenderColor(230, 51, 51, 255);
	pRenderManager->DrawText(m_Font, "Asteroids.io!", Camera::Instance()->GetWindowWidth() / 3.1f, Camera::Instance()->GetWindowHeight() / 1.2f);

	// Button Background
	pRenderManager->SetRenderColor(0, 0, 0, 255);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 3.0f, Camera::Instance()->GetWindowHeight() / 3.0f, 350, 100);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 1.5f, Camera::Instance()->GetWindowHeight() / 3.0f, 350, 100);

	// Images
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(m_PlyShip, Camera::Instance()->GetWindowWidth() / 2.0f, Camera::Instance()->GetWindowHeight() / 2.0f, 100, 100);
	m_PlayButton->Draw(pRenderManager);
	m_QuitButton->Draw(pRenderManager);
}

void MenuState::Exit()
{
	if (m_PlayButton)
	{
		m_PlayButton;
		m_PlayButton = nullptr;
	}
	if (m_QuitButton)
	{
		delete m_QuitButton;
		m_QuitButton = nullptr;
	}
	if (m_Font)
	{
		delete m_Font;
		m_Font = nullptr;
	}
	if (m_PlyShip)
	{
		delete m_PlyShip;
		m_PlyShip = nullptr;
	}
	if (m_RockLarge)
	{
		delete m_RockLarge;
		m_RockLarge = nullptr;
	}
	if (m_RockMed)
	{
		delete m_RockMed;
		m_RockMed = nullptr;
	}
}
