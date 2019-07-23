#include "Rock.h"
#include "TextureManager.h"
#include <random>
#include "Actor.h"
#include "Player.h"
#include "GUI.h"

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
		break;

		// Medium rock.
	case 1:
		m_pTexture = textMan->LoadTexture("rock_medium.png");
		// Takes two hits to destroy.
		m_nMaxHealth = 100;
		m_nHealth = 100;
		break;

		// Large rock.
	case 2:
		m_pTexture = textMan->LoadTexture("rock_large.png");
		// Takes three hits to destroy.
		m_nMaxHealth = 150;
		m_nHealth = 150;
		break;
	}

	m_v2Forward.x = rand() % 1000;
	m_v2Forward.y = rand() % 1000;
	m_v2Forward.normalise();

	m_v2Velocity.x = rand() % 10;
	m_v2Velocity.y = rand() % 10;
}

Rock::~Rock()
{
}

void Rock::Update(float deltaTime)
{
	Actor::Update(deltaTime);

	Vector3 v3Pos = GetPosition();

	Vector2 v2Pos;
	v2Pos.x = v3Pos.x;
	v2Pos.y = v3Pos.y;

	v2Pos += m_v2Velocity;

	SetPosition(v2Pos);
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

	// If the rock's health is = or < 0 -> set visible to false and add score to scoreboard.
	// So the rock can be destroyed.
	if (m_nHealth <= 0)
	{
		// Make the rock inactive.
		m_bVisible = false;
		
		// Adds score to the scoreboard.
		GUI* gui = gui->Instance();
		gui->AddScore(m_nMaxHealth);
	}

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

void Rock::OnCollision(Rock* rock)
{
	// Set the current position to the previous position,
	// so this rock doesn't get stuck in the other rock.
	SetPosition(m_v2PreviousPosition);

	// Bounce the rock.
	Bounce();
}

void Rock::Bounce()
{
	// Bounce the rock.
	m_v2Velocity * -1;
}