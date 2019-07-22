#include "Star.h"

Star::Star()
{
	m_pTextureManager = TextureManager::Instance();
	m_bWrapAndRespawn = true;
	m_pTexture = m_pTextureManager->LoadTexture("star.png");


	SetPosition(Vector2(rand() % 1000, rand() % 1000));

}

Star::~Star()
{

}
