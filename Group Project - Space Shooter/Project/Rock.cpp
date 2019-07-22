#include "Rock.h"
#include "TextureManager.h"
#include <random>
#include "Actor.h"
#include "Player.h"

Rock::Rock() : Actor(Vector2(rand(), rand()))
{
	// Get the texture manager.
	TextureManager* textMan;
	textMan->Instance();

	// Random int for the type of rock.
	int randRock = rand() % 3;

	switch (randRock)
	{
		// Small rock.
	case 0:
		m_pTexture = textMan->LoadTexture("rock_small.png");
		// Takes one hit to destroy.
		m_nHealth = 50;

		// Medium rock.
	case 1:
		m_pTexture = textMan->LoadTexture("rock_medium.png");
		// Takes two hits to destroy.
		m_nHealth = 100;

		// Large rock.
	case 2:
		m_pTexture = textMan->LoadTexture("rock_large.png");
		// Takes three hits to destroy.
		m_nHealth = 150;
	}

	// The velocity of the rock is set to 80.
	SetVelocity(Vector2(80.0f, 80.0f));
}

Rock::~Rock()
{
}

void Rock::OnCollision(Player* player)
{
	// Bounce the rock.
	Bounce();
}

void Rock::OnCollision(Bullet* bullet)
{
	// Decrease the health of the rock by 50 (the damage of the bullet).
	m_nHealth -= 50;
	// Bounce the rock.
	Bounce();
}

void Rock::OnCollision(HealthPickup* healthPickup)
{
	// Bounce the rock.
	Bounce();
}

void Rock::OnCollision(Enemy* Enemy)
{
	// Bounce the rock.
	Bounce();
}

void Rock::Bounce()
{
	// Bounce the rock.
	m_v2Velocity * -1;
}