#pragma once
#include <SFML/Graphics.hpp>
class Calculator
	{
		sf::RenderWindow window;
		sf::Event event;
	public:
		Calculator();
		void run();
		void processEvents();
		void update();
		void render();
	};
