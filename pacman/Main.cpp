#include "Map.h"
#include "Pacman.h"
#include "Positions.h"
#include "Ghost.h"


RenderWindow window(sf::VideoMode(800, 600), "Pacman");
//float x = 60; Pacman start posx
//float y = 35; Pacman start posy

int main() {
	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

		}

		SpriteCreator sprite_help;
		sprite_help.ImageCreation();
		sprite_help.TextureCreation();
		sprite_help.SpriteCreation();

		
		Map map_helper(sprite_help);
		Pacman main_charact(sprite_help, 60.0, 35.0);
		main_charact.setCharactSpeed(80);
		Ghost blinky(sprite_help, 355, 215);

		while (true)
		{
			window.clear(); //reduces a trail after sprite 
			map_helper.DrawMap(window);
			main_charact.UserInput();
			main_charact.UpdatePos();
			main_charact.CheckCollision(21, 28, map_helper.TileMap);
			main_charact.Draw(window, sprite_help.spr_hero);
			blinky.Draw(window, sprite_help.spr_blinky);
			window.display();
		}

	}
	return 0;
}