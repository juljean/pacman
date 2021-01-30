#include <SFML/Graphics.hpp>

#include "Sprites.h"
#include "Positions.h"
#include "Map.h"
#include "Positions.h"
using namespace sf;

class Pacman {
public:
	float charact_spd;
	StringConverter converter;
	Map map_inst;
	Clock clock;
	RenderWindow& window;
	SpriteCreator spr;

	float time = clock.getElapsedTime().asSeconds();
	const char *dir;
	float x = 60;
	float y = 35;
	float dx, dy = 0;
	float cur_x, cur_y = 0;
	float Speed = 160;

	Pacman(Map map_helper, RenderWindow& window_inst, SpriteCreator sprite_help);
	void Draw();
	void setCharactSpeed(float s);
	void Update();
	void UserInput();
	bool CheckCollision();
	void UpdateDir();
	void UpdatePos();

};
