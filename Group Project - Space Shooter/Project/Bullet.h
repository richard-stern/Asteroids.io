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
	//How long the bullet will be alive
	//	if it doesn't collide with anything 
	float	m_fLifeTime; 

	float	m_fTimer; 
	
	//The speed bullets will travel 
	float	m_fSpeed;

	//The amount of damage bullets will deal 
	int		m_nDamage; 
};

