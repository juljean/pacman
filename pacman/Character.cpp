#include "Character.h"

Character::Character() {}

Character::Character(SpriteCreator sprite_help, float x_pos, float y_pos) : spr(sprite_help), x(x_pos), y(y_pos) {}

Character::~Character() {}

void Character::setCharactSpeed(float s) {
	this->Speed = s;
}

void Character::SetCoord(float x, float y) {
	this->x = x;
	this->y = y;
}

void Character::SetDCoord(float dx, float dy) {
	this->dx = dx;
	this->dy = dy;
}

void Character::Draw(RenderWindow& window, Sprite sprt) {
	x = round(dx);
	y = round(dy);
	sprt.setPosition(x, y);
	window.draw(sprt);
}

void Character::UpdatePos() {

	switch (converter.hashit(dir))
	{
	case StringConverter::StringCode::eUp: dx = x; dy = y - Speed * time; break;
	case StringConverter::StringCode::eRight: dx = x + Speed * time; dy = y; break;
	case StringConverter::StringCode::eDown: dx = x; dy = y + Speed * time;  break;
	case StringConverter::StringCode::eLeft: dx = x - Speed * time; dy = y; break;
	case StringConverter::StringCode::eNone: dx = x; dy = y; break;
	}

	// need to add a tunel feature
}

void Character::UpdateDir() {
}

bool Character::CheckCollision(int w, int h, std::string *TileMap) {
	//int w = 21; int h = 28; // to set the closness to the wall

	for (int i = dy / 32; i < (dy + h) / 32; i++)
		for (int j = dx / 32; j < (dx + w) / 32; j++)
		{
			if (TileMap[i][j] == '0') {				
				dx = round(x);
				dy = round(y);
				return true;
			}
		}

	return false;
}

void Character::Update()//check for charact update on fatal situations
{
	//UserInput(); //get user input
}
