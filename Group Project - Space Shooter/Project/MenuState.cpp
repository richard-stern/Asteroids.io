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
	delete m_PlayButton;
	delete m_QuitButton;
	delete m_Font;
	delete m_PlyShip;
	delete m_RockLarge;
	delete m_RockMed;
}

void MenuState::Enter() 
{
	m_PlayButton = new Button("Play", Camera::Instance()->GetWindowWidth() / 3.0f, Camera::Instance()->GetWindowHeight() / 3.0f, 335, 85, 0, 255, 0, 255);
	m_QuitButton = new Button("Quit", Camera::Instance()->GetWindowWidth() / 1.5f, Camera::Instance()->GetWindowHeight() / 3.0f, 335, 85, 255, 0, 0, 255);
	m_Font = new Font("./Fonts/hobo_32px.fnt");
	m_PlyShip = new Texture("./Images/player.png");
	m_RockLarge = new Texture("./Images/rock_large.png");
	m_RockMed = new Texture("./Images/rock_medium.png");
}

void MenuState::Update(float deltaTime, StateMachine* p_StateMachine) 
{
	m_pStateMachine = p_StateMachine;

	//if (m_QuitButton->Update())
	//	m_App->Quit();

	if (m_PlayButton->Update())
		m_pStateMachine->ChangeState(ESTATE_GAME);
}

void MenuState::Draw(RenderManager* pRenderManager)
{
	// Background
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 2.0f, Camera::Instance()->GetWindowHeight() / 2.0f, (float)Camera::Instance()->GetWindowWidth(), (float)Camera::Instance()->GetWindowHeight());
	pRenderManager->SetRenderColor(230, 51, 51, 255);
	pRenderManager->DrawText(m_Font, "Asteroids.io!", Camera::Instance()->GetWindowWidth() / 3.1f, Camera::Instance()->GetWindowHeight() / 1.2f);

	// Button Background
	pRenderManager->SetRenderColor(0, 0, 0, 255);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 3.0f, Camera::Instance()->GetWindowHeight() / 3.0f, 350, 100);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 1.5f, Camera::Instance()->GetWindowHeight() / 3.0f, 350, 100);

	// Images
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(m_PlyShip, Camera::Instance()->GetWindowWidth() / 2.0f, Camera::Instance()->GetWindowHeight() / 5.0f, 100, 100);
	pRenderManager->DrawSprite(m_RockLarge, Camera::Instance()->GetWindowWidth() / 3.0f, Camera::Instance()->GetWindowHeight() / 1.0f, 250, 250);
	pRenderManager->DrawSprite(m_RockMed, Camera::Instance()->GetWindowWidth() / 4.0f, Camera::Instance()->GetWindowHeight() / 6.0f, 150, 150);
}

void MenuState::Exit() 
{
	delete m_PlayButton;
	delete m_QuitButton;
	delete m_Font;
	delete m_PlyShip;
	delete m_RockLarge;
	delete m_RockMed;
}
