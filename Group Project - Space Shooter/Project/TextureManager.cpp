#include "TextureManager.h"
#include <iostream>
//Declare Singleton
//---------------------------------------
TextureManager* TextureManager::m_pTextureManager = nullptr;
//----------------------------------------



TextureManager::Pair::Pair(Texture* pTexture, const char* szPath)
{
	m_pTexture = pTexture;
	m_szPath = szPath;
}

TextureManager::Pair::~Pair()
{
	delete m_pTexture;
}


Texture* TextureManager::LoadTexture(const char* szTextureName)
{
	const char* szPath = ("./textures/" + std::string(szTextureName)).c_str();
	for (int i = 0; i < m_Textures.Count();i++)//For every texture in the list
	{
		if (szPath == m_Textures[i]->m_szPath)//If found the path
		{
			return m_Textures[i]->m_pTexture;//Then return the texture its paired with
		}
	}
	//Else if loop is exited, then it is not found

	m_Textures.PushBack(new Pair(new Texture(szPath), szPath) ); //Create a new pair, as well as the texture and assign its path
	return m_Textures.Last()->m_pTexture;//Return the last texture, that was just created
}

TextureManager* TextureManager::Instance()
{
	return m_pTextureManager;
}

void TextureManager::Create()
{
	m_pTextureManager = new TextureManager();

}

void TextureManager::Destroy()
{
	delete m_pTextureManager;
}

TextureManager::TextureManager()
{
	
}


TextureManager::~TextureManager()
{
	for (int i = 0; i < m_Textures.Count(); i++)
	{
		delete m_Textures[i];//Delete each texture that was created
	}

}

