//#include "Pacman.h"
//#include "Positions.cpp"
//#include "Map.h"
//
//void Pacman::setCharactSpeed(float s) {
//	charact_spd = s;
//}
//
//void Draw(int x, int y) {
//	//spr_hero.setPosition(x, y);
//	//window.draw(spr_hero);
//}
//
//void Pacman::UpdatePos(int Speed) {
//	switch (hashit(dir))
//	{
//	case eUp: dx = x; dy = y - Speed * time; break;
//	case eRight: dx = x + Speed * time; dy = y; break;
//	case eDown: dx = x; dy = y + Speed * time; break;
//	case eLeft: dx = x - Speed * time; dy = y; break;
//	}
//	// need to add a tunel feature
//}
//
//void Pacman::UpdateDir() {
//
//}
//
//void Pacman::Update()//check for charact update on fatal situations
//{
//	UserInput(); //get user input
//}
//
//void Pacman::UserInput() {
////add wsad moving
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//		dir = "LEFT";
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//		dir = "RIGHT";
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//		dir = "UP";
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//		dir = "DOWN";
//	}
//}
//
//float* inter_with_map(float dx, float dy, float x, float y) {
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