#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius, ELayer eLayer) : Collider(CircleColliderType,eLayer)
{
	m_fRadius = radius;
}

void CircleCollider::Draw()
{
	RenderManager* renderer = RenderManager::Instance();
	renderer->SetRenderColor(0, 0, 1, 0);
	//renderer->DrawCircle(_position.x, _position.y, _radius);
}

bool CircleCollider::IsCollidingWith(Collider * other)
{
	if (other->GetType() == CircleColliderType)
		return IsCollidingWithCircle(static_cast<CircleCollider*>(other));
	else
		return IsColldingWithBox(static_cast<BoxCollider*>(other));
}

// Find the closest point on the AABB to the circle,
// then compare it with the circle's radius
bool CircleCollider::IsColldingWithBox(BoxCollider * other)
{
	Vector2 boxMin = other->GetMin();
	Vector2 boxMax = other->GetMax();
	Vector2 myPosition = GetPosition();
	Vector2 clampedPosition = clamp(myPosition, boxMin, boxMax);

	float sqrDistance = (clampedPosition - myPosition).magnitudeSqr();
	float sqrRadius = powf(GetRadius(), 2);

	return sqrDistance <= sqrRadius;
}

bool CircleCollider::IsCollidingWithCircle(CircleCollider* other)
{
	Vector2 otherPosition = other->GetPosition();
	float sqrDistance = (m_v2Position - otherPosition).magnitudeSqr();
	float sqrTotalRadius = powf((m_fRadius + other->GetRadius()), 2);

	return sqrDistance <= sqrTotalRadius;
}
