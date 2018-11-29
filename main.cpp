// This code expands on the tutorial code provided at:
// http://www.sfml-dev.org/tutorials/2.3/start-vc.php

#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "Paddle.h"


int main()
{
	sf::Texture texture;
	if (!texture.loadFromFile(("background.jpg"), sf::IntRect(10,10,1000,1000))) {
		return -1;

	}
	sf::Sprite background(texture);

	sf::RectangleShape rectangle(sf::Vector2f(150, 80));
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Moving a shape");
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();

				return 0;
			}
		}


		window.clear(sf::Color::White);

		rectangle.setFillColor(sf::Color(0, 250, 0));

		window.clear(sf::Color::Black);

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				rectangle.move(0, -5);
				Sleep(1);
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				rectangle.move(0, 5);
				Sleep(1);
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				rectangle.move(-5, 0);
				Sleep(1);
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				rectangle.move(5, 0);
				Sleep(1);
			}
		}

		window.draw(background);
		window.draw(rectangle);
		window.display();

	}


	return 0;
}