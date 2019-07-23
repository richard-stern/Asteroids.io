#include "Camera.h"

//Decalre singleton variable 
Camera * Camera::m_pInstance = nullptr; 

Camera::Camera(int nWindowWidth, int nWindowHeight)
{
	m_pRenderer = RenderManager::Instance();
	
	m_nWindowHeight = nWindowWidth;
	m_nWindowWidth = nWindowHeight;
}

Camera::~Camera()
{
}

void Camera::SetPosition(Vector2 v2Pos)
{
	m_pRenderer->SetCameraPos(v2Pos.x, v2Pos.y); 
}

void Camera::SetPosition(float fX, float fY)
{
	m_pRenderer->SetCameraPos(fX, fY);
}

Vector2 Camera::GetPosition()
{
	Vector2 v2Temp; 
	m_pRenderer->GetCameraPos(&v2Temp.x, &v2Temp.y);

	return v2Temp;
}



