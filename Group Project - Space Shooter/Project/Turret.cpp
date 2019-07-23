#include "Turret.h"
#include "Actor.h"
#include "Input.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "TextureManager.h"

Turret::Turret() : Actor(Vector2(0,0))
{
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
	// Update the turret's global position.
	UpdateGlobalTransform();

	// Call the actor's default update function,
	// for the internal matricies to be done.
	Actor::Update(deltaTime);

	// Get the input.
	Input* input = input->Instance();

	// The position of the mouse as a Vector3.
	Vector2 mousePos;
	mousePos.x = (float)input->GetMouseX();
	mousePos.y = (float)input->GetMouseY();
	
	Vector2 localPosition = m_m3GlobalTransform.getPosition();

	// The position of the turret as a Vector3.
	Vector2 v2Direction;
	v2Direction = (mousePos - localPosition).right(); // Credit to Chris for helping me with this
	
	float localRotation = atan2(v2Direction.y, v2Direction.x);

	// Get the rotation of the parent.
	float parentRotation = m_pParent->GetRotation();

	float finalRotation = parentRotation - localRotation;

	// The foward direction of the turret as a normalized Vector2.
	Vector2 v2Forward = Vector2(sin(finalRotation), cos(finalRotation));
	
	// Set the rotation of the turret's matrix.
	m_m3LocalTransform.setRotateZ(v2Forward);

	// If the left mouse button was pressed -> shoot a bullet.
	if (input->WasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
	{	
		// Call the shoot bullet function of the bullet manager.
		m_pBulletManager->ShootBullet(localPosition, v2Forward);
	}
}