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

class Player;
class Bullet;
class HealthPickup;
class Enemy;

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

	//--------------------------------------------------------------------------------
	// On collision with the player.
	// Params: the player.
	//--------------------------------------------------------------------------------
	void OnCollision(Player* player);

	//--------------------------------------------------------------------------------
	// On collision with a bullet.
	// Params: the bullet.
	//--------------------------------------------------------------------------------
	void OnCollision(Bullet* bullet);

	//--------------------------------------------------------------------------------
	// On collision with the health pickup.
	// Params: the health pickup.
	//--------------------------------------------------------------------------------
	void OnCollision(HealthPickup* healthPickup);

	//--------------------------------------------------------------------------------
	// On collision with an enemy.
	// Params: the enemy.
	//--------------------------------------------------------------------------------
	void OnCollision(Enemy* enemy);

	//--------------------------------------------------------------------------------
	// On collision with another rock.
	// Params: the rock.
	//--------------------------------------------------------------------------------
	void OnCollision(Rock* rock);

private:
	//--------------------------------------------------------------------------------
	// Bounce the rock.
	//--------------------------------------------------------------------------------
	void Bounce();

	//--------------------------------------------------------------------------------
	// The previous position of the rock.
	//--------------------------------------------------------------------------------
	Vector2 m_v2PreviousPosition;
};