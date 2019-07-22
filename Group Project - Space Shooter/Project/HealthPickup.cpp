#include "HealthPickup.h"
#include <random>
#include "Player.h"
#include "Rock.h"
#include "Enemy.h"
#include "Bullet.h"

HealthPickup::HealthPickup()
{
	// Initialise variables that are going to be needed.
	m_bWrapAndRespawn = true;

	m_v2Velocity.x = rand() % 10;
	m_v2Velocity.y = rand() % 10;

	m_bVisible = true;
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
	// Reverse the direction of the pickup.
	m_v2Velocity * -1;
}