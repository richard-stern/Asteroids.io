#include "Star.h"

Star::Star()
{
	m_pTextureManager = m_pTextureManager->Instance();
	m_bWrapAndRespawn = true;
	m_pTexture = m_pTextureManager->LoadTexture("star.png");


	SetPosition(Vector2(float(rand() % 1000), float(rand() % 1000)));

}

Star::~Star()
{

}
