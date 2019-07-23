/*-----------------------------------------------------------------------------
Author:			Connor Young
Description:	Bullet functionality 

Usage:			Spawns the bullet at set location 
				Fires it in a given direction 
				Deals damage to any rock or enemies 
				it comes in contact with 
-------------------------------------------------------------------------------*/

#pragma once
#include "Actor.h"
#include "Texture.h"
#include "Vector2.h" 



class Bullet : public Actor
{
public:
	//Constructor 
	Bullet();
	~Bullet();

	//Updating the positon of the bullet 
	//	and keeping track of it lifetime 
	void Update(float fDeltaTime);

	//Called to fire the bullet from a set postion 
	//	in a given direction 
	void Shoot(Vector2 v2Pos, Vector2 v2Dir);

	//Deals damage to any enemies and rocks 
	//	it collides with 
	void OnCollision(Actor* pOtherObeject); 

private:
	//Texture of the bullet 
	Texture* m_pTexture; 

	float	m_fLifeTime; 

	float	m_fTimer; 
	
	float	m_fSpeed;

	int		m_nDamage; 
};

