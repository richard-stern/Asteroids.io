#include "Turret.h"
#include "Actor.h"
#include "Input.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "TextureManager.h"

Turret::Turret() : Actor(_parent->GetPosition())
{
	// Ask the texture manager to load the turret texture for the turret.
	TextureManager* textMan;
	_texture = textMan->LoadTexture("turret.png");
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

	// The position of the mouse as a Vector3.
	Vector3 mousePos;
	mousePos.x = (float)input->GetMouseX();
	mousePos.y = (float)input->GetMouseY();

	// The position of the turret as a Vector3.
	Vector3 position;
	position = _localTransform[6];

	// The direction of where the mouse is.
	Vector3 direction = mousePos - position;
	direction.normalise();

	// The foward direction of the turret as a Vector2.
	Vector2 tempFoward;
	tempFoward.x = direction.x;
	tempFoward.y = direction.y;

	// The position of the turret as a Vector2.
	Vector2 tempPos;
	tempPos.x = position.x;
	tempPos.y = position.y;

	// Set the rotation of the turret's matrix.
	_localTransform.setRotateZ(tempFoward);

	// If the left mouse button was pressed -> shoot a bullet.
	if (input->WasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
		m_pBulletManager->ShootBullet(tempPos, tempFoward);
}