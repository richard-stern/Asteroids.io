#pragma once
#include "Collider.h"
#include "BoxCollider.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(float fRadius, ELayer eLayer);

	void Draw();

	float GetRadius() { return m_fRadius; }

	bool IsCollidingWith(Collider* pOther);

private:
	float m_fRadius;
	bool IsColldingWithBox(BoxCollider* pOther);
	bool IsCollidingWithCircle(CircleCollider* pOther);
};

