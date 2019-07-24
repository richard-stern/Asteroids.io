#pragma once
#include "Collider.h"
#include "CircleCollider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider(Vector2 v2Extend, ELayer eLayer);

	void Draw();

	Vector2 GetMin();
	Vector2 GetMax();
	Vector2 GetExtend() { return m_v2Extend; }

	bool IsCollidingWith(Collider* pOther);

private:
	Vector2 m_v2Extend;
	bool IsColldingWithBox(BoxCollider* pOther);
	bool IsCollidingWithCircle(CircleCollider* pOther);
};

