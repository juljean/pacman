#pragma once
#include "Sprites.h"
#include "Positions.h"
#include "Map.h"
#include "Positions.h"
#include "Character.h"

class Character {
public:
	float x = 0, y = 0;
	StringConverter converter;
	Clock clock;
	SpriteCreator spr;
	float time = clock.getElapsedTime().asSeconds();
	const char* dir = "NONE";

	Character();
	Character(SpriteCreator sprite_help, float x_pos, float y_pos);
	~Character();
	void Draw(RenderWindow& window, Sprite sprt);
	void setCharactSpeed(float s);
	void Update();
	bool CheckCollision(int w, int h, std::string* TileMap);
	void UpdateDir();
	void UpdatePos();
	void SetCoord(float x, float y);
	void SetDCoord(float dx, float dy);

	//float GetXCoord();
	//float GetYCoord();
	//float GetDXCoord();
	//float GetDYCoord();
	//void GetCoord();
	//void Died();

protected:
	float dx = 355, dy = 215;
	//float cur_x = 0, cur_y = 0;
	float Speed = 0;
};