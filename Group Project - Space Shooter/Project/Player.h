#pragma once
#include "Actor.h"
#include "RenderManager.h"
#include "Turret.h"

class Player : public Actor
{
public:
	Player(Vector2 v2Position);
	~Player();


	float GetSpeed();
	int GetLives();

	void SetSpeed(float fSpeed);
	void SetLives(int nLives);
	void Update(float fDeltaTime);

private:
	Turret* m_pTurret;
	void OnCollision(GameObject* pOtherObject);
	float m_fSpeed;
	int m_nLives;
	Vector2 m_v2PreviousPosition;
	float m_fMaxSpeed;
};
