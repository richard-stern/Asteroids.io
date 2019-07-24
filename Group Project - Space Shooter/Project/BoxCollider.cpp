#include "BoxCollider.h"
#include <iostream>


BoxCollider::BoxCollider(Vector2 v2Extend, ELayer eLayer) : Collider(BoxColliderType, eLayer)
{
	m_v2Extend = v2Extend;

}

void BoxCollider::Draw()
{
	RenderManager* renderer = RenderManager::Instance();
	Vector2 min = GetMin();
	Vector2 max = GetMax();

	renderer->SetRenderColor(1.0f, 0.0f, 0.0f, 0.1f);
	//renderer.->DrawBox(min.x + _extend.x, min.y + _extend.y, max.x - min.x, max.y - min.y);
}

Vector2 BoxCollider::GetMin()
{
	return m_v2Position - m_v2Extend;
}

Vector2 BoxCollider::GetMax()
{
	return m_v2Position + m_v2Extend;
}

bool BoxCollider::IsCollidingWith(Collider * other)
{
	if (other->GetType() == BoxColliderType)
		return IsColldingWithBox(static_cast<BoxCollider*>(other));
	else
		return IsCollidingWithCircle(static_cast<CircleCollider*>(other));
}

bool BoxCollider::IsColldingWithBox(BoxCollider * other)
{
	Vector2 myMin = GetMin();
	Vector2 myMax = GetMax();
	Vector2 otherMin = other->GetMin();
	Vector2 otherMax = other->GetMax();

	//any gap
	if (myMax.x < otherMin.x || otherMax.x < myMin.x ||
		myMax.y < otherMin.y || otherMax.y < myMin.y)
		return false;

	return true;
}

// Find the closest point on the AABB to the circle,
// then compare it with the circle's radius
bool BoxCollider::IsCollidingWithCircle(CircleCollider * other)
{
	Vector2 myMin = GetMin();
	Vector2 myMax = GetMax();
	Vector2 circleColPosition = other->GetPosition();
	Vector2 clampedPosition = clamp(circleColPosition, myMin, myMax);

	float sqrDistance = (clampedPosition - circleColPosition).magnitudeSqr();
	float sqrRadius = powf(other->GetRadius(), 2);

	return sqrDistance <= sqrRadius;
}
