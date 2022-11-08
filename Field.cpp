#include "Calculator.h"
#include "Field.h"

Field::Field(float width, float height, std::string str, sf::Color colorBgr, sf::Color colorText, int sizeText) :
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
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color(200, 200, 200, 255));
	setPosition(0, 0);



}

sf::Text& Field::getText()
{
	return text;
}

sf::RectangleShape& Field::getRectangle()
{
	return rectangle;
}

void Field::setPosition(float x, float y)
{
	float size = text.getCharacterSize();
	rectangle.setPosition(x, y);
	text.setPosition(x - size*text.getString().getSize() 
		/ 1.8 - 15 + rectangle.getSize().x, y + (rectangle.getSize().y 
			- size) / 2.4);
}

bool Field::intersects(sf::Vector2f mouse)
{
	float rX = rectangle.getPosition().x;
	float rY = rectangle.getPosition().y;
	float sX = rectangle.getSize().x;
	float sY = rectangle.getSize().y;
	return ((rX < mouse.x&& mouse.x < (rX + sX)) && ((rY < mouse.y&& mouse.y < (rY + sY))));
}

void Field::setColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

void Field::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(text);
}
