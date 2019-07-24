#include "GameState.h"
#include "StateMachine.h"
class GameState;

GameState::GameState()
{
	level = nullptr;
	gui = nullptr;
}

GameState::~GameState()
{
	if (level)
	{

	delete level;
	level = nullptr;
	}
	if (gui)
	{
		delete gui;
		gui = nullptr;
	}
}

void GameState::Enter()
{
	level = new Level(5, 100, 2, 2);
	gui = GUI::Instance();
}
void GameState::Exit()
{
	delete level;
	level = nullptr;

	delete gui;
	gui = nullptr;
}

bool GameState::Update(float deltaTime, StateMachine* stateMachine)
{
	Input* pInput = Input::Instance();
	level->Update(deltaTime);
	level->UpdateGlobalTransform();
	Player* player = level->GetPlayer();
	if (player->GetHealth() <= 0 || pInput->IsKeyDown(INPUT_KEY_ESCAPE))
	{
		stateMachine->ChangeState(ESTATE_GAMEOVER);
	}
	return false;
}
void GameState::Draw(RenderManager* renderManager)
{
	level->Draw(renderManager);
	gui->Draw(renderManager);
}