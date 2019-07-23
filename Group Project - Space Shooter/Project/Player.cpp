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
	m_eType = GameObjectType::Player;
	m_v2PreviousPosition = v2Position;
}


Player::~Player()
{
}

void Player::Update(float fDeltaTime) 
{
	Actor::Update(fDeltaTime);//Call Actor Update Function
	Input* pInput = Input::Instance(); //Get instance of input class


	m_v2PreviousPosition = GetPosition();

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
	//Set the camera to the player's position
	Camera* pCamera = Camera::Instance();
	pCamera->SetPosition( Vector2((GetPosition().x + pCamera->GetWindowWidth() / 2), GetPosition().y + (pCamera->GetWindowHeight() / 2)) );


	//Set the GUI
	GUI* pGUI = GUI::Instance();
	pGUI->SetHealth(m_fHealth);
	pGUI->SetLives(m_nLives);
	

}

void Player::OnCollision(GameObject* pOtherObject)
{
	
	if (pOtherObject->GetType() == GameObjectType::Rock) //If colliding with a Rock
	{
		//Seperate from object
		SetPosition(m_v2PreviousPosition);
		//Reverse the velocity
		m_v2Velocity = Vector2(-m_v2Velocity.x, -m_v2Velocity.y);
	}
	if (pOtherObject->GetType() == GameObjectType::Bullet) //If colliding with a Bullet
	{
		//Decrease Health
		m_fHealth -= 25.0f;
	}
	if (pOtherObject->GetType() == GameObjectType::Enemy) //If colliding with a Enemy
	{
		//Seperate from object
		SetPosition(m_v2PreviousPosition);
		//Reverse the velocity
		m_v2Velocity = Vector2(-m_v2Velocity.x, -m_v2Velocity.y);



	}
	if (pOtherObject->GetType() == GameObjectType::HealthPickup) //If colliding with a HealthPickup
	{
		//Increase Health
		m_fHealth += 25;
	}
	if (pOtherObject->GetType() == GameObjectType::Generic) //If colliding with a Generic object
	{
		SetPosition(m_v2PreviousPosition);
		//Reverse the velocity
		m_v2Velocity = Vector2(-m_v2Velocity.x, -m_v2Velocity.y);


	}




}

