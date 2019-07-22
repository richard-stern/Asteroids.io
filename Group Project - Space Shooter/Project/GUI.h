#pragma once

class GUI {
public:
	~GUI();

	static GUI *Instance();
	
	void Draw();
	void SetHealth(int health);
	void AddScore(int score);
	int GetScore();
	void SetLives(int lives);

private:
	static GUI *m_gInstance;

	int m_nHealth;
	int m_nScore;
	int m_nLives;

protected:
	GUI();


	/*	Help
		Access functions like this ->		GUI::Instance()->SetHealth(int health)
											GUI::Instance()->AddScore(int score)
											GUI::Instance()->GetScore()
											GUI::Instance()->SetLives(int lives)
											GUI::Instance()->Draw(int health)

								Made by Thomas
	*/
};

