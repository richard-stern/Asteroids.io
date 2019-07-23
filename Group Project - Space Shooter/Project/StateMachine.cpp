#include "StateMachine.h"
#include "RenderManager.h"
#include "MenuState.h"
#include "GameState.h"
#include "GameOverState.h"


StateMachine::StateMachine()
{
	//Creates the three states
	m_pMenuState = new MenuState();
	m_pGameState = new GameState();
	m_pGameOverState = new GameOverState();

	//Changes the current state to menu estate
	ChangeState(ESTATE_GAMEOVER);
}

StateMachine::~StateMachine()
{
	//Deletes the 3 states
	delete m_pMenuState;
	delete m_pGameState;
	delete m_pGameOverState;
}

bool StateMachine::Update(float deltatime)
{
	//Updates the appropriate states
	switch (m_CurrentState)
	{
	case ESTATE_MENU:
		return m_pMenuState->Update(deltatime, this);
		break;
	case ESTATE_GAME:
		return m_pGameState->Update(deltatime, this);
		break;
	case ESTATE_GAMEOVER:
		return m_pGameOverState->Update(deltatime, this);
		break;
	}
}

void StateMachine::Draw(RenderManager* rendermanager)
{
	//draws the appropriate states
	switch (m_CurrentState)
	{
	case ESTATE_MENU:
		m_pMenuState->Draw(rendermanager);
		break;
	case ESTATE_GAME:
		m_pGameState->Draw(rendermanager);
		break;
	case ESTATE_GAMEOVER:
		m_pGameOverState->Draw(rendermanager);
		break;
	}
}

void StateMachine::ChangeState(EState currentstate)
{
	//chooses the appropriate state to exit
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

	//assign the m_CurrentState to currrentstate
	m_CurrentState = currentstate;

	//chooses the appropriate state to enter
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
}
