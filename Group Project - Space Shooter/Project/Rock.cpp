#include "Rock.h"
#include "TextureManager.h"
#include <random>
#include "Actor.h"
#include "Player.h"

Rock::Rock() : Actor(Vector2((float)(rand() % 1000), (float)(rand() % 1000)))
{
	// Initialise the previous position of the rock, for collision.
	m_v2PreviousPosition = GetPosition();

	// The rock will wrap and respawn in the level.
	// So when it goes outside the level,
	// it will be respawn and wrap around the level.
	m_bWrapAndRespawn = true;

	// Get the texture manager.
	TextureManager* textMan = textMan->Instance();

	// Random int for the type of rock.
	int randRock = rand() % 3;

	// Switch for which rock the asteroid will spawn as.
	// The bullets do 50 damage, 
	// so the health of the asteroids is set to account for this.
	switch (randRock)
	{
		// Small rock.
	case 0:
		m_pTexture = textMan->LoadTexture("rock_small.png");
		// Takes one hit to destroy.
		m_nMaxHealth = 50;
		m_nHealth = 50;

		// Medium rock.
	case 1:
		m_pTexture = textMan->LoadTexture("rock_medium.png");
		// Takes two hits to destroy.
		m_nMaxHealth = 100;
		m_nHealth = 100;

		// Large rock.
	case 2:
		m_pTexture = textMan->LoadTexture("rock_large.png");
		// Takes three hits to destroy.
		m_nMaxHealth = 150;
		m_nHealth = 150;
	}

	// The velocity of the rock is set to a random number between 1 and 180.
	SetVelocity(Vector2((float)(rand() % 180 + 1), (float)(rand() % 180 + 1)));
}

Rock::~Rock()
{
}

void Rock::OnCollision(Player* player)
{
	// Set the current position to the previous position,
	// so the rock doesn't get stuck in the player.
	SetPosition(m_v2PreviousPosition);
	// Bounce the rock.
	Bounce();
}

void Rock::OnCollision(Bullet* bullet)
{
	// Decrease the health of the rock by 50 (the damage of the bullet).
	m_nHealth -= 50;

	// If the rock's health is = or < 0 -> set visible to false.
	// So the rock can be destroyed.
	if (m_nHealth <= 0)
		m_bVisible = false;

	// Set the current position to the previous position,
	// so the rock doesn't get stuck in the bullet.
	SetPosition(m_v2PreviousPosition);

	// Bounce the rock.
	Bounce();
}

void Rock::OnCollision(HealthPickup* healthPickup)
{
	// Set the current position to the previous position,
	// so the rock doesn't get stuck in the health pickup.
	SetPosition(m_v2PreviousPosition);
	// Bounce the rock.
	Bounce();
}

void Rock::OnCollision(Enemy* Enemy)
{
	// Set the current position to the previous position,
	// so the rock doesn't get stuck in the enemy.
	SetPosition(m_v2PreviousPosition);
	// Bounce the rock.
	Bounce();
}

void Rock::Bounce()
{
	// Bounce the rock.
	m_v2Velocity * -1;
}