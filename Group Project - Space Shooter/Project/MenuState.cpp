#include "MenuState.h"
#include "Button.h"
#include "Camera.h"

MenuState::MenuState() {
	m_PlayButton = nullptr;
	m_QuitButton = nullptr;
	m_Font = nullptr;
}


MenuState::~MenuState() {
	delete m_PlayButton;
	delete m_QuitButton;
	delete m_Font;
}

void MenuState::Enter() {
	m_PlayButton = new Button("Play", Camera::Instance()->GetWindowWidth() / 3, Camera::Instance()->GetWindowHeight() / 3, 335, 85, 0, 255, 0, 255);
	m_QuitButton = new Button("Quit", Camera::Instance()->GetWindowWidth() / 1.5f, Camera::Instance()->GetWindowHeight() / 3, 335, 85, 255, 0, 0, 255);
	m_Font = new Font("./Fonts/hobo_32px.fnt");
}

void MenuState::Update(float deltaTime, StateMachine* p_StateMachine) {
	m_pStateMachine = p_StateMachine;

	if (m_QuitButton->Update())
		m_App->Quit();

	if (m_PlayButton->Update())

}

void MenuState::Draw(RenderManager* pRenderManager) {
	// background
	pRenderManager->SetRenderColor(255, 255, 255, 255);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 2, Camera::Instance()->GetWindowHeight() / 2, Camera::Instance()->GetWindowWidth(), Camera::Instance()->GetWindowHeight());
	pRenderManager->SetRenderColor(230, 51, 51, 255);
	pRenderManager->DrawText(m_Font, "Asteroids.io!", Camera::Instance()->GetWindowWidth() / 3.1f, Camera::Instance()->GetWindowHeight() / 1.2f);

	// button background
	pRenderManager->SetRenderColor(0, 0, 0, 255);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 3, Camera::Instance()->GetWindowHeight() / 3, 350, 100);
	pRenderManager->DrawSprite(NULL, Camera::Instance()->GetWindowWidth() / 1.5f, Camera::Instance()->GetWindowHeight() / 3, 350, 100);

	// Reset Render Color
	pRenderManager->SetRenderColor(255, 255, 255, 255);
}

void MenuState::Exit() {
	delete m_PlayButton;
	delete m_QuitButton;
	delete m_Font;
}
