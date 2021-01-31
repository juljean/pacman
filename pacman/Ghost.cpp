#include "Ghost.h"
#include <SFML\Graphics.hpp>

Ghost::Ghost() : Character() {}


Ghost::Ghost(Map& map_helper, SpriteCreator sprite_help, float x_pos, float y_pos) : Character(map_helper, sprite_help, x_pos, y_pos) {
}

