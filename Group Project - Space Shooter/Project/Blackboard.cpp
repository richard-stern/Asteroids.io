#include "Blackboard.h"

//Declare Singleton
//-------------------------------------------
Blackboard* Blackboard::m_pBlackboard = nullptr;
//-------------------------------------------




Blackboard* Blackboard::Instance()
{
	return m_pBlackboard;
}

void Blackboard::Create()
{
	m_pBlackboard = new Blackboard;
}

void Blackboard::Destroy()
{
	delete m_pBlackboard;
}

Level* Blackboard::GetLevel()
{
	return m_pLevel;
}

void Blackboard::SetLevel(Level* pLevel)
{
	m_pLevel = pLevel;
}

Player* Blackboard::GetPlayer()
{
	return m_pPlayer;
}

void Blackboard::SetPlayer(Player* pPlayer)
{
	m_pPlayer = pPlayer;
}

int Blackboard::GetScore()
{
	return m_nScore;
}

void Blackboard::SetScore(int nScore)
{
	m_nScore = nScore;
}

Blackboard::Blackboard()
{
}


Blackboard::~Blackboard()
{
}
