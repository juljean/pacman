#include "Character.h"

Character::Character() {

}

Character::Character(Map& map_helper, SpriteCreator sprite_help, float x_pos, float y_pos) : map_inst(map_helper), spr(sprite_help), x(x_pos), y(y_pos) {

}

Character::~Character() {

}

void Character::setCharactSpeed(float s) {
	Speed = s;
}

void Character::Draw(RenderWindow& window) {
	x = dx;
	y = dy;
	spr.spr_hero.setPosition(x, y);
	window.draw(spr.spr_hero);
}

void Character::UpdatePos() {
	switch (converter.hashit(dir))
	{
	case StringConverter::StringCode::eUp: dx = x; dy = y - Speed * time; break;
	case StringConverter::StringCode::eRight: dx = x + Speed * time; dy = y; break;
	case StringConverter::StringCode::eDown: dx = x; dy = y + Speed * time; break;
	case StringConverter::StringCode::eLeft: dx = x - Speed * time; dy = y; break;
	case StringConverter::StringCode::eNone: dx = x; dy = y; break;
	}

	// need to add a tunel feature
}

void Character::UpdateDir() {
}

bool Character::CheckCollision() {
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
	false;
}

void Character::Update()//check for charact update on fatal situations
{
	//UserInput(); //get user input
}