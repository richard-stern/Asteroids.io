//created: 22/07/2019
// Leanne Vorster

#pragma once
#include "StateMachine.h"
#include "BaseState.h"
class GameOverState : public BaseState
{
public:
	GameOverState();
	~GameOverState();
	void Enter();
	void Update(float deltaTime, StateMachine* p_StateMachine);
	void Draw(RenderManager* pRenderManager);
	void Exit();
};




