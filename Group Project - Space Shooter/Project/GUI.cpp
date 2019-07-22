#include "GUI.h"

GUI::GUI() {
	m_nHealth = 0;
	m_nScore = 0;
	m_nLives = 0;

	GUI *m_gInstance = 0;
}

GUI::~GUI() {
	delete m_gInstance;
}

GUI *GUI::Instance() {
	if (!m_gInstance)
		m_gInstance = new GUI;
	return m_gInstance;
}

void GUI::Draw() {

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