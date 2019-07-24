#include "Enemy.h"
#include "CollisionManager.h"
#include "BoxCollider.h"
#include <iostream>

//Enemy constructor, takes a texture from the texture manager.
//Inherits from Actor class and calls it's GetPosition() function.
Enemy::Enemy(Player* pPlayer) : Actor(Vector2((float)(rand() % 1000), (float)(rand() % 1000)))
{
	//Allow the enemy to respawn after death and to wrap around the window when going offscreen.
	SetWrapAndRespawn(true);
	//The enemies will start as invisible because they start offscreen.
	SetVisible(true);

	//Locating the texture file for the Enemy sprite. 
	TextureManager* pTxtMan = pTxtMan->Instance();
	m_pTexture = pTxtMan->LoadTexture("Enemy.png");

	//Setting the type of object the enemy is
	m_eType = GameObjectType::ENEMY;

	//Sets the health of the enemy.
	//Referencing "Bullet.h", BULLET_DAMAGE = 50, making each enemy takes two hits to kill.
	SetHealth(100);

	//store pointers
	m_pPlayer = pPlayer;

	//Setting Collision Detection
	Vector2 v2Extend = Vector2((float)(m_pTexture->GetWidth() / 2), (float)(m_pTexture->GetHeight() / 2));
	m_pCollider = new BoxCollider(v2Extend, ELayer::ECOLLISIONLAYER_ENEMY);
	CollisionManager::GetInstance()->AddObject(this);
}

//Destructor.
Enemy::~Enemy()
{
}

//Enemy's collision detections
void Enemy::OnCollision(GameObject* pOtherObject)
{
	//If the enemy collides with the player.
	if (pOtherObject->GetType() == GameObjectType::PLAYER)
	{
		//Sets the health of the enemy to 0.
		SetHealth(100);

		//Make it invisible.
		SetVisible(false);
	}
	//If the enemy collides with the bullet.
	else if (pOtherObject->GetType() == GameObjectType::BULLET)
	{
		//Deduct 50 from the enemy's health
		SetHealth(m_nHealth - 50);

		//If their health falls to or below 0, stop drawing the enemy.
		if (m_nHealth <= 0)
		{
			SetVisible(false);
		}
	}
}

//Update function is used for steering behaviours.
void Enemy::Update(float deltaTime)
{
	//Call the Actor's update function.
	Actor::Update(deltaTime);

	//If the enemy is dead, return.
	if (GetVisible() == false)
		return;

	//Vectors used to track the positions of the enemy and player.
	Vector2 v2PlayerPos = m_pPlayer->GetPosition();
	Vector2 v2EnemyPos = this->GetPosition();

	//This Vector tracks the current velocity of the player.
	Vector2 v2PlayerVelocity = m_pPlayer->GetVelocity();
	
	//Vector that tracks the direction of the player.
	Vector2 v2Direction = v2PlayerPos - v2EnemyPos;

	//Distance between the player and the enemy.
	float fDistance = (v2PlayerPos - v2EnemyPos).magnitude();

	//Normalisation of the direction.
	v2Direction.normalise();

	//Rotation float, instead of using the Matrix rotate, atan2 is used on an already normalised vector.
	float fRotation = atan2f(v2Direction.y, v2Direction.x) - 1.5780f;
	
	//Seeking function.
	if (fDistance < 1100)
	{
		//Rotation and Position are adjusted here.
		this->SetPosition(v2EnemyPos + v2Direction * 75 * deltaTime);
		this->SetRotation(fRotation);
	}
}