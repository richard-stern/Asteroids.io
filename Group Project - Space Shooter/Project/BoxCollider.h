#pragma once
#include "Collider.h"
#include "CircleCollider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider(Vector2 extend);

	void Draw();

	Vector2 GetMin();
	Vector2 GetMax();
	Vector2 GetExtend() { return _extend; }

	bool IsCollidingWith(Collider* other);

private:
	Vector2 _extend;
	bool IsColldingWithBox(BoxCollider* other);
	bool IsCollidingWithCircle(CircleCollider* other);
};

