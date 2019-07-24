#pragma once
#include <vector>
#include "Vector2.h"
#include "Turret.h"

//How many bullets should be in the bullet pool
#define BULLET_POOL_SIZE 50 

class Bullet;	//Bullet class forward declare

class BulletManager
{
public:

	BulletManager();											//Constructor
	~BulletManager();											//Destructor

	void ShootBullet(Vector2 v2StartPos, Vector2 v2StartDir);	//Finds an inactive bullet and calls the shoot function on it

private:

	std::vector<Bullet*> m_aBulletPool;		//Object pool of bullet pointers
};

