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
	GameObject(const char* textureName);
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void OnCollision(GameObject* other);

	void UpdateGlobalTransform();

	void SetPosition(Vector2 pos);
	void SetPosition(float x, float y);
	void SetRotation(float radians);
	void SetScale(Vector2 scale);
	void SetVelocity(Vector2 velocity);
	void SetDrag(float drag);

	void Translate(Vector2 translation);
	void Rotate(float radians);

	void SetParent(GameObject* parent);
	void AddChild(GameObject* child);

	Vector2 GetPosition();
	float GetRotation();
	Vector2 GetScale();
	GameObject* GetParent();
	Collider* GetCollider() { return _collider; }

	Vector2 GetVelocity() { return _velocity; }
	float GetDrag() { return _drag; }

protected:
	GameObject* _parent;
	List<GameObject*> _childList;

	Matrix3 _localTransform;
	Matrix3 _globalTransform;

	Texture* _texture;

	Collider* _collider;

	Vector2 _velocity;
	float _drag;
};

