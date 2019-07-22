#pragma once
//--------------------------------------------------------------------------------
// Turret class
// Created by Grant Roberts
//
// This object is the turret that follows the player, pointing towards the mouse.
// Will shoot a bullet when the left mouse button is pressed.
//
// Functions:
//			  Update(float deltaTime) Update the turret.
//--------------------------------------------------------------------------------

#include "BulletManager.h"

class Actor;

class Turret : public Actor
{
public:
	//----------------------------------------------------------------------------
	// Constructor.
	//----------------------------------------------------------------------------
	Turret();

	//----------------------------------------------------------------------------
	// Destructor.
	//----------------------------------------------------------------------------
	~Turret();

	//----------------------------------------------------------------------------
	// Update the turret.
	// Params: delta time.
	//----------------------------------------------------------------------------
	void Update(float deltaTime);

private:
	//----------------------------------------------------------------------------
	// The bullet manager.
	//----------------------------------------------------------------------------
	BulletManager* m_pBulletManager;
};