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
	m_RockSmall = nullptr;
	m_Enemy = nullptr;
	m_Bullet = nullptr;
	m_Menu = nullptr;
	m_fWindowWidth = (float)Camera::Instance()->GetWindowWidth();
	m_fWindowHeight = (float)Camera::Instance()->GetWindowHeight();
}


MenuState::~MenuState()
{
	if (m_PlayButton)
	{
		delete m_PlayButton;
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
	if (m_RockSmall)
	{
		delete m_RockSmall;
		m_RockSmall = nullptr;
	}
	if (m_Enemy)
	{
		delete m_Enemy;
		m_Enemy = nullptr;
	}
	if (m_Bullet)
	{
		delete m_Bullet;
		m_Bullet = nullptr;
	}
	if (m_Menu)
	{
		delete m_Menu;
		m_Menu = nullptr;
	}
}

void MenuState::Enter() 
{
	m_PlayButton = new Button("Play", m_fWindowWidth / 3.0f, m_fWindowHeight / 2.0f, 255, 85, 0, 255, 0, 255);
	m_QuitButton = new Button("Quit", m_fWindowWidth / 1.5f, m_fWindowHeight / 2.0f, 255, 85, 100, 255, 0, 255);
	m_Font = new Font("./Fonts/hobo_32px.fnt");
	m_PlyShip = new Texture("./Images/player.png");
	m_RockLarge = new Texture("./Images/rock_large.png");
	m_RockMed = new Texture("./Images/rock_medium.png");
	m_RockSmall = new Texture("./Images/rock_small.png");
	m_Enemy = new Texture("./Images/Enemy.png");
	m_Bullet = new Texture("./Images/Bullet.png");
	m_Menu = new Texture("./Images/Menu.png");
}

bool MenuState::Update(float deltaTime, StateMachine* p_StateMachine)
{
	m_pStateMachine = p_StateMachine;


	if (m_PlayButton->Update())
	{
		m_pStateMachine->ChangeState(ESTATE_GAME);
		return false;
	}
	else if (m_QuitButton->Update())
		return true;
	else
		return false;

}

void MenuState::Draw(RenderManager* pRenderManager)
{
	// Background
	pRenderManager->SetRenderColor(255, 255, 255, 200);
	pRenderManager->DrawSprite(m_Menu, m_fWindowWidth / 2.0f, m_fWindowHeight / 2.0f, m_fWindowWidth, m_fWindowHeight);
	pRenderManager->SetRenderColor(230, 51, 51, 255);

	// Button Background
	//pRenderManager->SetRenderColor(0, 0, 0, 255);
	//pRenderManager->DrawSprite(NULL, m_fWindowWidth / 3.0f, m_fWindowHeight / 3.0f, 350, 100);
	//pRenderManager->DrawSprite(NULL, m_fWindowWidth / 1.5f, m_fWindowHeight / 3.0f, 350, 100);

	// Images
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(m_PlyShip, m_fWindowWidth / 2.0f, m_fWindowHeight / 3.0f, 100, 100, 0.75f);
	pRenderManager->DrawSprite(m_Bullet, m_fWindowWidth / 2.4f, m_fWindowHeight / 2.6f, 40, 40, 0.75f);
	pRenderManager->DrawSprite(m_RockLarge, m_fWindowWidth / 3.0f, m_fWindowHeight / 1.6f, 200, 200);
	pRenderManager->DrawSprite(m_RockMed, m_fWindowWidth / 4.0f, m_fWindowHeight / 4.0f, 150, 150);
	pRenderManager->DrawSprite(m_RockSmall, m_fWindowWidth / 1.3f, m_fWindowHeight / 5.2f, 100, 100);
	pRenderManager->DrawSprite(m_Enemy, m_fWindowWidth / 1.4f, m_fWindowHeight / 1.5f, 100, 100, -0.5f);

	m_PlayButton->Draw(pRenderManager);
	m_QuitButton->Draw(pRenderManager);
}

void MenuState::Exit()
{
	if (m_PlayButton)
	{
		delete m_PlayButton;
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
	if (m_RockSmall)
	{
		delete m_RockSmall;
		m_RockSmall = nullptr;
	}
	if (m_Enemy)
	{
		delete m_Enemy;
		m_Enemy = nullptr;
	}
	if (m_Bullet)
	{
		delete m_Bullet;
		m_Bullet = nullptr;
	}
	if (m_Menu)
	{
		delete m_Menu;
		m_Menu = nullptr;
	}
}
