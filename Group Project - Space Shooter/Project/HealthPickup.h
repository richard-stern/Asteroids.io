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

	// Update the health pickup.
	void HealthPickup::Update(float deltaTime);

	//----------------------------------------------------------------------------
	// On collision with another game object.
	// Params: the game object.
	//----------------------------------------------------------------------------
	void OnCollision(GameObject* gameObject);

private:
	//----------------------------------------------------------------------------
	// Bounce the health pickup.
	//----------------------------------------------------------------------------
	void Bounce();

	//--------------------------------------------------------------------------------
	// The previous position of the health pickup.
	//--------------------------------------------------------------------------------
	Vector2 m_v2PreviousPosition;

	// The foward direction of the health pickup.
	Vector2 m_v2Forward;
};