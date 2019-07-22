#include "Rock.h"
#include "TextureManager.h"
#include <random>
#include "Actor.h"

Rock::Rock() : Actor(Vector2(rand(), rand()))
{
	TextureManager* textMan;
	textMan->Instance();

	int randRock = rand() % 3;

	switch (randRock)
	{
	case 0:
		m_pTexture = textMan->LoadTexture("rock_small.png");
		m_nHealth = ;
	case 1:
		m_pTexutre = textMan->LoadTexture("rock_medium.png");
		m_nHealth = ;
	case 2:
		m_pTexture = textMan->LoadTexture("rock_large.png");
		m_nHealth = ;
	}
}

Rock::~Rock()
{
}