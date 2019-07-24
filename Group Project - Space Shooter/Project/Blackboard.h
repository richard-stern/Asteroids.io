#pragma once


//Forward declarations to prevent circular inclusion
class Level;
class Player;

class Blackboard
{
public:
	//Singleton stuff
	static Blackboard* Instance();
	static void Create();
	static void Destroy();

	//Stored Variables


	//Level
	Level* GetLevel();
	void SetLevel(Level* pLevel);

	//Player
	Player* GetPlayer();
	void SetPlayer(Player* pPlayer);

	//Score
	int GetScore();
	void SetScore(int nScore);

private:
	//Private Constructor and Destructor for Singleton
	Blackboard();
	~Blackboard();

	//Singleton created
	static Blackboard* m_pBlackboard;
	Level* m_pLevel;
	Player* m_pPlayer;
	int m_nScore;
};

