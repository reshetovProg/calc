

#include "Calculator.h"
#include "SetProject.h"

Calculator::Calculator() : window(sf::VideoMode(WIDTH_W, HEIGHT_W), "Calculator")
{

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
	window.display();
}
