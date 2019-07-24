#pragma once
//--------------------------------------------------------------------------------
// Rock class
// Created by Grant Roberts.
//
// This is the class for the asteroids that fly around in the game.
//
// Functions:
//			  Constructor()					Create the rock.
//			  Destructor()					Clean up the rock (does nothing).
//			  OnCollision(Player* player)	Rock collides with the player
//			  OnCollision(Bullet* bullet)	Rock collides with a bullet.
//			  OnCollision(HealthPickup* healthPickup)...
//											Rock collides with the health pickup.
//			  OnCollision(Enemy* enemy)		Rock collides with an enemy.
//			  OnCollision(Rock* rock)		Rock collides with another rock.
//--------------------------------------------------------------------------------

#include "Actor.h"

class Rock : public Actor
{
public:
	//--------------------------------------------------------------------------------
	// Constructor.
	//--------------------------------------------------------------------------------
	Rock();

	//--------------------------------------------------------------------------------
	// Destructor.
	//--------------------------------------------------------------------------------
	~Rock();

	// Update the rocks.
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------
	// On collision with another game object.
	// Params: the game object.
	//--------------------------------------------------------------------------------
	void OnCollision(GameObject* gameObject);

private:
	//--------------------------------------------------------------------------------
	// Bounce the rock.
	//--------------------------------------------------------------------------------
	void Bounce();

	//--------------------------------------------------------------------------------
	// The previous position of the rock.
	//--------------------------------------------------------------------------------
	Vector2 m_v2PreviousPosition;

	//--------------------------------------------------------------------------------
	// Vector in the direction of forwards for the rock.
	//--------------------------------------------------------------------------------
	Vector2 m_v2Forward;
};