#include "GUI.h"
#include "Font.h"
#include "Application.h"
#include "RenderManager.h"
#include "Camera.h"

GUI * GUI::m_pInstance = nullptr;


GUI::GUI() {
	m_nHealth = 0;
	m_nScore = 0;
	m_nLives = 0;

	//GUI *m_pInstance = 0;
	m_fontGUI = new Font("./Fonts/hobo_32px.fnt");
}

GUI::~GUI() {
	delete m_fontGUI;
	delete m_pInstance;
}

GUI *GUI::Instance() {
	if (!m_pInstance)
		m_pInstance = new GUI;
	return m_pInstance;
}

void GUI::Draw(RenderManager* renderer) {
	renderer->SetRenderColor(HUD_COLOUR);
	Vector2 cam = Camera::Instance()->GetPosition();


	// Health
	sprintf_s(m_kHealth, 32, "Health: %i", m_nHealth);
	renderer->DrawText(m_fontGUI, m_kHealth, cam.x, cam.y + HEALTH_OFFSET);
	//renderer->DrawText(m_fontGUI, m_kHealth, 0.0f, Camera::Instance()->GetWindowHeight() - HEALTH_OFFSET);
	
	// Score
	sprintf_s(m_kScore, 32, "Score: %i", m_nScore);
	renderer->DrawText(m_fontGUI, m_kScore, cam.x, cam.y + SCORE_OFFSET);
	//renderer->DrawText(m_fontGUI, m_kScore, 0.0f, Camera::Instance()->GetWindowHeight() - SCORE_OFFSET);
	// Lives

	sprintf_s(m_kLives, 32, "Lives: %i", m_nLives);
	renderer->DrawText(m_fontGUI, m_kLives, cam.x, cam.y + LIVES_OFFSET);
	//renderer->DrawText(m_fontGUI, m_kLives, 0.0f, Camera::Instance()->GetWindowHeight() - LIVES_OFFSET);

	// Resets Color
	renderer->SetRenderColor(255, 255, 255, 255);
}

void GUI::DisplayFPS(RenderManager* renderer) 
{
	
	sprintf_s(m_kFPS, 32, "FPS: %i", app->GetFPS());
	renderer->SetRenderColor(255, 0, 0, 255);
	renderer->DrawText(m_fontGUI, m_kFPS, 0, 720 - 32);

	// Resets Color
	renderer->SetRenderColor(255, 255, 255, 255);
}

void GUI::SetHealth(int health) 
{
	m_nHealth = health;
}

void GUI::AddScore(int score) 
{
	m_nScore += score;
}

int GUI::GetScore() {
	return m_nScore;
}

void GUI::SetLives(int lives) {
	m_nLives = lives;
}