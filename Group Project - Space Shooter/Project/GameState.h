#pragma once
#include "RenderManager.h"

#include "BaseState.h"
#include "Level.h"
#include "GUI.h"
class GameState : public BaseState //change when find out what basestate name is
{
public:
	GameState();
	virtual ~GameState();

	void Enter();
	void Exit();

	virtual bool Update(float deltaTime, StateMachine* stateMachine);
	virtual void Draw(RenderManager *renderManager);

private:
	Level* level;
	GUI* gui;
};