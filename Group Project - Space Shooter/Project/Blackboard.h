#pragma once

class Level;


class Blackboard
{
public:
	//Singleton stuff
	static Blackboard* Instance();
	static void Create();
	static void Destroy();

	//Stored Variables

	Level* GetLevel();
	void SetLevel(Level* pLevel);

private:
	//Private Constructor and Destructor for Singleton
	Blackboard();
	~Blackboard();

	//Singleton created
	static Blackboard* m_pBlackboard;
	Level* m_pLevel;
	
};

