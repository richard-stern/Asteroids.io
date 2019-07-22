#pragma once
#include "BaseState.h"

/*
	Menu State Class

	Made by Thomas
*/

class MenuState : public BaseState {
public:
	MenuState();
	~MenuState();

	void Enter();
	void Update(float deltaTime, StateMachine* p_StateMachine);
	void Draw(RenderManager* pRenderManager);
	void Exit();

private:
	StateMachine* m_pStateMachine;
	Button* m_PlayButton;
	Button* m_QuitButton;
	Font* m_Font;
	Application* m_App;
};

