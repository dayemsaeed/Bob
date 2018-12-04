#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "spaceBros.h"
#include "bob.h"
#include "wolves.h"


bool checkCollides(sf::Sprite character, Platform all[], int &numPlat, int const &direction, float &speed);
bool enemyCollisions(sf::Sprite character, sf::Sprite wolves[], int &numWolves);
