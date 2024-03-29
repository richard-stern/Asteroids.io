#pragma once
#include "RenderManager.h"

/*
								GUI Class
	Access functions like this ->		GUI::Instance()->SetHealth(int health)
										GUI::Instance()->AddScore(int score)
										GUI::Instance()->GetScore()
										GUI::Instance()->SetLives(int lives)
										

							Made by Thomas
*/

#define HEALTH_OFFSET 0.0f
#define SCORE_OFFSET 48.0f
#define LIVES_OFFSET 24.0f 
#define HUD_COLOUR 255, 0, 0, 255


class Application;

class GUI {
public:
	~GUI();

	static GUI *Instance();
	
	void Draw(RenderManager* renderer);
	// Doens't work yet
	void DisplayFPS(RenderManager* renderer);

	void SetHealth(int health);
	void AddScore(int score);
	int GetScore();
	void SetLives(int lives);

private:

	static GUI *m_pInstance;

	int m_nHealth;
	int m_nScore;
	int m_nLives;
	char m_kFPS[32];
	char m_kHealth[32];
	char m_kScore[32];
	char m_kLives[32];

	Font *m_fontGUI;
	Application* app;

protected:
	GUI();
};

