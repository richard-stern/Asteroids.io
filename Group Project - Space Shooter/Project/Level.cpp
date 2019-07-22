#include "Level.h"


Level::Level(int nAsteroids)
{
	m_pPlayer = new Player;
	for
	{
		m_apRock[i] = new Rock;
	}
	for
	{
		m_apStar[i] = new Star;
	}
	for
	{
		m_apEnemy[i] = new Enemy
	}
	for
	{
		m_apHPPickup = new HealthPickup;
	}
	m_pCollisionManager = new CollisionManager;

	m_pTextureManager = new TextureManager;

	m_bWrapAndRespawn = false;
}

Level::~Level()
{
	delete m_pPlayer;
	for
	{
		m_apRock;
	}
	for
	{
		m_apStar;
	}
	for
	{
		m_apEnemy
	}
	for
	{
		m_apHPPickup;
	}

	delete m_pCollisionManager;

	delete m_pTextureManager;
}


void Level::Update(float fDeltaTime)
{
	for (int i = 0; i < m_apChildren.size; ++i)
	{
		m_apChildren[i]->Update(fDeltaTime);
	}
}


void Level::Draw(RenderManager* pRenderer)
{
	for (int i = 0; i < m_apChildren.size; ++i)
	{
		m_apChildren[i]->Draw(pRenderer);
	}
}
