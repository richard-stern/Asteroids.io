#include "Bullet.h"



Bullet::Bullet() : Actor(GetPosition())
{
	SetWrapAndRespawn(false);

	SetVisible(false); 

	m_pTexture = new Texture("BulletTexture.png"); 

	m_fLifeTime = 5.0f;

	m_fTimer = 0.0f;

	m_fSpeed = 100.0f;

	m_nDamage = 50;
}


Bullet::~Bullet()
{
}

void Bullet::Update(float fDeltaTime)
{
	m_fTimer += fDeltaTime; 

	if (GetVisible())
	{
		Vector2 v2Temp;
		v2Temp = GetPosition();

		v2Temp.x += m_fSpeed * fDeltaTime;
		v2Temp.y += m_fSpeed * fDeltaTime;
	}
	
	if (m_fTimer >= m_fLifeTime)
		SetVisible(false);
}

void Bullet::Shoot(Vector2 v2Pos, Vector2 v2Dir)
{
	SetPosition(v2Pos);
	SetRotation(v2Dir); 

	SetVisible(true); 
}