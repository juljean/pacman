#include <SFML/Graphics.hpp>

#include "Sprites.h"
#include "Positions.h"
#include "Map.h"
#include "Positions.h"
#include "Character.h"

using namespace sf;

class Pacman : public Character {

public:
	Pacman();
	Pacman(SpriteCreator sprite_help, float x_pos, float y_pos);
	void UserInput();
};
