#include "StateMachine.h"
#include "RenderManager.h"
#include "MenuState.h"
#include "GameState.h"
#include "GameOverState.h"


StateMachine::StateMachine()
{
	m_pMenuState = new MenuState();
	m_pGameState = new GameState();
	m_pGameOverState = new GameOverState();
	//This changed the current state to menu estate
	m_CurrentState = ESTATE_MENU;
}

StateMachine::~StateMachine()
{
	delete m_pMenuState;
	delete m_pGameState;
	delete m_pGameOverState;
}

void StateMachine::Update(float deltatime)
{
	//This changes between the 3 states
	switch (m_CurrentState)
	{
	case ESTATE_MENU:
		m_pGameState->Update(deltatime, this);
		break;
	case ESTATE_GAME:
		m_pGameOverState->Update(deltatime, this);
		break;
	case ESTATE_GAMEOVER:
		m_pMenuState->Update(deltatime, this);
		break;
	}
}

void StateMachine::Draw(RenderManager* rendermanager)
{
	switch (m_CurrentState)
	{
	case ESTATE_MENU:
		m_pGameState->Draw(rendermanager);
		break;
	case ESTATE_GAME:
		m_pGameOverState->Draw(rendermanager);
		break;
	case ESTATE_GAMEOVER:
		m_pMenuState->Draw(rendermanager);
		break;
	}
}

void StateMachine::ChangeState(EState currentstate)
{
	switch (m_CurrentState)
	{
	case ESTATE_MENU:
		m_pMenuState->Enter();
		break;
	case ESTATE_GAME:
		m_pGameState->Enter();
		break;
	case ESTATE_GAMEOVER:
		m_pGameOverState->Enter();
		break;
	}

	m_CurrentState = currentstate;

	switch (m_CurrentState)
	{
	case ESTATE_MENU:
		m_pMenuState->Exit();
		break;
	case ESTATE_GAME:
		m_pGameState->Exit();
		break;
	case ESTATE_GAMEOVER:
		m_pGameOverState->Exit();
		break;
	}
}
