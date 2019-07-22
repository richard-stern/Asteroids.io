#include "CollisionManager.h"
#include "Vector2.h"

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

// Iterates over the collider array and checks for any intersections between them.
void CollisionManager::Update(float fDeltaTime)
{
	for (int i = 0; i < m_prgColliders.size() - 1; ++i)
	{
		for (int j = 0; j < m_prgColliders.size() - 1; ++j)
		{
			if (i != j)
			{
				Actor* pActor = m_prgColliders[i];
				Actor* pOtherActor = m_prgColliders[j];

				// Objects on the LAYER_NONE layer will never collide.
				if (pActor->eLayer == ECOLLISIONLAYER_NONE || pOtherActor->eLayer == ECOLLISIONLAYER_NONE)
					continue;

				// Objects on the LAYER_PLAYER and LAYER_BULLLET layer will never collide. 
				if (pActor->eLayer == ECOLLISIONLAYER_PLAYER && pOtherActor->eLayer == ECOLLISIONLAYER_BULLET ||
					pOtherActor->eLayer == ECOLLISIONLAYER_PLAYER && pActor->eLayer == ECOLLISIONLAYER_BULLET)
					continue;

				// Objects on the LAYER_ENEMY and LAYER_ROCK layer will never collide. 
				if (pActor->eLayer == ECOLLISIONLAYER_ENEMY && pOtherActor->eLayer == ECOLLISIONLAYER_ROCK ||
					pOtherActor->eLayer == ECOLLISIONLAYER_ENEMY && pActor->eLayer == ECOLLISIONLAYER_ROCK)
					continue;

				// If both objects are visible and intersect, then call both the object's OnCollision function,
				// passing each other in as the parameters.
				if (pActor->IsVisible() && pOtherActor->IsVisible() && Intersection(pActor, pOtherActor))
				{
					pActor->OnCollision(pOtherActor);
					pOtherActor->OnCollision(pActor);
				}
			}
		}
	}
}

// Checks for an intersection betweem two actors.
bool CollisionManager::Intersection(Actor* pActor, Actor* pOtherActor)
{
	Vector2 v2ActorPosition = pActor->GetPosition();
	Vector2 v2OtherActorPosition = pOtherActor->GetPosition();
	float otherX = v2OtherActorPosition.x;
	float otherY = v2OtherActorPosition.y;
	float otherSize = pOtherActor->m_v2Max;
	float otherX1 = otherX + otherSize;
	float otherY1 = otherY + otherSize;

	return (v2ActorPosition.x >= otherX || v2ActorPosition.x <= otherX1) &&
		   (v2ActorPosition.y >= otherY || v2ActorPosition.y <= otherY1);
}