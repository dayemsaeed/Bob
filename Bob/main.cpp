#include <SFML/graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	sf::Texture texture;
	if (!texture.loadFromFile("bob.png")) {

		throw std::runtime_error("File could not be opened");

	}
	else {

		sf::Sprite sprite;
		sprite.setTexture(texture);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(sprite);
			window.display();
		}

	}

	return 0;
}