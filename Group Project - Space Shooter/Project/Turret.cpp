#include "Turret.h"
#include "Input.h"
#include "Vector2.h"
#include "Matrix3.h"

Turret::Turret()
{
	m_pTexture = TextureManager.LoadTexture("./Images/turret.png");
	m_bWrapAndRespawn = false;
}

Turret::~Turret()
{
}

void Turret::Update(float deltaTime)
{
	// Call the actor's default update function,
	// for the internal matricies to be done.
	Actor::Update(deltaTime);

	// Get the input.
	Input* input = input->Instance();

	// The position of the mouse.
	Vector2 mousePos;
	mousePos.x = input->GetMouseX();
	mousePos.y = input->GetMouseY();

	// The direction of where the mouse is.
	Vector2 direction = mousePos - m_m3LocalMatrix[6];
	direction.normalise();

	// Set the rotation of the turret's matrix.
	m_m3LocalMatrix.SetRotateZ(direction);

	// If the left mouse button was pressed -> shoot a bullet.
	if (input->WasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
		m_pBulletManager->ShootBullet(m_m3LocalMatrix[6], direction);
}