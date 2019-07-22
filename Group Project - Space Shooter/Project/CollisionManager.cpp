#include "CollisionManager.h"
#include "Vector2.h"
#include "Collider.h"
#include <algorithm>

CollisionManager* CollisionManager::m_pInstance = nullptr;

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

// Adds an actor to the collider array.
void CollisionManager::AddObject(Actor* pActor)
{
	m_prgColliders.push_back(pActor);
}

// Removes an actor from the collider array.
void CollisionManager::RemoveObject(Actor* pActor)
{
	auto iter = std::find(m_prgColliders.begin(), m_prgColliders.end(), pActor);
	if (iter != m_prgColliders.end())
	{
		m_prgColliders.erase(iter);
	}
}

// Iterates over the collider array and checks for intersection between them.
void CollisionManager::Update(float fDeltaTime)
{
	for (int i = 0; i < m_prgColliders.size() - 1; ++i)
	{
		for (int j = 1; j < m_prgColliders.size() - 1; ++j)
		{
			if (i != j)
			{
				Collider* pCollider = m_prgColliders[i]->GetCollider();
				Collider* pOtherCollider = m_prgColliders[j]->GetCollider();

				// Objects on the LAYER_NONE will never collide.
				if (pCollider->m_eLayer == ECOLLISIONLAYER_NONE || pOtherCollider->m_eLayer == ECOLLISIONLAYER_NONE)
					continue;

				// Objects on LAYER_PLAYER and LAYER_BULLLET will never collide. 
				if (pCollider->m_eLayer == ECOLLISIONLAYER_PLAYER && pOtherCollider->m_eLayer == ECOLLISIONLAYER_BULLET ||
					pOtherCollider->m_eLayer == ECOLLISIONLAYER_PLAYER && pCollider->m_eLayer == ECOLLISIONLAYER_BULLET)
					continue;

				// Objects on LAYER_ENEMY and LAYER_ROCK will never collide. 
				if (pCollider->m_eLayer == ECOLLISIONLAYER_ENEMY && pOtherCollider->m_eLayer == ECOLLISIONLAYER_ROCK ||
					pOtherCollider->m_eLayer == ECOLLISIONLAYER_ENEMY && pCollider->m_eLayer == ECOLLISIONLAYER_ROCK)
					continue;

				// If both objects are visible and intersect, then call both the object's OnCollision function,
				// passing each other in as the parameters.
				if (m_prgColliders[i]->IsVisible() && m_prgColliders[j]->IsVisible() && pCollider->IsCollidingWith(pOtherCollider))
				{
					m_prgColliders[i]->OnCollision(pOtherCollider);
					m_prgColliders[j]->OnCollision(pCollider);
				}
			}
		}
	}
}