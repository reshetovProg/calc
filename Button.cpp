#include "Calculator.h"
#include "Button.h"

Button::Button(float width, float height, std::string str, sf::Color colorBgr, sf::Color colorText, int sizeText) :
	rectangle(sf::Vector2f(width, height))
{
	
	if (!font.loadFromFile("src/fonts/arial.ttf")) {
		std::cout << "error";
	}
	rectangle.setFillColor(colorBgr);
	text.setFont(font);
	text.setString(str);
	text.setFillColor(colorText);
	text.setCharacterSize(sizeText);

}

sf::Text& Button::getText()
{
	return text;
}

sf::RectangleShape& Button::getRectangle()
{
	return rectangle;
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(text);
}
