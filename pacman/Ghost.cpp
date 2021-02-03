#include "Ghost.h"
#include <SFML\Graphics.hpp>

Ghost::Ghost() : Character() {}

Ghost::Ghost(SpriteCreator sprite_help, float x_pos, float y_pos) : Character(sprite_help, x_pos, y_pos) {}

Ghost:: ~Ghost() {}


//Blinky:: Blinky() : Ghost() {}
//Blinky:: Blinky(SpriteCreator sprite_help, float x_pos, float y_pos) : Ghost(sprite_help, x_pos, y_pos) {}
//
////void Blinky::Algorithm() {
////	//x = 0;
////}

