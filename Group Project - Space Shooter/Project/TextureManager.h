#pragma once
#include "Texture.h"
#include "List.h"


class TextureManager
{
	//Private Constructor and Destructor for singleton pattern
	TextureManager();
	~TextureManager();


	struct Pair //Pairs the Texture along with its path. Easier to search for the texture this way
	{
		Texture* m_pTexture;
		const char* m_szPath;

		//Constructor and Destructor
		Pair(Texture* pTexture, const char* szPath);
		~Pair();
	};

public:
	//Functions

	//---------------------------------------------
	//LoadTexture
	//Passes in the name of the texture (No need to put full path in). Searches the list for the path passed in and loads the one needed, and creating it if not found
	//---------------------------------------------
	Texture* LoadTexture(const char* szTextureName);


	//Singleton stuff

	//---------------------------------------------
	//Instance()
	//Returns a reference to the texture manager
	//---------------------------------------------
	static TextureManager* Instance();

	static void Create();
	static void Destroy();

	//Variables

	List<Pair*> m_Textures;

	//Singleton created
	static TextureManager* m_pTextureManager;
};

