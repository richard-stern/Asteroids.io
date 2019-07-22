#pragma once
#include "RenderManager.h"
#include "MenuState.h"
#include "GameState.h"
#include "GameOverState.h"

enum EState;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float deltatime);
	void Draw(RenderManager* renderer);

	void ChangeState(EState currentstate);

	enum EState
	{
		ESTATE_MENU,
		ESTATE_GAME,
		ESTATE_GAMEOVER
	};

protected:
	EState m_CurrentState;

	MenuState* m_pMenuState;
	GameState* m_pGameState;
	GameOverState* m_pGameOverState;
};

