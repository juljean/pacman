#include "Pacman.h"
#include <iostream>


Pacman::Pacman() : Character(){}


Pacman::Pacman(Map& map_helper, SpriteCreator sprite_help, float x_pos, float y_pos) : Character(map_helper, sprite_help, x_pos, y_pos) {
	dir = "UP";
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



//float Pacman:: inter_with_map(float dx, float dy, float x, float y) {
//	int w = 29;
//	int h = 29;//sprite size
//	for (int i = y / 32; i < (y + h) / 32; i++)
//		for (int j = x / 32; j < (x + w) / 32; j++)
//		{
//			if (TileMap[i][j] == '0') {
//				if (dy > 0) {//go down
//					y = i * 32 - h;//stopped a hero
//					float coord[2] = { x,y };
//					return coord;
//				}
//				if (dy < 0) {//go up
//					y = i * 32 + 32;
//					float coord[2] = { x,y };
//					return coord;
//				}
//				if (dx > 0) {
//					x = j * 32 - w;//stopped a hero
//					float coord[2] = { x,y };
//					return coord;
//				}
//				if (dx < 0) {//go to the left
//					x = j * 32 + 32;
//					float coord[2] = { x,y };
//					return coord;
//				}
//			}
//			if (TileMap[i][j] == '1') {
//				TileMap[i][j] = ' ';
//				float coord[2] = { x,y };
//				return coord;
//			}
//			if (TileMap[i][j] == 'b') {
//				TileMap[i][j] = ' ';
//				float coord[2] = { 60,35 };
//				return coord;
//			}
//			if (TileMap[i][j] == 'd') {
//				TileMap[i][j] = ' ';
//				float coord[2] = { x,y };
//				return coord;
//			}
//		}
//	float coord[2] = { x,y };
//	return coord;
//}