#include "Level.h"


Level::Level(int nAsteroids, int nStars, int nEnemies, int nHealthPickups)
{
	//Sets the amount of asteroids in the game
	m_nStars = nStars;
	m_nAsteroids = nAsteroids;
	m_nEnemies = nEnemies;
	m_nHealthPickups = nHealthPickups;
	m_eType = LEVEL;
	//Adds player to child list
	/*AddChild(m_pPlayer);*/

	//Creates the Rocks and adds them to child list
	for (int i = 0; i < m_nAsteroids; ++i)
	{
		Rock* m_pRock = new Rock();
		AddChild(m_pRock);
	}
	//Creates the Stars and adds them to child list
	for (int i = 0; i < m_nStars; ++i)
	{
		Star* m_pStar = new Star();
		AddChild(m_pStar);
	}

	//Creates the player
	m_pPlayer = new Player(Vector2((float)(Camera::Instance()->GetWindowWidth()/2), (float)(Camera::Instance()->GetWindowHeight()/2)));
	//Adds player to child list
	AddChild(m_pPlayer);

	//Creates the Health pickups and adds them to child list
	for (int i = 0; i < m_nHealthPickups; ++i)
	{
		HealthPickup* m_pHPPickup = new HealthPickup();
		AddChild(m_pHPPickup);
	}

	//Creates the Enemies and adds them to child list
	for (int i = 0; i < m_nEnemies; ++i)
	{
		Enemy* m_pEnemy = new Enemy(m_pPlayer);
		AddChild(m_pEnemy);
	}

	m_bWrapAndRespawn = false;
}

Level::~Level()
{
}

Player* Level::GetPlayer()
{
	return m_pPlayer;
}

Level* Level::GetLevel()
{
	return this;
}