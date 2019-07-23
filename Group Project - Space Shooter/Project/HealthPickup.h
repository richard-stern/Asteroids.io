#pragma once
//--------------------------------------------------------------------------------
// HealthPickup class
// Created by Grant Roberts
//
// The item that restores the player's health when the player moves over the item.
//
// Functions:
//			  Contstructor()				Creates the object.
//			  Destructor()					Cleans up the object during deletion.
//			  OnCollision(Player* player)	Pickup collides with the player.
//			  OnCollision(Rock* rock)		Pickup collides with a rock.
//			  OnCollision(Enemy* enemy)		Pickup collides with an enemy.
//			  OnCollision(Bullet* bullet)	Pickup collides with a bullet.
//--------------------------------------------------------------------------------

#include "Actor.h"

class Player;
class Rock;
class Enemy;
class Bullet;

class HealthPickup : public Actor
{
public:
	//----------------------------------------------------------------------------
	// Constructor.
	//----------------------------------------------------------------------------
	HealthPickup();

	//----------------------------------------------------------------------------
	// Destructor.
	//----------------------------------------------------------------------------
	~HealthPickup();

	//----------------------------------------------------------------------------
	// On collision with the player.
	// Params: the player.
	//----------------------------------------------------------------------------
	void OnCollision(Player* player);

	//----------------------------------------------------------------------------
	// On collision with a rock.
	// Params: the rock.
	//----------------------------------------------------------------------------
	void OnCollision(Rock* rock);

	//----------------------------------------------------------------------------
	// On collision with an enemy.
	// Params: the enemey.
	//----------------------------------------------------------------------------
	void OnCollision(Enemy* enemy);

	//----------------------------------------------------------------------------
	// On collision with a bullet.
	// Params: the bullet.
	//----------------------------------------------------------------------------
	void OnCollision(Bullet* bullet);

private:
	//----------------------------------------------------------------------------
	// Bounce the health pickup.
	//----------------------------------------------------------------------------
	void Bounce();
};