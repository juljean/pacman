#include "Pacman.h"
#include <iostream>

Pacman::Pacman(Map map_helper, RenderWindow& window_inst, SpriteCreator sprite_help) : map_inst(map_helper), window(window_inst), spr(sprite_help) {
	dir = "UP";
}

void Pacman::setCharactSpeed(float s) {
	charact_spd = s;
}

void Pacman::Draw() {
	x = dx;
	y = dy;
	spr.spr_hero.setPosition(x, y);
	window.draw(spr.spr_hero);
	//UserInput();
}

void Pacman::UpdatePos() {
	switch (converter.hashit(dir))
	{
	case StringConverter::StringCode::eUp: dx = x; dy = y - Speed * time; break;
	case StringConverter::StringCode::eRight: dx = x + Speed * time; dy = y; break;
	case StringConverter::StringCode::eDown: dx = x; dy = y + Speed * time; break;
	case StringConverter::StringCode::eLeft: dx = x - Speed * time; dy = y; break;
	case StringConverter::StringCode::eNone: dx = x; dy = y; break;
	}
	//x = dx;
	//y = dy;

	// need to add a tunel feature
}

void Pacman::UpdateDir() {
}

bool Pacman::CheckCollision() {
	int w = 21; // to set the closness to the wall
	int h = 28;

	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (map_inst.TileMap[i][j] == '0') {
				dir = "NONE";
				dx = round(x); //CENTER COORDS
				dy = round(y);
				return true;
			}
		}
}

void Pacman::Update()//check for charact update on fatal situations
{
	//UserInput(); //get user input
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
	//UpdatePos();
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