#include "BulletManager.h"
#include "Bullet.h"
#include "Level.h"
#include "Blackboard.h"

BulletManager::BulletManager()
{
	Level* pLevel = Blackboard::Instance()->GetLevel();

	for (int i = 0; i < BULLET_POOL_SIZE; ++i)	//Loop and create however many bullets
	{
		m_aBulletPool.push_back(new Bullet());	//Add a bullet to the pool
		pLevel->AddChild(m_aBulletPool[i]);
	}
}


BulletManager::~BulletManager()
{
	////Destroy the bullet pool
	//for (int i = 0; i < BULLET_POOL_SIZE; ++i)	//For all bullets in the pool,
	//{
	//	if (m_aBulletPool[i])					//If the bullet exists,
	//	{
	//		delete m_aBulletPool[i];			//Delete each bullet
	//		m_aBulletPool[i] = nullptr;			//Set to nullptr
	//	}
	//}
}

void BulletManager::ShootBullet(Vector2 v2StartPos, Vector2 v2StartDir)
{
	for (int i = 0; i < BULLET_POOL_SIZE; ++i)	//For all bullets in the pool,
	{
		Bullet* pBullet = m_aBulletPool[i];		//Make a pointer to the current bullet, to avoid repeated index calls

		if (pBullet->GetVisible() == false)				//If the bullet is inactive,
		{
			pBullet->Shoot(v2StartPos, v2StartDir);		//Call the shoot function on the bullet
			break;										//Stop searching for bullets
		}
	}
}