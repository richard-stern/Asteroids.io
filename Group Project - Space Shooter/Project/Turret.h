#pragma once
//--------------------------------------------------------------------------------
// Turret class
// Created by Grant Roberts
//
// The turret that follows the player, pointing towards the mouse.
// Will shoot a bullet when the left mouse button is pressed.
//
// Functions:
//			  Constructor().				Creates the turret.
//			  Destructor().					Cleans up the turret after deletion.
//			  Update(float deltaTime)		Update the turret.
//--------------------------------------------------------------------------------

#include "BulletManager.h"
#include "Actor.h"

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