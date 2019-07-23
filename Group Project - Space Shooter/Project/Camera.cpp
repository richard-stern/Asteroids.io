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
	m_pRenderer->SetCameraPos(v2Pos.x - CAMERA_OFFSET, v2Pos.y + CAMERA_OFFSET);
}

void Camera::SetPosition(float fX, float fY)
{
	m_pRenderer->SetCameraPos(fX - CAMERA_OFFSET, fY + CAMERA_OFFSET);
}

Vector2 Camera::GetPosition()
{
	Vector2 v2Temp; 
	m_pRenderer->GetCameraPos(&v2Temp.x, &v2Temp.y);

	return v2Temp;
}

Vector2 Camera::GetWindowSize()
{
	Vector2 v2Temp;

	v2Temp.x = GetWindowWidth();
	v2Temp.y = GetWindowHeight();

	return v2Temp; 
}

