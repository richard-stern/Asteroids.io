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
	for (int i = 0; i < (int) m_prgColliders.size() - 1; ++i)
	{
		for (int j = 1; j < (int) m_prgColliders.size() - 1; ++j)
		{
			if (i != j)
			{
				// Game object's we're checking.
				GameObject* pGameObject = m_prgColliders[i];
				GameObject* pOtherGameObject = m_prgColliders[j];

				// Colliders of the game object's we're checking.
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
				// passing each other in as the parameter.
				if (m_prgColliders[i]->GetVisible() && m_prgColliders[j]->GetVisible() && pCollider->IsCollidingWith(pOtherCollider))
				{
					m_prgColliders[i]->OnCollision(pOtherGameObject);
					m_prgColliders[j]->OnCollision(pGameObject);
				}
			}
		}
	}
}