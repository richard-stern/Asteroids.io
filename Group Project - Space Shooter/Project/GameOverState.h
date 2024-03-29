//created: 22/07/2019
// Leanne Vorster

#pragma once
#include "StateMachine.h"
#include "BaseState.h"
#include "Font.h"
class StateMachine;
class GameOverState : public BaseState
{
public:
	GameOverState();
	~GameOverState();
	void Enter();
	bool Update(float deltaTime, StateMachine* p_StateMachine);
	void Draw(RenderManager* pRenderManager);
	void Exit();
private:
	StateMachine* m_pStateMachine;
	Font* m_font;
	Button* m_ExitButton;
	Button* m_PlayAgainButton;
	Texture* m_Richard;
	float m_fWindowWidth;
	float m_fWindowHeight;
};




