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
};

