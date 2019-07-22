#pragma once
#include "RenderManager.h"
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "HealthPickup.h"
#include "CollisionManager.h"
#include "TextureManager.h"
#include "Rock.h"
#include "Star.h"
#include "Enemy.h"

class Level : public GameObject
{
public:
	//Settable amount for objects in the game
	Level(int nAsteroids, int nStars, int nEnemies, int nHealthPickups);
	//Delete all game objects
	~Level();

private:
	Player* m_pPlayer;

	Rock** m_apRock;

	Star** m_apStar;

	Enemy** m_apEnemy;

	HealthPickup** m_apHPPickup;

	CollisionManager* m_pCollisionManager;

	TextureManager* m_pTextureManager;

	int m_nAsteroids;
	int m_nStars;
	int m_nEnemies;
	int m_nHealthPickups;
};