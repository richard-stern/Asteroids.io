#include "Game.h"
#include <crtdbg.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	//Check for most forms of memory leaks.
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	srand((unsigned int)time(nullptr));

	//Create game window.
	Game *pGame = new Game(1024, 768, false, "Game");

	//Begin the game loop.
	pGame->RunGame();

	//Shut everything down.
	delete pGame;
};