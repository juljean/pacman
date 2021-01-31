#include <SFML/Graphics.hpp>

#include "Sprites.h"
#include "Positions.h"
#include "Map.h"
#include "Positions.h"
#include "Character.h"

using namespace sf;

class Pacman: public Character {

public:
	float Speed = 190;
	Pacman();
	Pacman(Map& map_helper, SpriteCreator sprite_help, float x_pos, float y_pos);
	void UserInput();

};
