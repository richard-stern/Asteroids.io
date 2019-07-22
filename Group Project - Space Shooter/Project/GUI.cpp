#include "GUI.h"
#include "Font.h"
#include "Application.h"
#include "RenderManager.h"
#include "Camera.h"


GUI::GUI() {
	m_nHealth = 0;
	m_nScore = 0;
	m_nLives = 0;

	GUI *m_gInstance = 0;
	Font *m_fontGUI = new Font("./Fonts/hobo_32px.fnt");
}

GUI::~GUI() {
	delete m_fontGUI;
	delete m_gInstance;
}

GUI *GUI::Instance() {
	if (!m_gInstance)
		m_gInstance = new GUI;
	return m_gInstance;
}

void GUI::Draw(RenderManager* renderer) {
	renderer->DrawText(m_fontGUI, "Health", camera->getWindowWidth() / 2, camera->getWindowHeight() / 2);
}

void GUI::DisplayFPS(RenderManager* renderer) {
	sprintf_s(fps, 32, "FPS: %i", Application::GetFPS())
}

void GUI::SetHealth(int health) {
	m_nHealth = health;
}

void GUI::AddScore(int score) {
	m_nScore += score;
}

int GUI::GetScore() {
	return m_nScore;
}

void GUI::SetLives(int lives) {
	m_nLives = lives;
}