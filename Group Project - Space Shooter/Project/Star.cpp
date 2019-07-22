#include "Star.h"

Star::Star()
{
	m_pTextureManager = TextureManager::Instance();
	m_bWrapAndRespawn = true;
	m_pTexture = m_pTextureManager->LoadTexture("star.png");
}
Star::~Star()
{

}
