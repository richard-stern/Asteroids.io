#pragma once
#include "RenderManager.h"
#include "Font.h"
#include "Input.h"

/*		Button Class
		
		Made by Thomas
*/

#define TEXT_WIDTH 10
#define TEXT_HEIGHT 10
#define BUFFER_SIZE 64


class Button
{
public:
	Button(const char* buttonText, float x, float y, float width, float height, int r, int g, int b, int a);
	~Button();

	void Draw(RenderManager* renderer, float width, float height);
	bool Update();

private:
	// font and text
	Font* m_font;
	char m_buttonText[BUFFER_SIZE];

	// position, width and height
	float m_fPosX;
	float m_fPosY;
	float m_fWidth;
	float m_fHeight;
	int m_nColourRed;
	int m_nColourGreen;
	int m_nColourBlue;
	int m_nAlpha;
};