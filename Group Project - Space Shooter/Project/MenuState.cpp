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
	m_Menu = nullptr;
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
	if (m_Menu)
	{
		delete m_Menu;
		m_Menu = nullptr;
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

bool MenuState::Update(float deltaTime, StateMachine* p_StateMachine)
{
	m_pStateMachine = p_StateMachine;


	if (m_PlayButton->Update())
		m_pStateMachine->ChangeState(ESTATE_GAME);
	if (m_QuitButton->Update())
		return true;
	else if (MenuState::Update(deltaTime, m_pStateMachine))
		return false;

}

void MenuState::Draw(RenderManager* pRenderManager)
{
	// Background
	pRenderManager->SetRenderColor(255, 255, 255, 200);
	pRenderManager->DrawSprite(m_Menu, Camera::Instance()->GetWindowWidth() / 2.0f, Camera::Instance()->GetWindowHeight() / 2.0f, (float)Camera::Instance()->GetWindowWidth(), (float)Camera::Instance()->GetWindowHeight());
	pRenderManager->SetRenderColor(230, 51, 51, 255);

	// Button Background
	pRenderManager->SetRenderColor(0, 0, 0, 255);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 3.0f, Camera::Instance()->GetWindowHeight() / 3.0f, 350, 100);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 1.5f, Camera::Instance()->GetWindowHeight() / 3.0f, 350, 100);

	// Images
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(m_PlyShip, Camera::Instance()->GetWindowWidth() / 2.0f, Camera::Instance()->GetWindowHeight() / 5.0f, 100, 100);
	pRenderManager->DrawSprite(m_RockLarge, Camera::Instance()->GetWindowWidth() / 3.0f, Camera::Instance()->GetWindowHeight() / 1.0f, 250, 250);
	pRenderManager->DrawSprite(m_RockMed, Camera::Instance()->GetWindowWidth() / 4.0f, Camera::Instance()->GetWindowHeight() / 6.0f, 150, 150);
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
