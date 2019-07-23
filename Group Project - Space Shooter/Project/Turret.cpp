#include "Turret.h"
#include "Actor.h"
#include "Input.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "TextureManager.h"

Turret::Turret(Vector2 pos) : Actor(pos)
{
	SetPosition(pos);
	// Ask the texture manager to load the turret texture for the turret.
	TextureManager* textMan = textMan->Instance();
	m_pTexture = textMan->LoadTexture("turret.png");

	// Create the bullet manager.
	m_pBulletManager = new BulletManager();
}

Turret::~Turret()
{
	//  Delete the bullet manager.
	delete m_pBulletManager;
	m_pBulletManager = nullptr;
}

void Turret::Update(float deltaTime)
{
	// Call the actor's default update function,
	// for the internal matricies to be done.
	Actor::Update(deltaTime);

	// Get the input.
	Input* input = input->Instance();

	// The position of the mouse as a Vector3.
	Vector3 mousePos;
	mousePos.x = (float)input->GetMouseX();
	mousePos.y = (float)input->GetMouseY();

	// The position of the turret as a Vector3.
	Vector3 v3Position;
	v3Position = m_m3LocalTransform[6];

	// The direction of where the mouse is.
	Vector3 v3Forward = mousePos - v3Position;
	v3Forward.normalise();

	// The foward direction of the turret as a Vector2.
	Vector2 v2Foward;
	v2Foward.x = v3Forward.x;
	v2Foward.y = v3Forward.y;
	
	// Set the rotation of the turret's matrix.
	m_m3LocalTransform.setRotateZ(v2Foward);

	// If the left mouse button was pressed -> shoot a bullet.
	if (input->WasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
	{	
		// The position of the turret as a Vector2.
		Vector2 v2Position;
		v2Position.x = v3Position.x;
		v2Position.y = v3Position.y;

		// Call the shoot bullet function of the bullet manager.
		m_pBulletManager->ShootBullet(v2Position, v2Foward);
	}
}