#include "HealthPickup.h"
#include <random>

HealthPickup::HealthPickup()
{
	m_bWrapAndRespawn = true;

	m_v2Velocity.x = rand() % 10;
	m_v2Velocity.y = rand() % 10;

	m_bVisible = true;

	m_pTexture = TextureManager.LoadTexture("./Images/Powerup.png");
}

HealthPickup::~HealthPickup()
{
}

void HealthPickup::OnCollision(Player* player)
{
	// If the health pickup is visible -> call the player's on collision function,
	//									  passing in a pointer to this
	if (m_bVisible)
		player->OnCollision(*this);
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