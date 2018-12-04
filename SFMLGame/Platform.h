class Platform : public sf::RectangleShape
{
public:
	Platform() {
		depth = 0;
	}

	Platform(sf::Vector2f placement, sf::Texture * block, sf::Vector2f size, double depth) {
		platform.setSize(size);
		platform.setTexture(block);
		platform.setPosition(placement);
		this-> depth = depth;

	}

	void drawToWindow(sf::RenderWindow & window) {
		window.draw(platform);
	}

	sf::FloatRect getTopBound() {

		return sf::FloatRect(platform.getPosition().x, platform.getPosition().y, platform.getSize().x, 4.f);
	}

	void setShape(sf::Vector2f newSize) {
		platform.setSize(newSize);
	}

	void setTexture(sf::Texture * newTex) {
		platform.setTexture(newTex);
	}

	void setPos(double blockX, double blockY) {
		platform.setPosition(blockX, blockY);
	}
	
	void setDepth(double newDepth) {
		depth = newDepth;
	}

private:
	sf::RectangleShape platform;
	double depth;

};