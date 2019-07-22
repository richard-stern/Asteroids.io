#include "Actor.h"



Actor::Actor(Vector2 Position)
{
	SetPosition(Position);
	m_pCollider = nullptr;

}


Actor::~Actor()
{
}

void Actor::Update(float fDeltaTime)
{
	GameObject::Update(fDeltaTime);
	
	if(m_pCollider)
	{
		//GetPosition = SetPosition
		Vector2 v2Pos = GetPosition();
		m_pCollider->SetPosition(v2Pos);

	}
}
void Actor::OnCollision(GameObject* pOther)
{

}
