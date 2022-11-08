#include "Calculator.h"
#include "SetProject.h"
#include <iostream>


Calculator::Calculator() : window(sf::VideoMode(WIDTH_W, HEIGHT_W), "Calculator")
{
	createKeyboard();
	createField();
}


void Calculator::run()
{
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Calculator::processEvents()
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					if (keyboard[i][j]->intersects(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
						keyboard[i][j]->setColor(sf::Color(0, 255, 0, 25));
						lastBtn = keyboard[i][j];
					}
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			if (lastBtn != nullptr) {
				lastBtn->setColor(buttonBack);
				if (lastBtn->intersects(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					std::string text = lastBtn->getText().getString();
					std::cout << text;
				}

			}
		}
	}
}

void Calculator::update()
{
}

void Calculator::render()
{
	window.clear();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			keyboard[i][j]->draw(window);
		}
	}
	field->draw(window);
	window.display();
}

void Calculator::createKeyboard()
{
	int btnH = (HEIGHT_W - fieldSize) / row;
	int btnW = WIDTH_W / column;
	keyboard = new Button**[row];
	for (int i = 0; i < row; i++) {
		keyboard[i] = new Button * [column];
		for (int j = 0; j < column; j++) {
			keyboard[i][j] = new Button(btnW, btnH, keySymbol[i][j], buttonBack, colorText, 20);
			keyboard[i][j]->setPosition(btnW * j, btnH * i + fieldSize);
		}
	}

}

void Calculator::createField()
{
	field = new Field(WIDTH_W, fieldSize, "267236812638", colorText, buttonBack, 50);
	
}
