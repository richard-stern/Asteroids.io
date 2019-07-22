#include "Collider.h"

Collider::Collider(ColliderType type, ELayer layer = ECOLLISIONLAYER_NONE)
{
	m_eType = type;
	m_eLayer = layer;
}

void Collider::SetPosition(Vector2 position)
{
	m_v2Position = position;
}

Vector2 Collider::clamp(Vector2 position, Vector2 min, Vector2 max)
{
	Vector2 result;

	result.x = std::fmax(min.x, std::fmin(position.x, max.x));
	result.y = std::fmax(min.y, std::fmin(position.y, max.y));

	return result;
}

void Collider::SetLayer(ELayer eLayer)
{
	m_eLayer = eLayer;
}
