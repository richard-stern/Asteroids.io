#include "Level.h"


Level::Level(int nAsteroids, int nStars, int nEnemies, int nHealthPickups)
{
	//Sets the amount of asteroids in the game
	m_nStars = nStars;
	m_nAsteroids = nAsteroids;
	m_nEnemies = nEnemies;
	m_nHealthPickups = nHealthPickups;

	//Adds player to child list
	/*AddChild(m_pPlayer);*/

	//Creates the Rocks and adds them to child list
	m_apRock = new Rock*[m_nAsteroids];
	for (int i = 0; i < m_nAsteroids; ++i)
	{
		m_apRock[i] = new Rock();
		AddChild(m_apRock[i]);
	}
	//Creates the Stars and adds them to child list
	m_apStar = new Star*[m_nStars];
	for (int i = 0; i < m_nStars; ++i)
	{
		m_apStar[i] = new Star();
		AddChild(m_apStar[i]);
	}

	//Creates the player
	m_pPlayer = new Player(Vector2((float)(Camera::Instance()->GetWindowWidth()/2), (float)(Camera::Instance()->GetWindowHeight()/2)));
	//Adds player to child list
	AddChild(m_pPlayer);

	//Creates the Health pickups and adds them to child list
	m_apHPPickup = new HealthPickup*[m_nHealthPickups];
	for (int i = 0; i < m_nHealthPickups; ++i)
	{
		m_apHPPickup[i] = new HealthPickup;
		AddChild(m_apHPPickup[i]);
	}

	//Creates the Enemies and adds them to child list
	m_apEnemy = new Enemy*[m_nEnemies];
	for (int i = 0; i < m_nEnemies; ++i)
	{
		m_apEnemy[i] = new Enemy(m_pPlayer);
		AddChild(m_apEnemy[i]);
	}

	//Creates the Rocks and adds them to child list
	m_apRock = new Rock*[m_nAsteroids];
	for (int i = 0; i < m_nAsteroids; ++i)
	{
		m_apRock[i] = new Rock();
		AddChild(m_apRock[i]);
	}

	m_bWrapAndRespawn = false;
}

Level::~Level()
{
	//Deletes Player
	delete m_pPlayer;
	m_pPlayer = nullptr;
	//Deletes the rocks in the rock array
	for (int i = 0; i < m_nAsteroids; ++i)
	{
		delete m_apRock[i];
		m_apRock[i] = nullptr;
	}
	//Deletes the rock array
	delete[] m_apRock;
	m_apRock = nullptr;
	//Deletes the stars in the star array
	for (int i = 0; i < 20; ++i)
	{
		delete m_apStar[i];
		m_apStar[i] = nullptr;
	}
	//Deletes the star array
	delete[] m_apStar;
	m_apStar = nullptr;
	//Deletes the Enemies in the array
	for (int i = 0; i < 2; ++i)
	{
		delete m_apEnemy[i];
		m_apEnemy[i] = nullptr;
	}
	//Deletes the enemy array
	delete[] m_apEnemy;
	m_apEnemy = nullptr;
	//Deletes the HealthPickups in the array
	for (int i = 0; i < m_nHealthPickups; ++i)
	{
		delete m_apHPPickup[i];
		m_apHPPickup[i] = nullptr;
	}
	//Deletes the HealthPickup array
	delete[] m_apHPPickup;
	m_apHPPickup = nullptr;
}

Player* Level::GetPlayer()
{
	return m_pPlayer;
}