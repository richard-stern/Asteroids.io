#include "HealthPickup.h"
#include <random>
#include "Actor.h"
#include "TextureManager.h"

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

	m_v2Forward.x = rand() % 180;
	m_v2Forward.y = rand() % 180;
	m_v2Forward.normalise();
}

HealthPickup::~HealthPickup()
{
	// Clean up.
	m_bWrapAndRespawn = false;
	m_bVisible = false;
}

void HealthPickup::Update(float deltaTime)
{
	Actor::Update(deltaTime);

	Vector3 v3Pos = GetPosition();	

	Vector2 v2Pos;
	v2Pos.x = v3Pos.x;
	v2Pos.y = v3Pos.y;

	v2Pos += m_v2Velocity;

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