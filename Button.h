#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class Button
{
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
public:
	Button(float width, float height, std::string str, sf::Color color, sf::Color colorText, int sizeText);
	void draw(sf::RenderWindow& window);
	sf::Text& getText();
	sf::RectangleShape& getRectangle();
	void setPosition(float x, float y);
	bool intersects(sf::Vector2f mouse) { return ((rectangle.getPosition().x < mouse.x&& mouse.x < (rectangle.getPosition().x + rectangle.getSize().x)) && ((rectangle.getPosition().y < mouse.y&& mouse.y < (rectangle.getPosition().y + rectangle.getSize().y)))); }
	void setColor(sf::Color color) {
		rectangle.setFillColor(color);
	}
};

