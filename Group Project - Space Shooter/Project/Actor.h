#pragma once
#include "GameObject.h"

class Actor : public GameObject
{
public:
	Actor(Vector2 Position);
	~Actor();
		//Creation of a Update Function.
	 virtual void Update(float fDeltaTime);
	 virtual void OnCollision(GameObject* pOther);
private:
	Collider* m_pCollider;
	int m_nHealth;
	int m_nMaxHealth;
};

