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

	m_pTexture = m_pStarNormal;
	m_eType = GameObjectType::STAR;

	SetPosition(Vector2(float(rand() % Camera::Instance()->GetWindowWidth() * 2), float(rand() % Camera::Instance()->GetWindowHeight() * 2)));
}

Star::~Star()
{

}

void Star::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}
