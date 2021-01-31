#include "Character.h"
#include "Pacman.h"
class Ghost: public Character {
public:
	float InBoxTimer = 0, TimeToGo = 3, GTimer = 0;
	float x, y;
	Ghost();
	Ghost(Map& map_helper, SpriteCreator sprite_help, float x_pos, float y_pos);
	virtual void Algorithm(const Pacman& pacman) {}
	~Ghost();

protected:
	float GhostSpeed = 0;
	float GhostStartX = 0, GhostStartY = 0;
};

class Blinky : public Ghost {
	Blinky(Map& map_helper, SpriteCreator sprite_help, float x, float y) : Ghost(map_helper, sprite_help, x, y) {
		GhostSpeed = 170;
		GhostStartX = 100;
		GhostStartY = 100;
		TimeToGo = 0.5;
	}
};