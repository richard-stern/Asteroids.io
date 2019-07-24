#include "Rock.h"
#include "TextureManager.h"
#include <random>
#include "Actor.h"
#include "Player.h"
#include "GUI.h"
#include "BoxCollider.h"
#include "CollisionManager.h"

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
	// FEATURE: each game, all the rocks spawn as different types, it's a rogue-lite!

	// Set the forward direction to between 1 and 1000.
	m_v2Forward.x = (float)(rand() % 1000 + 1);
	m_v2Forward.y = (float)(rand() % 1000 + 1);
	m_v2Forward.normalise();

	// Set the velocity to between -3 and 3.
	m_v2Velocity.x = (float)(rand() % (5 + 1) - 3);
	m_v2Velocity.y = (float)(rand() % (5 + 1) - 3);

	// Set the collider.
	Vector2 v2Extend = Vector2(m_pTexture->GetWidth() / 2, m_pTexture->GetHeight() / 2);
	m_pCollider = new BoxCollider(v2Extend, ELayer::ECOLLISIONLAYER_ROCK);
	m_eType = GameObjectType::ROCK;

	CollisionManager::GetInstance()->AddObject(this);

	UpdateGlobalTransform();
}

Rock::~Rock()
{
}

void Rock::Update(float deltaTime)
{
	// Call the base class update.
	Actor::Update(deltaTime);

	// Get the position as a Vector3.
	Vector3 v3Pos = GetPosition();

	// Convert the position to a Vector2.
	Vector2 v2Pos;
	v2Pos.x = v3Pos.x;
	v2Pos.y = v3Pos.y;

	// Change the position by the velocity.
	v2Pos += m_v2Velocity;

	// Set position to the new position.
	SetPosition(v2Pos);
}

void Rock::OnCollision(GameObject* gameObject)
{
	// If the rock collided with the player.
	if (gameObject->GetType() == GameObjectType::PLAYER)
	{
		// Set the position of the rock to the previous position.
		SetPosition(m_v2PreviousPosition);

		// Bounce the rock.
		Bounce();
	}

	// If the rock collided with a bullet.
	else if (gameObject->GetType() == GameObjectType::BULLET)
	{
		// Decrease the health of the rock.
		m_nHealth -= 50;

		// If the rock has no health -> deactivate the rock.
		if (m_nHealth <= 0)
			m_bVisible = false;

		// Set the rock's position to it's preivous position.
		SetPosition(m_v2PreviousPosition);

		// Bounce the rock.
		Bounce();
	}

	// If the rock collided with another rock.
	else if (gameObject->GetType() == GameObjectType::ROCK)
	{
		// Get the health of the rock.
		int rockHealth = ((Actor*)gameObject)->GetHealth();

		// Set the health of the other rock to it's health - my max health.
		((Actor*)gameObject)->SetHealth(rockHealth -= m_nMaxHealth);

		// If the rock has no health -> deactivate the rock.
		if (m_nHealth <= 0)
			m_bVisible = false;

		// Set the rock's position to it's preivous position.
		SetPosition(m_v2PreviousPosition);

		// Bounce the rock.
		Bounce();
	}

	// If the rock collided with an enemy.
	else if (gameObject->GetType() == GameObjectType::ENEMY)
	{
		// Decrease the health of the rock.
		m_nHealth -= 50;

		// If the rock has no health -> deactivate the rock.
		if (m_nHealth <= 0)
			m_bVisible = false;

		// Set the rock's position to it's preivous position.
		SetPosition(m_v2PreviousPosition);

		// Bounce the rock.
		Bounce();
	}
}

void Rock::Bounce()
{
	// Bounce the rock.
	m_v2Velocity * -1;
}