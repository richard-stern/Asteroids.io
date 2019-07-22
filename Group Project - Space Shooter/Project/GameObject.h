#pragma once
#include "../DataStructuresLib/List.h"
#include "RenderManager.h"
#include "Texture.h"
#include "Matrix3.h"
#include "Collider.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw();

	//------------------------------------------------------------
	// This is called by the collision manager when this gameObject
	// collides with other collidable gameObjects.
	// 'other' parameter is the gameObject that is colliding with
	// this one. 
	//------------------------------------------------------------
	virtual void OnCollision(GameObject* other);

	void UpdateGlobalTransform();

	void SetPosition(Vector2 pos);
	void SetPosition(float x, float y);
	void SetRotation(float radians);
	void SetScale(Vector2 scale);
	void SetVisible(bool visible);
	void SetWrapAndRespawn(bool value);
	void SetVelocity(Vector2 velocity);
	void SetDrag(float drag);

	//------------------------------------------------------------
	// 'translation' parameter is the delta amount that the 
	// gameObject should be moved.
	// If you need to set the absolute position of the gameObject,
	// use SetPosition() instead.
	//------------------------------------------------------------
	void Translate(Vector2 translation);

	//------------------------------------------------------------
	// 'radians' parameter is the delta amount that the 
	// gameObject should be rotated.
	// If you need to set the absolute rotation of the gameObject,
	// use SetRotation() instead.
	//------------------------------------------------------------
	void Rotate(float radians);

	void SetParent(GameObject* parent);
	void AddChild(GameObject* child);

	Vector2 GetPosition();
	float GetRotation();
	Vector2 GetScale();
	GameObject* GetParent();
	Collider* GetCollider() { return _collider; }
	bool GetVisible() { return _visible; }
	bool GetWrapAndRespawn() { return _wrapAndRespawn; }
	Vector2 GetVelocity() { return _velocity; }
	float GetDrag() { return _drag; }

protected:
	GameObject* _parent;
	List<GameObject*> _childList;

	Matrix3 _localTransform;
	Matrix3 _globalTransform;

	Texture* _texture;

	Collider* _collider;

	bool _visible;
	bool _wrapAndRespawn;
	Vector2 _velocity;
	float _drag;
};

