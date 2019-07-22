#include "MenuState.h"

MenuState::MenuState() {

}


MenuState::~MenuState() {

}

void MenuState::Enter() {

}

void MenuState::Update(float deltaTime, StateMachine* p_StateMachine) {
	m_pStateMachine = p_StateMachine;
}

void MenuState::Draw(RenderManager* pRenderManager) {

}

void MenuState::Exit() {

}
