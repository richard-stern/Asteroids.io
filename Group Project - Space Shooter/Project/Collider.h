#pragma once
#include "Vector2.h"
#include "RenderManager.h"
#include <cmath>

enum ColliderType
{
	BoxColliderType,
	CircleColliderType
};

class BoxCollider;
class CircleCollider;

class Collider
{
public:
	Collider(ColliderType type);
	virtual ~Collider() {};

	ColliderType GetType() { return _type; }

	virtual void Draw() = 0;

	void SetPosition(Vector2 position);
	Vector2 GetPosition() { return _position; }

	virtual bool IsCollidingWith(Collider* other) = 0;

protected:
	Vector2 _position;
	ColliderType _type;
	Vector2 clamp(Vector2 position, Vector2 min, Vector2 max);
};

