#include "Level.h"
#include "Blackboard.h"


Level::Level(int nAsteroids, int nStars, int nEnemies, int nHealthPickups)
{
	//Set level in blackboard
	Blackboard::Instance()->SetLevel(this);

	//Sets the amount of asteroids in the game
	m_nStars = nStars;
	m_nAsteroids = nAsteroids;
	m_nEnemies = nEnemies;
	m_nHealthPickups = nHealthPickups;
	m_eType = LEVEL;

	//Creates the Stars and adds them to child list
	for (int i = 0; i < m_nStars; ++i)
	{
		Star* m_pStar = new Star();
		m_pStar->SetParent(this);
	}

	//Creates the player
	m_pPlayer = new Player(Vector2((float)(Camera::Instance()->GetWindowWidth()/2), (float)(Camera::Instance()->GetWindowHeight()/2)));
	//Adds player to child list
	m_pPlayer->SetParent(this);

	//Creates the Health pickups and adds them to child list
	for (int i = 0; i < m_nHealthPickups; ++i)
	{
		HealthPickup* m_pHPPickup = new HealthPickup();
		m_pHPPickup->SetParent(this);
	}

	//Creates the Rocks and adds them to child list
	for (int i = 0; i < m_nAsteroids; ++i)
	{
		Rock* m_pRock = new Rock();
		m_pRock->SetParent(this);
	}

	//Creates the Enemies and adds them to child list
	for (int i = 0; i < m_nEnemies; ++i)
	{
		Enemy* m_pEnemy = new Enemy(m_pPlayer);
		m_pEnemy->SetParent(this);
	}

	m_bWrapAndRespawn = false;

	UpdateGlobalTransform();
}

Level::~Level()
{
}

Player* Level::GetPlayer()
{
	return m_pPlayer;
}