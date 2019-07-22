#pragma once
#include "Collider.h"
#include "BoxCollider.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(float radius);

	void Draw();

	float GetRadius() { return m_fRadius; }

	bool IsCollidingWith(Collider* other);

private:
	float m_fRadius;
	bool IsColldingWithBox(BoxCollider* other);
	bool IsCollidingWithCircle(CircleCollider* other);
};

