

#include "Calculator.h"
#include "SetProject.h"

Calculator::Calculator() : window(sf::VideoMode(WIDTH_W, HEIGHT_W), "Calculator")
{
	createKeyboard();
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
