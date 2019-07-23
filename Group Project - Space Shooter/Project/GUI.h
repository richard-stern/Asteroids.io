#pragma once
#include "RenderManager.h"

/*
								GUI Class
	Access functions like this ->		GUI::Instance()->SetHealth(int health)
										GUI::Instance()->AddScore(int score)
										GUI::Instance()->GetScore()
										GUI::Instance()->SetLives(int lives)
										GUI::Instance()->Draw(RenderManager* renderer)
										GUI::Instance()->DisplayFPS(RenderManager* renderer)

							Made by Thomas
*/
class Application;

class GUI {
public:
	~GUI();

	static GUI *Instance();
	
	void Draw(RenderManager* renderer);
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

