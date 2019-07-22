#include "Bullet.h"



Bullet::Bullet(int SetLifeTime /*, Texture* pTexture*/)
{
	//m_bWrapAndRespwan = false; 

	//Remeber to set as not visible when constructed 
	//SetVisible(false); 
	m_nLifeTime = SetLifeTime;

	//m_pTexture = pTexture; 
}


Bullet::~Bullet()
{
}

/*void Bullet::Shoot(Vector2 v2Pos, float fDir)
{
	
}*/ 