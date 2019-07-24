#include "HealthPickup.h"
#include <random>
#include "Actor.h"
#include "TextureManager.h"
#include "BoxCollider.h"
#include "CollisionManager.h"

HealthPickup::HealthPickup() : Actor(Vector2(100, 100))
{
	// Initialise variables that are going to be needed.
	m_bWrapAndRespawn = true;
	m_bVisible = true;

	// Sets the velocity in each direction to be somewhere between 1 and 10.
	m_v2Velocity.x = (float)(rand() % 10 + 1);
	m_v2Velocity.y = (float)(rand() % 10 + 1);

	// Ask the texture manager to load the health pickup texture for the turret.
	TextureManager* textMan = textMan->Instance();
	m_pTexture = textMan->LoadTexture("Powerup.png");

	// Set the foward direction to between 1 to 1000.
	m_v2Forward.x = (float)(rand() % 1000 + 1);
	m_v2Forward.y = (float)(rand() % 1000 + 1);
	m_v2Forward.normalise();
	
	// Set the velocity to between -3 and 3.
	m_v2Velocity.x = (float)(rand() % (5 + 1) - 3);
	m_v2Velocity.y = (float)(rand() % (5 + 1) - 3);

	//Collider
	Vector2 v2Extend = Vector2(m_pTexture->GetWidth() / 2, m_pTexture->GetHeight() / 2);
	m_pCollider = new BoxCollider(v2Extend, ELayer::ECOLLISIONLAYER_HEALTH);
	m_eType = GameObjectType::HEALTH_PICKUP;

	// Add the rock to the collision manager.
	CollisionManager::GetInstance()->AddObject(this);

	// Update the global transform with the rock.
	UpdateGlobalTransform();
}

HealthPickup::~HealthPickup()
{
	// Clean up.
	m_bWrapAndRespawn = false;
	m_bVisible = false;
}

void HealthPickup::Update(float deltaTime)
{
	// Call the base class update.
	Actor::Update(deltaTime);

	// Get the current position as a Vector3.
	Vector3 v3Pos = GetPosition();	

	// Convert the current position to a Vector2.
	Vector2 v2Pos;
	v2Pos.x = v3Pos.x;
	v2Pos.y = v3Pos.y;

	// Change the position by the velocity.
	v2Pos += m_v2Velocity;

	// Set position to the new position.
	SetPosition(v2Pos);
}

void HealthPickup::OnCollision(Player* player)
{
	// Set visible to false.
	m_bVisible = false;
}

void HealthPickup::OnCollision(Rock* rock)
{
	// Set the current position to the previous position,
	// so the health pickup doesn't get stuck in the rock.
	SetPosition(m_v2PreviousPosition);

	// Call the bounce function.
	Bounce();
}

void HealthPickup::OnCollision(Enemy* enemy)
{
	// Set the current position to the previous position,
	// so the health pickup doesn't get stuck in the enemy.
	SetPosition(m_v2PreviousPosition);

	// Call the bounce function.
	Bounce();
}

void HealthPickup::OnCollision(Bullet* bullet)
{
	// Set the current position to the previous position,
	// so the health pickup doesn't get stuck in the bullet.
	SetPosition(m_v2PreviousPosition);

	// Set visible to false.
	m_bVisible = false;
}

void HealthPickup::Bounce()
{
	// Reverse the direction of the pickup, basic bounce against object.
	m_v2Velocity * -1;
}