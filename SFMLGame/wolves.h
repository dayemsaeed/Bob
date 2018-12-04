class Wolves : public SpaceBros {

public:

	Wolves() {
	
	}

	Wolves(sf::Vector2f placement, sf::Texture * block, sf::Vector2f size, double speed, double width, bool left) : SpaceBros(placement, block, size) {
		wolfSpeed = speed;
		trailLength = width;
		this->left = left;
		zone = 0;

	}

	void move(std::string direction, sf::View &background, double &centerX, sf::Sprite &distance) {
		if (left == true) {
			getPackage().move(-wolfSpeed, 0);
			zone -= wolfSpeed;
			if (zone <= -trailLength) {
				left = false;
			}
		}
		else {
			getPackage().move(wolfSpeed, 0);
			zone += wolfSpeed;
			if (zone >= trailLength) {
				left = true;
			}
		}
	}

	void gravity(Platform all[], int &numPlats) {
		if (!collidesPlat(all, numPlats)) { // doesn't work when jumping
			getPackage().move(0, wolfSpeed);
		}
	}

	void setTexture(sf::IntRect newTex) {
		getPackage().setTextureRect(newTex);

	}
		 

private:
	double zone;
	double wolfSpeed;
	double trailLength;
	bool left;

};