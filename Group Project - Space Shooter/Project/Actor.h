#pragma once
#include "GameObject.h"
#include "Collider.h"

class Actor : public GameObject
{
public:
	Actor();
	Actor(Vector2 Position);
	~Actor();
		//Creation of a Update Function.
	 virtual void Update(float fDeltaTime);

	 Collider* GetCollider() { return m_pCollider; }
	 virtual void OnCollision(GameObject* pOther);

protected:
	
	int m_nHealth;
	int m_nMaxHealth;

private:

	 Collider* m_pCollider;

};

