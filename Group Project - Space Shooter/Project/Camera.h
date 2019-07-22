/*-----------------------------------------------------------------------------
Aurthur:		Connor Young
Destription:	Camera controls, sets and gets location
				of camera using multiple methods 
				gets the size of the game window 
				using multiple methods 

Usage:			Create and instance of the class 
				then you will be able to call all the functions 
-------------------------------------------------------------------------------*/

#pragma once
#include "RenderManager.h"
#include "Application.h"
#include "Vector2.h"

//Camera Singleton
class Camera
{
public:
	//Returns instance of camera controls 
	static Camera *Instance()	{ return m_pInstance; }
	static Camera* m_pInstance; 

	//Will only create one instance of the camera 
	static void Create(int nWindowWidth, int nWidndowHeight) { m_pInstance = new Camera(nWindowWidth, nWidndowHeight); }

	//Destroys camera instance 
	static void Destroy() { delete m_pInstance; }

	//Set camera position using Vector2
	void SetPosition(Vector2 v2Pos);

	//Set camera position using x & y floats 
	void SetPosition(float fX, float fY);

	//Returns the camera position as a Vector2
	Vector2 GetPosition();

	//Get the game window Width as an int
	int GetWindowWidth() { return m_nWindowWidth; }

	//Get the game window Height as an int 
	int GetWindowHeight() { return m_nWindowHeight; }

	//Get the game window size as a Vector2
	Vector2 GetWindowSize(); 



private:
	//Constructor requires application pointer
	Camera(int nWindowWidth, int nWidndowHeight);
	
	//Destructor
	~Camera(); 

	//Renderer instance to get components 
	RenderManager* m_pRenderer; 

	//Game window dimensions 
	int m_nWindowHeight;
	int m_nWindowWidth; 
};

