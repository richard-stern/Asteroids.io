#include "Player.h"
#include "TextureManager.h"
#include "Input.h"
#include "Camera.h"
#include "GUI.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "BoxCollider.h"

Player::Player(Vector2 v2Position) : Actor(v2Position)
{
	SetPosition(v2Position);
	TextureManager* pTextureManager = TextureManager::Instance();
	m_pTexture = pTextureManager->LoadTexture("player.png");
	m_bWrapAndRespawn = false;
	m_fSpeed = 100;
	m_nHealth = 100;
	m_nLives = 3;
	m_eType = GameObjectType::PLAYER;
	m_v2PreviousPosition = v2Position;
	m_pTurret = new Turret();
	m_pTurret->SetParent(this);

	//Create a varible for the collider, by getting pointer the texture manager, and return the player texture, and ask for its width 
	//and divide it by 2. Then set that as the extend in the Box Collider
	Vector2 v2Extend = Vector2((float)((m_pTexture->GetWidth()) / 2), (float)((m_pTexture->GetHeight()) / 2));
	m_pCollider = new BoxCollider(v2Extend, ELayer::ECOLLISIONLAYER_PLAYER);

	CollisionManager::GetInstance()->AddObject(this);
}


Player::~Player()
{
}


float Player::GetSpeed()
{
	return m_fSpeed;
}

int Player::GetLives()
{
	return m_nLives;
}

void Player::SetSpeed(float fSpeed)
{
	m_fSpeed = fSpeed;
}

void Player::SetLives(int nLives)
{
	m_nLives = nLives;
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

	}
	if (pInput->IsKeyDown(INPUT_KEY_S))
	{
		Vector2 v2Direction = m_m3LocalTransform.forward();

		// A = v / t    Apply acceleration
		m_v2Velocity -= v2Direction * m_fSpeed * fDeltaTime;

	}
	if (pInput->IsKeyDown(INPUT_KEY_A))
	{
		//Add Rotation
		SetRotation(GetRotation() - 5 * fDeltaTime);
	}
	if (pInput->IsKeyDown(INPUT_KEY_D))
	{
		//Rotation
		SetRotation(GetRotation() + 5 * fDeltaTime);
	}
	// v = d / t    Apply Velocity
	SetPosition(GetPosition() + (m_v2Velocity * fDeltaTime));
	//Set the camera to the player's position
	Camera* pCamera = Camera::Instance();
	pCamera->SetPosition( Vector2((GetPosition().x - pCamera->GetWindowWidth() / 2), GetPosition().y - (pCamera->GetWindowHeight() / 2)) );


	//Set the GUI
	GUI* pGUI = GUI::Instance();
	pGUI->SetHealth(m_nHealth);
	pGUI->SetLives(m_nLives);
	

}

void Player::OnCollision(GameObject* pOtherObject)
{
	
 	if (pOtherObject->GetType() == GameObjectType::ROCK) //If colliding with a Rock
	{
		//Seperate from object
		SetPosition(m_v2PreviousPosition);
		//Reverse the velocity
		m_v2Velocity = Vector2(-m_v2Velocity.x, -m_v2Velocity.y);
	}
	if (pOtherObject->GetType() == GameObjectType::BULLET) //If colliding with a Bullet
	{
		//Decrease Health
		m_nHealth -= 25;
	}
	if (pOtherObject->GetType() == GameObjectType::ENEMY) //If colliding with a Enemy
	{
		//Seperate from object
		SetPosition(m_v2PreviousPosition);
		//Reverse the velocity
		m_v2Velocity = Vector2(-m_v2Velocity.x, -m_v2Velocity.y);



	}
	if (pOtherObject->GetType() == GameObjectType::HEALTH_PICKUP) //If colliding with a HealthPickup
	{
		//Increase Health
		m_nHealth += 25;
	}
	if (pOtherObject->GetType() == GameObjectType::GENERIC) //If colliding with a Generic object
	{
		SetPosition(m_v2PreviousPosition);
		//Reverse the velocity
		m_v2Velocity = Vector2(-m_v2Velocity.x, -m_v2Velocity.y);


	}




}

