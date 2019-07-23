#include "HealthPickup.h"
#include <random>
#include "Actor.h"
#include "TextureManager.h"

HealthPickup::HealthPickup() : Actor(Vector2((float)(rand() % 1000), (float)(rand() % 1000)))
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
}

HealthPickup::~HealthPickup()
{
	// Clean up.
	m_bWrapAndRespawn = false;
	m_bVisible = false;
}

void HealthPickup::OnCollision(Player* player)
{
	// Set visible to false.
	m_bVisible = false;
}

void HealthPickup::OnCollision(Rock* rock)
{
	// Call the bounce function.
	Bounce();
}

void HealthPickup::OnCollision(Enemy* enemy)
{
	// Call the bounce function.
	Bounce();
}

void HealthPickup::OnCollision(Bullet* bullet)
{
	// Set visible to false.
	m_bVisible = false;
}

void HealthPickup::Bounce()
{
	// Reverse the direction of the pickup, basic bounce against object.
	m_v2Velocity * -1;
}