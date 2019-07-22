#include "Button.h"
#include <string.h>
Button::Button(const char* buttonText, float x, float y, float width, float height, int r, int g, int b, int a)
{
	// stores copy of the text
	strcpy_s(m_buttonText, 64, buttonText);

	// loads the font
	m_font = new Font("./Fonts/hobo_32px.fnt");

	// stores position, width, height and colour
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
	delete m_font;
}

void Button::Draw(RenderManager* renderer, float width, float height)
{
	// grey interior
	renderer->SetRenderColor(185, 185, 185, 255);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->SetRenderColor(m_nColourRed, m_nColourGreen, m_nColourBlue, m_nAlpha);

	// calculating centered text
	float textWidth = m_font->getStringWidth(m_buttonText);
	float textHeight = m_font->getStringHeight(m_buttonText);
	float centredPosX = m_posX - (textWidth * 0.5f) + 2;
	float centredPosY = m_posY - (textHeight * 0.5f) + 5;

	// draw text
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
}

bool Button::Update()
{
	aie::Input* input = aie::Input::getInstance();

	// gets mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	// calculates the four sides of the button
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);

	// checks if the mouse is inside of the box
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		// return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}

	return false;
}