#include "GameState.h"

class GameState;

GameState::GameState()
{

}

GameState::~GameState()
{
	delete level;
	level = nullptr;

	delete gui;
	gui = nullptr;
}

void GameState::Enter()
{
	level = new Level();
	gui = new GUI();
}
void GameState::Exit()
{
	delete level;
	level = nullptr;

	delete gui;
	gui = nullptr;
}

void GameState::Update(float deltaTime, StateMachine* stateMachine)
{
	level->Update(deltaTime);
	Player* player = level->GetPlayer();
	if (player->GetHealth() <= 0)
	{
		stateMachine->ChangeState(ESTATE_GAMEOVER);
	}
}
void GameState::Draw(RenderManager* renderManager)
{
	level->Draw(renderManager);
	gui->Draw(renderManager);
}