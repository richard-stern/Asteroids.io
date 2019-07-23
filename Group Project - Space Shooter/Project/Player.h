#pragma once
#include "Actor.h"
#include "RenderManager.h"


class Player : public Actor
{
public:
	Player(Vector2 v2Position);
	~Player();
private:
	void Update(float fDeltaTime);
	void OnCollision(GameObject* pOtherObject);
	float m_fSpeed;
	float m_fHealth;
	int m_nLives;
	Vector2 m_v2PreviousPosition;
};
