#pragma once
#include "Collider.h"
#include "BoxCollider.h"

class CircleCollider :
	public Collider
{
public:
	CircleCollider(float radius);

	void Draw();

	float GetRadius() { return _radius; }

	bool IsCollidingWith(Collider* other);

private:
	float _radius;
	bool IsColldingWithBox(BoxCollider* other);
	bool IsCollidingWithCircle(CircleCollider* other);
};

