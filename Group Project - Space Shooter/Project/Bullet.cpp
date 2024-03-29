#include "Bullet.h"
#include "TextureManager.h"
#include "CircleCollider.h"
#include "CollisionManager.h"
#include "Player.h"
#include "Blackboard.h"
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
	m_fLifeTime = 1.0f;
	m_fTimer = 0.0f;
	m_fSpeed = 500.0f;
	m_nDamage = 50;
	
	//Set the object type
	m_eType = GameObjectType::BULLET;

	//Collider mumbojumbo 
	m_pCollider = new CircleCollider(8.0f, ELayer::ECOLLISIONLAYER_BULLET);
	CollisionManager::GetInstance()->AddObject(this); 	
}


Bullet::~Bullet()
{
}

void Bullet::Update(float fDeltaTime)
{
	Actor::Update(fDeltaTime);		//Call the base class update to check the collider

	m_fTimer += fDeltaTime; 

	if (m_bVisible)												//If the bullet is currently visible,
	{
		Vector2 v2NewPosition = GetPosition();					//Get the position into a vector
		
		Vector2 v2Direction = m_m3LocalTransform.forward();		//Get the forward direction into a vector
		v2Direction.normalise();								//Normalise to a unit vector

		Player* pPlayer = Blackboard::Instance()->GetPlayer();
		Vector2 v2PlayerVelocity = pPlayer->GetVelocity();

		v2NewPosition += ((m_fSpeed * v2Direction * fDeltaTime) + (v2PlayerVelocity * fDeltaTime));	//Add a vector with the magnitude of the speed in the direction of travel

		SetPosition(v2NewPosition);								//Set the new position
	}
	
	if (m_fTimer >= m_fLifeTime)
	{
		SetVisible(false); 
	}
}

void Bullet::Shoot(Vector2 v2Pos, Vector2 v2Dir)
{
	m_fTimer = 0.0f;	//Reset the timer to 0 when shot

	SetPosition(v2Pos);
	SetRotation(v2Dir);

	SetVisible(true); 
}

void Bullet::OnCollision(Actor* pOtherObject)
{
	if (pOtherObject->GetType() == ENEMY || pOtherObject->GetType() == ROCK || pOtherObject->GetType() == HEALTH_PICKUP)
	{
		SetVisible(false);
		/*int nTempHealth; 
		nTempHealth = pOtherObject->GetHealth();
		nTempHealth -= m_nDamage; 
		pOtherObject->SetHealth(nTempHealth); */
	}
}
