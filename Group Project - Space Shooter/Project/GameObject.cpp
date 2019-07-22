#include "GameObject.h"
#include <string>

GameObject::GameObject()
{
	m_pTexture = nullptr;
	_parent = nullptr;
	m_pCollider = nullptr;
}

GameObject::~GameObject()
{
	for (int i = 0; i < _childList.Count(); i++)
		if (_childList[i])
			delete _childList[i];

	if (m_pTexture)
	{
		delete m_pTexture;
		m_pTexture = nullptr;
	}

	if (m_pCollider)
	{
		delete m_pCollider;
		m_pCollider = nullptr;
	}
}

void GameObject::Update(float deltaTime)
{
	for (int i = 0; i < _childList.Count(); i++)
		_childList[i]->Update(deltaTime);

	if (m_pCollider)
		m_pCollider->SetPosition(GetPosition());
}

void GameObject::Draw(RenderManager* renderer)
{
	if (m_pTexture)
		renderer->DrawSpriteTransformed3x3(m_pTexture, _globalTransform);

	for (int i = 0; i < _childList.Count(); i++)
		_childList[i]->Draw(renderer);
}

void GameObject::OnCollision(GameObject * other)
{
}

void GameObject::UpdateGlobalTransform()
{
	if (_parent)
		_globalTransform = _parent->_globalTransform * _localTransform;
	else
		_globalTransform = _localTransform;

	for (int i = 0; i < _childList.Count(); i++)
		_childList[i]->UpdateGlobalTransform();
}

void GameObject::SetPosition(Vector2 pos)
{
	_localTransform.setPosition(pos);
}

void GameObject::SetPosition(float x, float y)
{
	_localTransform.setPosition(x, y);
}

void GameObject::SetRotation(float radians)
{
	_localTransform.setRotateZ(radians);
}

void GameObject::SetScale(Vector2 scale)
{
	_localTransform.setScale(scale);
}

void GameObject::SetVisible(bool visible)
{
	m_bVisible = visible;
}

void GameObject::SetWrapAndRespawn(bool value)
{
	m_bWrapAndRespawn = value;
}

void GameObject::SetVelocity(Vector2 velocity)
{
	m_v2Velocity = velocity;
}

void GameObject::SetDrag(float drag)
{
	m_fDrag = drag;
}

void GameObject::Translate(Vector2 translation)
{
	Vector2 currentPos = GetPosition();
	SetPosition(currentPos.x + translation.x, currentPos.y + translation.y);
}

void GameObject::Rotate(float radians)
{
	SetRotation(GetRotation() + radians);
}

void GameObject::SetParent(GameObject * parent)
{
	_parent = parent;
	parent->AddChild(this);
}

void GameObject::AddChild(GameObject * child)
{
	_childList.PushBack(child);
}

Vector2 GameObject::GetPosition()
{
	return _localTransform.getPosition();
}

float GameObject::GetRotation()
{
	return _localTransform.getRotation();
}

Vector2 GameObject::GetScale()
{
	return Vector2();
}

GameObject * GameObject::GetParent()
{
	return _parent;
}
