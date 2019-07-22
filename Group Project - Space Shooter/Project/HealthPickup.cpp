#include "HealthPickup.h"
#include <random>
#include "Actor.h"
#include "TextureManager.h"

HealthPickup::HealthPickup() : Actor(Vector2(rand(), rand()))
{
	// Initialise variables that are going to be needed.
	_wrapAndRespawn = true;
	_visible = true;

	// Sets the velocity in each direction to be somewhere between 1 and 10.
	_velocity.x = rand() % 10 + 1;
	_velocity.y = rand() % 10 + 1;

	// Ask the texture manager to load the health pickup texture for the turret.
	TextureManager* textMan;
	_texture = textMan->LoadTexture("Powerup.png");
}

HealthPickup::~HealthPickup()
{
	// Clean up.
	_wrapAndRespawn = false;
	_visible = false;
}

void HealthPickup::OnCollision(Player* player)
{
	// Set visible to false.
	_visible = false;
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
	_visible = false;
}

void HealthPickup::Bounce()
{
	// Reverse the direction of the pickup, basic bounce against object.
	_velocity * -1;
}