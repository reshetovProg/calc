#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class Calculator
	{
		sf::RenderWindow window;
		sf::Event event;
		Button* btn=nullptr;
	public:
		Calculator();
		void run();
		void processEvents();
		void update();
		void render();
	};
