#include "header.h"

// false : no collision
// true  : collision
bool checkCollides(sf::Sprite character, Platform all[], int &numPlat, int const &direction, float &speed) {
	bool success = false;

	for (int i = 0; i < numPlat; i++) {
		
		if (character.getGlobalBounds().intersects(all[i].getTopBound()))
			success = true;
	}

	return success;
}

bool enemyCollisions(sf::Sprite character, sf::Sprite wolves[], int &numWolves) {
	bool success = false;

	for (int i = 0; i < numWolves; i++) {

		if (character.getGlobalBounds().intersects(wolves[i].getGlobalBounds())) {
			success = true;
		}

		return success;
	}
}
