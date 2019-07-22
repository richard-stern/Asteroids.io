#pragma once
#include "GameObject.h"
#include "TextureManager.h"
class Star : public GameObject
{

public:
	Star();
	~Star();

private:
	TextureManager* m_pTextureManager;
};
