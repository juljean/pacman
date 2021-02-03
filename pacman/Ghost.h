#include "Character.h"
//#include "Pacman.h"

class Ghost: public Character {
public:
	SpriteCreator spr;
	float x = 0, y = 0;
	float InBoxTimer = 0, TimeToGo = 3, GTimer = 0;
	Ghost();
	Ghost(SpriteCreator sprite_help, float x_pos, float y_pos);
	//virtual void Algorithm();
	~Ghost();

protected:
	float GhostSpeed = 0;
	float GhostStartX = 0, GhostStartY = 0;
};

//class Blinky : public Ghost {
//	Blinky();
//	Blinky(SpriteCreator sprite_help, float x_pos, float y_pos);
//	//void Algorithm();
//};