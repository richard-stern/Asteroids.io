#include "Button.h"
#include <string.h>



Button::Button(const char* buttonText, float x, float y, float width, float height, int r, int g, int b, int a)
{
	//stores copy of the text
	strcpy_s(m_buttonText, BUFFER_SIZE, buttonText);

	//loads the font
	m_font = new Font("./Fonts/hobo_32px.fnt");

	//stores position, width, height and colour
	m_fPosX = x;
	m_fPosY = y;
	m_fWidth = width;
	m_fHeight = height;
	m_nColourRed = r;
	m_nColourGreen = g;
	m_nColourBlue = b;
	m_nAlpha = a;
}

Button::~Button()
{
	if (m_font)
	{
		delete m_font;
		m_font = nullptr;
	}
}

//void Button::Draw(RenderManager* renderer, float width, float height)
void Button::Draw(RenderManager* renderer)
{
	// grey interior
	renderer->SetRenderColor(m_nColourRed, m_nColourGreen, m_nColourBlue, 255);
	renderer->DrawSprite(NULL, m_fPosX, m_fPosY, m_fWidth, m_fHeight);
	renderer->SetRenderColor(0, 0, 0, 255);

	// calculating centered text
	//float textWidth = m_font->getStringWidth(m_buttonText);		// Leaving this error for now. No getStringWidth
	//float textHeight = m_font->getStringHeight(m_buttonText);		// Leaving this error for now.
	float textWidth = TEXT_WIDTH;
	float textHeight = TEXT_HEIGHT;
	float centredPosX = m_fPosX - (textWidth * 0.5f) + 2;
	float centredPosY = m_fPosY - (textHeight * 0.5f) + 5;

	// draw text
	renderer->DrawText(m_font, m_buttonText, centredPosX, centredPosY);
}

bool Button::Update()
{
	Input* input = Input::Instance();

	// gets mouse position
	int mouseX = input->GetMouseX();
	int mouseY = input->GetMouseY();

	// calculates the four sides of the button
	float left = m_fPosX - (m_fWidth * 0.5f);
	float right = m_fPosX + (m_fWidth * 0.5f);
	float bottom = m_fPosY - (m_fHeight * 0.5f);
	float top = m_fPosY + (m_fHeight * 0.5f);

	// checks if the mouse is inside of the box
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		m_nColourRed = 85;
		m_nColourGreen = 85;
		m_nColourBlue = 85;

		// return whether the mouse button is clicked while colliding
		return input->WasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT);
	}
	else
	{
		m_nColourRed = 185;
		m_nColourGreen = 185;
		m_nColourBlue = 185;
	}

	return false;
}