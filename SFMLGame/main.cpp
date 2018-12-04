#include <iostream>
#include "header.h"


int main()
{

	// establish background
	sf::Texture background;
	sf::Sprite distance;

	// load image of background
	if (!background.loadFromFile("spaceBack1.png")) {
		return -1;
	}
	distance.setTexture(background);
	distance.setPosition(-900, 0);

	// platforms + ground
	sf::Texture block;
	sf::Texture * blockPtr = &block; // rectangleShapes need pointers to textures

	if (!block.loadFromFile("rocky01.png")) {
		return -1;
	}

	// lava
	sf::Texture lava;
	sf::Texture * lavaPtr = &lava; // rectangleShapes need pointers to textures

	if (!lava.loadFromFile("lava 1.png")) {
		return -1;
	}

	Platform ground[100];
	for (int i = 0; i < 100; i++) {
		if (i > 30 && i < 45) {
			ground[i].setShape(sf::Vector2f(50.f, 50.f));
			ground[i].setTexture(lavaPtr);
			ground[i].setPos(-100 + (i * 50), 650);
			ground[i].setDepth(20);
		} else if (i > 77 && i < 80) {
			ground[i].setShape(sf::Vector2f(50.f, 50.f));
			ground[i].setTexture(lavaPtr);
			ground[i].setPos(-100 + (i * 50), 650);
			ground[i].setDepth(20);
		} else {
			ground[i].setShape(sf::Vector2f(50.f, 50.f));
			ground[i].setTexture(blockPtr);
			ground[i].setPos(-100 + (i * 50), 650);
			ground[i].setDepth(0);
		}
	}

	Platform test(sf::Vector2f(0, 350), blockPtr, sf::Vector2f(400, 300), 0);
	Platform one(sf::Vector2f(700, 350), blockPtr, sf::Vector2f(400, 300), 0);
	Platform two(sf::Vector2f(500, 450), blockPtr, sf::Vector2f(250, 200), 0);
	Platform thr(sf::Vector2f(800, 250), blockPtr, sf::Vector2f(300, 400), 0);
	Platform fur(sf::Vector2f(1300, 400), blockPtr, sf::Vector2f(800, 300), 0);
	Platform fiv(sf::Vector2f(2850, 450), blockPtr, sf::Vector2f(800, 150), 0);
	Platform six(sf::Vector2f(2500, 550), blockPtr, sf::Vector2f(300, 100), 0);
	Platform sev(sf::Vector2f(2300, 450), blockPtr, sf::Vector2f(100, 100), 0);
	Platform egt(sf::Vector2f(2700, 550), blockPtr, sf::Vector2f(100, 100), 0);
	

	Platform allPlats[109];
	allPlats[0] = fur;
	for (int i = 1; i < 101; i++) {
		allPlats[i] = ground[i - 1];
	}
	allPlats[101] = one;
	allPlats[102] = two;
	allPlats[103] = thr;
	allPlats[104] = fiv;
	allPlats[105] = six;
	allPlats[106] = sev;
	allPlats[107] = egt;
	allPlats[108] = test;
	int numPlats = 109;

	// inherent attributes
	double centerX = 500;
	double centerY = 350;

	enum Direction { Down, Left, Right, Up };
	
	// window stuff
	int x_coord = 0, y_coord = Right;
	sf::Vector2i source(x_coord, y_coord);
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	sf::Clock clock;
	sf::View gameBackground(sf::FloatRect(0, 0, 1000.f, 700.f));
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Bob in Space");
	window.setVerticalSyncEnabled(true);

	// bob
	sf::Texture bobTex;
	if (!bobTex.loadFromFile("bob-sheet.png")) {
		return -1;

	}
	
	Bob ourBob(sf::Vector2f(0,0), &bobTex, sf::Vector2f(32,32), 10, 150);

	// wolf
	sf::Texture wolfTex;
	if (!wolfTex.loadFromFile("wolf.png")) {
		return -1;

	}

	wolfTex.setSmooth(true);
	Wolves enemies[5];
	enemies[0] = Wolves(sf::Vector2f(250,0), &wolfTex, sf::Vector2f(32, 32), 3, 150, true);
	enemies[1] = Wolves(sf::Vector2f(550, 0), &wolfTex, sf::Vector2f(32, 32), 3, 50, false);
	enemies[2] = Wolves(sf::Vector2f(800, 0), &wolfTex, sf::Vector2f(32, 32), 1, 100, true);
	enemies[3] = Wolves(sf::Vector2f(1000, 0), &wolfTex, sf::Vector2f(32, 32), 5, 300, true);
	enemies[4] = Wolves(sf::Vector2f(1500, 0), &wolfTex, sf::Vector2f(32, 32), 2, 90, false);
	int numWolves = 5;
	

	// game loop
	while (window.isOpen()) {

		sf::Event event;


		// Bob Movement	- key pressed
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				ourBob.move("left", gameBackground, centerX, distance);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				ourBob.move("right", gameBackground, centerX, distance);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				ourBob.move("up", gameBackground, centerX, distance);
			}
		}

		// Bob gravity
		ourBob.gravity(allPlats, numPlats);

		// update Bob Sprite
		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			source.x++;
			if (source.x * 32 >= bobTex.getSize().x) {
				source.x = 0;
			}
		}
		ourBob.setTexture(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

		// event loop
		while (window.pollEvent(event)) {

			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

				// space 'jumping' is released
			case sf::Event::KeyReleased:
				ourBob.setJumping(false); // turns on gravity (more magic!)

			}
		}

		// wolf Movement
		for (int ww = 0; ww < numWolves; ww++) {
			enemies[ww].move("none", gameBackground, centerX, distance);
		}

		// wolf Gravity
		for (int h = 0; h < numWolves; h++) {
			enemies[h].gravity(allPlats, numPlats);
		}

		// why doesn't this work
		//// Check Enemy Collision

		//for (int wwz = 0; wwz < numWolves; wwz++) {
		//	if (ourBob.enemyCollision(enemies[wwz].getGlobalBounds())) {
		//		ourBob.getPackage().move(0, 0);
		//		std::cout << "You Lose" << std::endl;
		//	}
		//}

		// update Bob Sprite
		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			source.x++;
			if (source.x * 32 >= bobTex.getSize().x) {
				source.x = 0;
			}
		}
		ourBob.setTexture(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

		// update wolf Sprites
		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			source.x++;
			if (source.x * 32 >= wolfTex.getSize().x) {
				source.x = 0;
			}
		}
		for (int l = 0; l < numWolves; l++) {
			enemies[l].setTexture(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
		}

		window.clear();
		gameBackground.setCenter(centerX, centerY);
		window.setView(gameBackground);
		window.draw(distance);
		for (int j = 0; j < numPlats; j++) {
			allPlats[j].drawToWindow(window);
		}
		for (int w = 0; w < numWolves; w++) {
			enemies[w].drawToWindow(window);
		}
		ourBob.drawToWindow(window);
		window.display();

	}

	return 0;
}