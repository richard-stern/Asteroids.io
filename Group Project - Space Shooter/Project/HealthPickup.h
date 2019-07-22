#pragma once

class Actor;
class Player;
class Rock;
class Enemy;
class Bullet;

class HealthPickup : public Actor
{
public:
	// Constructor.
	HealthPickup();

	// Destructor.
	~HealthPickup();

	// On collision with the player.
	// Params: the player.
	void OnCollision(Player* player);

	// On collision with a rock.
	// Params: the rock.
	void OnCollision(Rock* rock);

	// On collision with an enemy.
	// Params: the enemey.
	void OnCollision(Enemy* enemy);

	// On collision with a bullet.
	// Params: the bullet.
	void OnCollision(Bullet* bullet);

private:
	// Bounce the health pickup.
	void Bounce();
};