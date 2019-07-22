#include "MenuButton.h"
#include <string.h>
MenuButton::MenuButton(const char* buttonText, float x, float y, float width, float height, float r, float g, float b)
{
	// stores copy of the text
	strcpy_s(m_buttonText, 64, buttonText);

	// loads the font
	m_font = new aie::Font("./font/consolas.ttf", 24);

	// stores position, width, height and colour
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
	m_colourRed = r;
	m_colourGreen = g;
	m_colourBlue = b;
}

MenuButton::~MenuButton()
{
	delete m_font;
}

void MenuButton::Draw(aie::Renderer2D* renderer, float width, float height)
{
	// grey interior
	renderer->setRenderColour(0.9f, 0.9f, 0.9f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(m_colourRed, m_colourGreen, m_colourBlue);

	// calculating centered text
	float textWidth = m_font->getStringWidth(m_buttonText);
	float textHeight = m_font->getStringHeight(m_buttonText);
	float centredPosX = m_posX - (textWidth * 0.5f) + 2;
	float centredPosY = m_posY - (textHeight * 0.5f) + 5;

	// draw text
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
}

bool MenuButton::Update()
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