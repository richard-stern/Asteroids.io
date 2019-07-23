#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "HealthPickup.h"
#include "Rock.h"
#include "Star.h"
#include "Enemy.h"
#include "Vector2.h"

class Level : public GameObject
{
public:
	//Settable amount for objects in the game
	Level(int nAsteroids, int nStars, int nEnemies, int nHealthPickups);
	//Delete all game objects
	~Level();

	Player* GetPlayer();
private:
	Player* m_pPlayer;

	int m_nAsteroids;
	int m_nStars;
	int m_nEnemies;
	int m_nHealthPickups;
};