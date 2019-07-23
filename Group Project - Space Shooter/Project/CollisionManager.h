#pragma once
#include <vector>
#include "Actor.h"


class CollisionManager //: public Actor - Unsure if neccesary
{
private:
	CollisionManager();
	static CollisionManager* m_pInstance;
	std::vector<Actor*> m_prgColliders;

public:
	~CollisionManager();

	void AddObject(Actor* pActor);
	void RemoveObject(Actor* pActor);
	void Update(float fDeltaTime);

	static void Create()
	{
		if (!m_pInstance)
			m_pInstance = new CollisionManager();
	}

	static void Destroy()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	static CollisionManager* GetInstance() { return m_pInstance; }
};