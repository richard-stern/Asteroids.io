#include "Player.h"
#include "TextureManager.h"
#include "Input.h"
#include "Camera.h"
#include "GUI.h"

Player::Player(Vector2 v2Position) : Actor(v2Position)
{
	SetPosition(v2Position);
	TextureManager* pTextureManager = TextureManager::Instance();
	m_pTexture = pTextureManager->LoadTexture("player.png");
	m_bWrapAndRespawn = false;
	m_fSpeed = 0;
	m_fHealth = 100;
	m_nLives = 3;

}


Player::~Player()
{
}

void Player::Update(float fDeltaTime) 
{
	Actor::Update(fDeltaTime);//Call Actor Update Function
	Input* pInput = Input::Instance(); //Get instance of input class
	if (pInput->IsKeyDown(INPUT_KEY_W))
	{
		Vector2 v2Direction = m_m3LocalTransform.forward();

		// A = v / t    Apply acceleration
		m_v2Velocity += v2Direction * m_fSpeed * fDeltaTime;

		// v = d / t    Apply Velocity
		SetPosition((GetPosition() + m_v2Velocity) * fDeltaTime);
	}
	if (pInput->IsKeyDown(INPUT_KEY_S))
	{
		Vector2 v2Direction = m_m3LocalTransform.forward();

		// A = v / t    Apply acceleration
		m_v2Velocity -= v2Direction * m_fSpeed * fDeltaTime;

		// v = d / t    Apply Velocity
		SetPosition((GetPosition() + m_v2Velocity) * fDeltaTime);
	}
	if (pInput->IsKeyDown(INPUT_KEY_A))
	{
		//Add Rotation
		SetRotation(GetRotation() + 1);
	}
	if (pInput->IsKeyDown(INPUT_KEY_D))
	{
		//Rotation
		SetRotation(GetRotation() - 1);
	}

	Camera* pCamera = Camera::Instance();
	pCamera->SetPosition(GetPosition());

	GUI* pGUI = GUI::Instance();
	pGUI->SetHealth(m_fHealth);
	pGUI->SetLives(m_nLives);
	

}

void Player::OnCollision(GameObject* pOtherObject)
{
	


}

