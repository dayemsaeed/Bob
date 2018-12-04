class Bob : public SpaceBros {

public:

	Bob(sf::Vector2f placement, sf::Texture * block, sf::Vector2f size, double speed, double maxJumpHeight) : SpaceBros(placement, block, size) {
		bobSpeed = speed;
		bobMaxJump = maxJumpHeight;
		jumpHeight = 0;
		jumping = false;
		canJump = false;
	}

	void move(std::string direction, sf::View &background, double &centerX, sf::Sprite &distance) {
		if (direction == "left") {
			if (!(getPackage().getPosition().x < (background.getCenter().x - 500))) { // can't move past left side of screen, 500 is offset from centerX value
				getPackage().move(-bobSpeed, 0);
			}
		}
		if (direction == "right") {
			getPackage().move(bobSpeed, 0);
			if (getPackage().getPosition().x > centerX) { // movepast center, background moves with you
				centerX += bobSpeed;
				distance.move(bobSpeed, 0); // background moves with character
			}
		}
		if (direction == "up" && canJump == true && jumpHeight < bobMaxJump) {
			jumping = true; // turns off gravity (magic!)
			getPackage().move(0, -bobSpeed);
			jumpHeight += bobSpeed;
			if (jumpHeight >= bobMaxJump) {
				canJump = false;
				jumping = false;
			}
		}

	}

	// somehow i can't create my own sf::FloatRect containing only the sliver of area 
	// widthwise of bob's feet, WTF
	//sf::FloatRect getBobFeet() {

	//	// return sf::FloatRect(getPackage().getGlobalBounds().left, getPackage().getGlobalBounds().top + getPackage().getSize().y, 
	//	// 	getPackage().getSize().x, 2.f);

	//	// current has him 'climbing' at least he can't jump when he's 'climbing'
	//	return getPackage().getGlobalBounds();
	//}


	bool canBobJump() {
		return canJump;
	}

	bool isBobJumping() {
		return jumping;
	}

	void gravity(Platform all[], int &numPlats) {
		if (jumping == false && !collidesPlat(all, numPlats)) { // doesn't work when jumping
			getPackage().move(0, bobSpeed);
			canJump = false;
			if (collidesPlat(all, numPlats)) { // can't move farther down
				jumpHeight = 0;
				canJump = true;
			}
		}
	}

	// why doesn't this work
	//bool enemyCollision(sf::FloatRect wolf) {
	//	bool success = false;

	//	if (getPackage().getGlobalBounds().intersects(wolf)) {
	//		success = true;
	//	}

	//	return success;
	//}

	void drawToWindow(sf::RenderWindow & window) {
		window.draw(getPackage());
	}

	void setJumping(bool success) {
		jumping = success;
	}

	void setCanJump(bool success) {
		canJump = success;
	}

	void setTexture(sf::IntRect newTex) {
		getPackage().setTextureRect(newTex);

	}

	double getJumpHeight(){
		return jumpHeight;
	}

	double getMaxJump() {
		return bobMaxJump;
	}

private:
	bool jumping;
	bool canJump;
	double bobSpeed;
	double jumpHeight;
	double bobMaxJump;

};