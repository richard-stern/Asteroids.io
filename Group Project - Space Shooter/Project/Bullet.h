/*-----------------------------------------------------------------------------
Author:			Connor Young
Description:	Bullet functionality 

Usage:			
-------------------------------------------------------------------------------*/

#pragma once
#include "Actor.h"
#include "Texture.h"
#include "Vector2.h" 

#define BULLET_LIFETIME 5
#define BULLET_SPEED 100
#define BULLET_DAMAGE 50

class Bullet : public Actor
{
public:
	Bullet();
	~Bullet();

	void Update(float fDeltaTime);

	void Shoot(Vector2 v2Pos, Vector2 v2Dir);

private:
	Texture* m_pTexture; 

	float	m_fLifeTime; 

	float	m_fTimer; 
	
	float	m_fSpeed;

	int		m_nDamage; 
};

