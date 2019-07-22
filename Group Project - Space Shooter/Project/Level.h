#pragma once
#include "RenderManager.h"
#include <vector>


class GameObject;

class Player;

class Rock;

class Star;

class Enemy;

class HealthPickup;

class CollisionManager;

class TextureManager;

class Level : GameObject
{
public:
	//Settable amount of asteroids in game
	Level(int nAsteroids);

	~Level();

	void Update(float fDeltaTime);

	void Draw(RenderManager* pRenderer);
private:
	std::vector<GameObject*> m_apChildren;

	Player* m_pPlayer;

	Rock** m_apRock;

	Star** m_apStar;

	Enemy** m_apEnemy;

	HealthPickup** m_apHPPickup;

	CollisionManager* m_pCollisionManager;

	TextureManager* m_pTextureManager;

	int m_nAsteroids;
};