#include "Blackboard.h"

//Declare Singleton
//-------------------------------------------
Blackboard* Blackboard::m_pBlackboard = nullptr;
//-------------------------------------------




Blackboard* Blackboard::Instance()
{
	return nullptr;
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

Blackboard::Blackboard()
{
}


Blackboard::~Blackboard()
{
}
