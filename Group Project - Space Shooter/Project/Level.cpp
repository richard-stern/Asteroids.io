#include "Level.h"


Level::Level(int nAsteroids, int nStars, int nEnemies, int nHealthPickups)
{
	//Creates the collision manager
	m_pCollisionManager->Create();
	m_pCollisionManager = CollisionManager::GetInstance();

	//Creates the texture manager
	m_pTextureManager->Create();
	m_pTextureManager = TextureManager::Instance();

	//Sets the amount of asteroids in the game
	m_nAsteroids = nAsteroids;
	m_nStars = nStars;
	m_nEnemies = nEnemies;
	m_nHealthPickups = nHealthPickups;
	//Creates the player
	m_pPlayer = new Player;

	//Adds player to child list
	AddChild(m_pPlayer);

	//Creates the Rocks and adds them to child list
	for (int i = 0; i < m_nAsteroids; ++i)
	{
		m_apRock[i] = new Rock;
		AddChild(m_apRock[i]);
	}
	//Creates the Stars and adds them to child list
	for (int i = 0; i < m_nStars; ++i)
	{
		m_apStar[i] = new Star;
		AddChild(m_apStar[i]);
	}
	//Creates the Enemies and adds them to child list
	for (int i = 0; i < m_nEnemies; ++i)
	{
		m_apEnemy[i] = new Enemy;
		AddChild(m_apEnemy[i]);
	}
	//Creates the Health pickups and adds them to child list
	for (int i = 0; i < m_nHealthPickups; ++i)
	{
		m_apHPPickup[i] = new HealthPickup;
		AddChild(m_apHPPickup[i]);
	}
	m_bWrapAndRespawn = false;
}

Level::~Level()
{
	delete m_pPlayer;

	for (int i = 0; i < m_nAsteroids; ++i)
	{
		delete m_apRock[i];
		m_apRock[i] = nullptr;
	}
	delete[] m_apRock;
	m_apRock = nullptr;

	for (int i = 0; i < 20; ++i)
	{
		delete m_apStar[i];
		m_apStar[i] = nullptr;
	}
	delete[] m_apStar;
	m_apStar = nullptr;

	for (int i = 0; i < 2; ++i)
	{
		delete m_apEnemy[i];
		m_apEnemy[i] = nullptr;
	}
	delete[] m_apEnemy;
	m_apEnemy = nullptr;

	for (int i = 0; i < 3; ++i)
	{
		delete m_apHPPickup[i];
		m_apHPPickup[i] = nullptr;
	}
	delete[] m_apHPPickup;
	m_apHPPickup = nullptr;

	m_pCollisionManager->Destroy();

	m_pTextureManager->Destroy();
}

