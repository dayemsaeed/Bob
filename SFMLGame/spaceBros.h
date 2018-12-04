class SpaceBros : public sf::RectangleShape // everything is rectangles
{
public:

	SpaceBros() {

	}

	SpaceBros(sf::Vector2f placement, sf::Texture * block, sf::Vector2f size) {
		bro.setSize(size);
		bro.setTexture(block);
		bro.setPosition(placement);
		bro.setScale(3, 3);

	}

	virtual void move(std::string direction, sf::View &background, double &centerX, sf::Sprite &distance) = 0; // each subclass needs its own

	virtual void gravity(Platform all[], int &numPlats) = 0;

	virtual bool collidesPlat(Platform all[], int &numPlats) {
		bool success = false;

		for (int i = 0; i < numPlats; i++) {
			
			if (bro.getGlobalBounds().intersects(all[i].getTopBound())) {
				success = true;
			}
		}

		return success;
	}


	void setShape(sf::Vector2f newSize) {
		bro.setSize(newSize);
	}

	void setTexture(sf::Texture * newTex) {
		bro.setTexture(newTex);
	}

	void setPos(double blockX, double blockY) {
		bro.setPosition(blockX, blockY);
	}

	sf::RectangleShape & getPackage() {
		return bro;
	}

	void drawToWindow(sf::RenderWindow & window) {
		window.draw(bro);
	}

private:
	sf::RectangleShape bro;


};