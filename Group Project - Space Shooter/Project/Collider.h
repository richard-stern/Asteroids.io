#pragma once
#include "Vector2.h"
#include "RenderManager.h"
#include <cmath>

enum ColliderType
{
	BoxColliderType,
	CircleColliderType
};

enum ELayer
{
	ECOLLISIONLAYER_NONE,
	ECOLLISIONLAYER_PLAYER,
	ECOLLISIONLAYER_BULLET,
	ECOLLISIONLAYER_ROCK,
	ECOLLISIONLAYER_ENEMY,
	ECOLLISIONLAYER_HEALTH
};

class BoxCollider;
class CircleCollider;

class Collider
{
public:
	Collider(ColliderType type, ELayer layer);
	virtual ~Collider() {};

	ColliderType GetType() { return _type; }

	virtual void Draw() = 0;

	void SetPosition(Vector2 position);
	Vector2 GetPosition() { return _position; }

	virtual bool IsCollidingWith(Collider* other) = 0;

	ELayer m_eLayer;
	void SetLayer(ELayer eLayer);

protected:
	Vector2 _position;
	ColliderType _type;
	Vector2 clamp(Vector2 position, Vector2 min, Vector2 max);
};

