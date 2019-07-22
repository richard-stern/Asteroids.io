#pragma once
//#include "Actor.h"
//#include "TextureManager.h"
//#include "Vector2.h" 



class Bullet : //public class Actor
{
public:
	Bullet(int bSetLifeTime /*, Texture* pTexture*/);
	~Bullet();

	//Update(float fDeltaTime)

	

	//void Shoot(Vector2 v2Pos, float fDir);

private:
	//Texture* m_pTexture; 
	int m_nLifeTime;


	 
	//Vector2 m_v2Pos;
	//float m_fDir; 


};

