#pragma once
//--------------------------------------------------------------------------------
// Rock class
// Created by Grant Roberts.
//
// This is the class for the asteroids that fly around in the game.
//
// Functions:
//			  Constructor()								Create the rock.
//			  Destructor()								Clean up the rock.
//			  OnCollision(Player* player)				Pickup collides with the player
//			  OnCollision(Bullet* bullet)				Pickup collides with a bullet.
//			  OnCollision(HealthPickup* healthPickup)	Pickup collides with the health pickup.
//			  OnCollision(Enemy* enemy)					Pickup collides with an enemy.
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
	void OnCollision(Enemy* Enemy);

private:
	//--------------------------------------------------------------------------------
	// Bounce the rock.
	//--------------------------------------------------------------------------------
	void Bounce();
};