#include "Enemy.h"

//Enemy constructor, takes a texture from the texture manager.
//Inherits from Actor class and calls it's GetPosition() function.
Enemy::Enemy(Player* pPlayer) : Actor(Vector2(rand() % 1000, rand() % 1000))
{
	//Allow the enemy to respawn after death and to wrap around the window when going offscreen.
	SetWrapAndRespawn(true);
	//The enemies will start as invisible because they start offscreen.
	SetVisible(false);

	//Locating the texture file for the Enemy sprite. 
	m_pTexture = TextureManager::Instance()->LoadTexture("Enemy.png");

	//Sets the health of the enemy.
	//Referencing "Bullet.h", BULLET_DAMAGE = 50, making each enemy takes two hits to kill.
	GUI::Instance()->SetHealth(100);

	//store pointers
	m_pPlayer = pPlayer;
}

//Destructor.
Enemy::~Enemy()
{
}

//Enemy's collision detection
void Enemy::OnCollision(Player* pPlayer)
{
	//Sets the health of the enemy to 0.
	GUI::Instance()->SetHealth(0);

	//Make it invisible.
	SetVisible(false);
}

//Enemy's collision with the bullet
void Enemy::OnCollision(Bullet* pBullet)
{
	//Take 50 HP off the enemy.
	GUI::Instance()->SetHealth(m_nHealth - 50);

	//Checks if the enemy has no health remaining.
	if (m_nHealth <= 0)
	{
		//Make the enemy invisible.
		SetVisible(false);

		//Add 10 points. to the player's score
		GUI::Instance()->AddScore(10);
	}
}

//Update function is used for steering behaviours.
void Enemy::Update(float deltaTime)
{
	//Vectors used to track the positions of the enemy and player.
	Vector2 v2PlayerPos = m_pPlayer->GetPosition();
	Vector2 v2EnemyPos = this->GetPosition();

	//Seeking function.
	if ((v2PlayerPos - v2EnemyPos).magnitude() < 1000)
	{
		
	}
}