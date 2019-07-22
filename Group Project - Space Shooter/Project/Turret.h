#pragma once

#include "BulletManager.h"

class Actor;

class Turret : public Actor
{
public:
	Turret();
	~Turret();

	void Update(float deltaTime);

private:
	BulletManager* m_pBulletManager;
};

