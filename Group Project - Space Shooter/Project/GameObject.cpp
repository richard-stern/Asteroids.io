#include "GameObject.h"
#include <string>
#include "Camera.h"
GameObject::GameObject()
{
	m_pCamera = Camera::Instance();
	m_v2ScreenSize = m_pCamera->GetWindowSize();
	m_pTexture = nullptr;
	m_pParent = nullptr;
}

GameObject::~GameObject()
{
	for (int i = 0; i < m_apChildList.Count(); i++)
		if (m_apChildList[i])
			delete m_apChildList[i];
}

void GameObject::Update(float deltaTime)
{
	for (int i = 0; i < m_apChildList.Count(); i++)
		m_apChildList[i]->Update(deltaTime);

	if (m_m3LocalTransform.getPosition().x > Camera::Instance()->GetWindowWidth())
	{
		m_m3LocalTransform.setPosition(Vector2(0, m_m3LocalTransform.getPosition().y));
	}
	else if (m_m3LocalTransform.getPosition().y > Camera::Instance()->GetWindowHeight())
	{
		m_m3LocalTransform.setPosition(Vector2(m_m3LocalTransform.getPosition().x, 0));
	}
	else if (m_m3LocalTransform.getPosition().x < 0)
	{
		m_m3LocalTransform.setPosition(Vector2(Camera::Instance()->GetWindowWidth(), m_m3LocalTransform.getPosition().y));
	}
	else if (m_m3LocalTransform.getPosition().y < 0)
	{
		m_m3LocalTransform.setPosition(Vector2(m_m3LocalTransform.getPosition().x, Camera::Instance()->GetWindowHeight()));
	}
}

void GameObject::Draw(RenderManager* renderer)
{
	screenWrap();

	if (m_pTexture)
		renderer->DrawSpriteTransformed3x3(m_pTexture, m_m3GlobalTransform);

	for (int i = 0; i < m_apChildList.Count(); i++)
		m_apChildList[i]->Draw(renderer);
}

void GameObject::UpdateGlobalTransform()
{
	if (m_pParent)
		m_m3GlobalTransform = m_pParent->m_m3GlobalTransform * m_m3LocalTransform;
	else
		m_m3GlobalTransform = m_m3LocalTransform;

	for (int i = 0; i < m_apChildList.Count(); i++)
		m_apChildList[i]->UpdateGlobalTransform();
}

void GameObject::SetPosition(Vector2 pos)
{
	m_m3LocalTransform.setPosition(pos);
}

void GameObject::SetPosition(float x, float y)
{
	m_m3LocalTransform.setPosition(x, y);
}

void GameObject::SetRotation(float radians)
{
	m_m3LocalTransform.setRotateZ(radians);
}

void GameObject::SetRotation(Vector2 direction)
{
	m_m3LocalTransform.setRotateZ(direction);
}

void GameObject::SetScale(Vector2 scale)
{
	m_m3LocalTransform.setScale(scale);
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
	m_pParent = parent;
	parent->AddChild(this);
}

void GameObject::AddChild(GameObject * child)
{
	m_apChildList.PushBack(child);
}

Vector2 GameObject::GetPosition()
{
	return m_m3LocalTransform.getPosition();
}

float GameObject::GetRotation()
{
	return m_m3LocalTransform.getRotation();
}

Vector2 GameObject::GetScale()
{
	return Vector2();
}

GameObject * GameObject::GetParent()
{
	return m_pParent;
}

void GameObject::screenWrap()
{
	Vector2 myPosition = GetPosition();
	Vector2 cameraPosition = m_pCamera->GetPosition();

	if (myPosition.x < cameraPosition.x)
		SetPosition(Vector2(cameraPosition.x + m_v2ScreenSize.x, myPosition.y));

	if(myPosition.x > (cameraPosition.x + m_v2ScreenSize.x))
		SetPosition(Vector2(cameraPosition.x, myPosition.y));

	if (myPosition.y < cameraPosition.y)
		SetPosition(Vector2(myPosition.x, cameraPosition.y + m_v2ScreenSize.y));

	if (myPosition.y > (cameraPosition.y + m_v2ScreenSize.y))
		SetPosition(Vector2(myPosition.x, cameraPosition.y));
}
