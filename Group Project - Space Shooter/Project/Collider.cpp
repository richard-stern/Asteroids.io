#include "Collider.h"

Collider::Collider(ColliderType type)
{
	_type = type;
}

void Collider::SetPosition(Vector2 position)
{
	_position = position;
}

Vector2 Collider::clamp(Vector2 position, Vector2 min, Vector2 max)
{
	Vector2 result;

	result.x = std::fmax(min.x, std::fmin(position.x, max.x));
	result.y = std::fmax(min.y, std::fmin(position.y, max.y));

	return result;
}
