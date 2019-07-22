// created: 22/07/2019
// Leanne Vosrter
#pragma once
#include "RenderManager.h"
#include "Button.h"
class StateMachine;
class BaseState
{
public:
	BaseState() {};
	 virtual ~BaseState() {};
	 virtual void Enter() {};
	 virtual void Update(float deltaTime, StateMachine* p_StateMachine)
	 {
		 m_pStateMachine = p_StateMachine;
	 };
	 virtual void Draw(RenderManager* pRenderManager) {};
	 virtual void Exit() {};
private:
	StateMachine* m_pStateMachine;
};

