#include "Pacman.h"
#include <iostream>


Pacman::Pacman() : Character(){}


Pacman::Pacman(SpriteCreator sprite_help, float x_pos, float y_pos) : Character(sprite_help, x_pos, y_pos) {
}



void Pacman::UserInput() {
//add wsad moving
	dir = "NONE";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dir = "LEFT";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dir = "RIGHT";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		dir = "UP";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		dir = "DOWN";
	}
}


