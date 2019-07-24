#include "Star.h"
#include "Camera.h"
#include <iostream>
Star::Star()
{
	f_timer = 0.0f;
	
	m_pTextureManager = TextureManager::Instance();
	m_pTextureManager = m_pTextureManager->Instance();

	m_bWrapAndRespawn = true;

	m_pStarNormal = m_pTextureManager->LoadTexture("star.png");
	m_pStarUp = m_pTextureManager->LoadTexture("StarUp.png");
	m_pStarSide = m_pTextureManager->LoadTexture("StarSide.png");

	m_pTexture = m_pStarSide;
	m_eType = GameObjectType::STAR;

	SetPosition(Vector2(float(rand() % Camera::Instance()->GetWindowWidth()), float(rand() % Camera::Instance()->GetWindowHeight())));
	SetScale(Vector2(2.0f,2.0f));
}

Star::~Star()
{

}

void Star::Update(float deltaTime)
{
	f_timer += deltaTime;
	GameObject::Update(deltaTime);

	if (f_timer > 5.0f)
	{
		f_timer = 0.0f;
		if (m_pTexture == m_pStarUp)
		{
			m_pTexture = m_pStarSide;
		}
		else if (m_pTexture == m_pStarSide)
		{
			m_pTexture = m_pStarNormal;
		}
		else if (m_pTexture == m_pStarNormal)
		{
			m_pTexture = m_pStarUp;
		}
	}
}
