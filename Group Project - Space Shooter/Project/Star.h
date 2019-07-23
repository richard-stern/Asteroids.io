#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Application.h"

class Star : public GameObject
{

public:

	Star();
	~Star();

	void Update(float deltaTime);

private:
	Application* m_pApplication;
	TextureManager* m_pTextureManager;
	Texture* m_pStarNormal;
	Texture* m_pStarUp;
	Texture* m_pStarSide;
	float f_timer;
};
