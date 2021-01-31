#pragma once
#include "Sprites.h"
#include "Positions.h"
#include "Map.h"
#include "Positions.h"
#include "Character.h"

class Character {
public:
	StringConverter converter;
	Map map_inst;
	Clock clock;
	SpriteCreator spr;

	float time = clock.getElapsedTime().asSeconds();
	const char* dir;

	float x, y = 0;
	float dx, dy = 0;
	float cur_x, cur_y = 0;
	float Speed = 160;

	Character();
	Character(Map& map_helper, SpriteCreator sprite_help, float x_pos, float y_pos);
	~Character();
	void Draw(RenderWindow& window);
	void setCharactSpeed(float s);
	void Update();
	bool CheckCollision();
	void UpdateDir();
	void UpdatePos();
	void Died();

};