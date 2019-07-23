/*
=======================
Enemy Class
Written By: James
=======================
*/

#pragma once

//Includes
#include "Actor.h"
#include "TextureManager.h"
#include "Camera.h"
#include "Player.h"
#include "Bullet.h"
#include "GUI.h"

//Declaration of class, inherits from Actor base class.
class Enemy : public Actor
{
public:

	//Constructor and Destructor functions.
	Enemy(TextureManager* pEnemyTexture, Player* pPlayer);
	~Enemy();

	//Collision Detection Functions.
	void OnCollision(Player* pPlayer);
	void OnCollision(Bullet* pBullet);

	//Update Function
	virtual void Update(float deltaTime);

private:
	//Texture variable.
	Texture* m_pTexture;

	//pointer to a player
	Player* m_pPlayer;
};