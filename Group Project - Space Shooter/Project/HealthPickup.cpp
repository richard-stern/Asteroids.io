#include "HealthPickup.h"
#include <random>
#include "Player.h"
#include "Rock.h"
#include "Enemy.h"
#include "Bullet.h"

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
	// Clean up.
	m_bWrapAndRespawn = false;
	m_bVisible = false;
}

void HealthPickup::OnCollision(Player* player)
{
	// "Destroy" the pickup.
	m_bVisible = false;

	// The collision manager will/has called the OnCollision of the player,
	// I don't need to do anything else.
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