#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Field
{
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;

public:
	Field(float width, float height, std::string str, sf::Color color, sf::Color colorText, int sizeText);
	void draw(sf::RenderWindow& window);
	sf::Text& getText();
	sf::RectangleShape& getRectangle();
	void setPosition(float x, float y);
	bool intersects(sf::Vector2f mouse);
	void setColor(sf::Color color);
};

