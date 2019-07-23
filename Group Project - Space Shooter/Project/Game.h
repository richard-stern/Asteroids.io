#pragma once

#include "Application.h"




class StateMachine;
class TextureManager;

class Game : public Application
{
public:
	Game(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);
	~Game();

	void Update(float deltaTime);
	void Draw();

private:
	StateMachine* m_pStateMachine;
	
};
