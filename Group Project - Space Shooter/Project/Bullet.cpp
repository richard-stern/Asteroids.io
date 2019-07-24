#include "Bullet.h"
#include "TextureManager.h"
#include "CircleCollider.h"
#include "CollisionManager.h"
#include <iostream>



Bullet::Bullet() : Actor(GetPosition())
{
	//Stops bullets from wrapping around the game window 
	SetWrapAndRespawn(false);

	//Making bullets invisible on creation 
	SetVisible(false); 

	//Fetching the bullet texture and assigning it 
	//	to the member texture pointer 
	TextureManager* pTextMan = pTextMan->Instance(); 
	m_pTexture = pTextMan->LoadTexture("Bullet.png"); 

	//Assigning member variables their values 
	m_fLifeTime = 5.0f;
	m_fTimer = 0.0f;
	m_fSpeed = 500.0f;
	m_nDamage = 50;
	
	//Collider mumbojumbo 
	m_pCollider = new CircleCollider(8.0f, ELayer::ECOLLISIONLAYER_BULLET);
	CollisionManager::GetInstance()->AddObject(this); 	
}


Bullet::~Bullet()
{
}

void Bullet::Update(float fDeltaTime)
{
	m_fTimer += fDeltaTime; 

	if (m_bVisible)
	{
		Vector2 v2NewPosition = GetPosition();
		
		Vector2 v2Direction = m_m3LocalTransform.forward();
		v2Direction.normalise();

		v2NewPosition += m_fSpeed * v2Direction * fDeltaTime;

		SetPosition(v2NewPosition);
	}
	
	if (m_fTimer >= m_fLifeTime)
	{
		SetVisible(false); 
	}
}

void Bullet::Shoot(Vector2 v2Pos, Vector2 v2Dir)
{
	m_fTimer = 0.0f;

	SetPosition(v2Pos);
	SetRotation(v2Dir);

	SetVisible(true); 
}

void Bullet::OnCollision(Actor* pOtherObject)
{
	if (pOtherObject->GetType() == ENEMY || pOtherObject->GetType() == ROCK)
	{
		SetVisible(false); 
		int nTempHealth; 
		nTempHealth = GetHealth();
		nTempHealth -= m_nDamage; 
		SetHealth(nTempHealth); 

		std::cout << "Bullet Fired/n"; 
	}
}
