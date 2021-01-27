#include "Map.h"
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
		CircleShape shape(50.f);

		// set the shape color to green
		shape.setFillColor(sf::Color(90, 20, 50));

		SpriteCreator sprite_help;
		sprite_help.ImageCreation();
		sprite_help.TextureCreation();
		sprite_help.SpriteCreation();


		Map map_helper(window, sprite_help);
		map_helper.DrawMap();

		//window.draw(sprite_help.spr_map);
		//window.draw(sprite_help.spr_coins);
		//window.draw(sprite_help.spr_diamond);
		//window.draw(sprite_help.spr_cherry);
		//window.draw(sprite_help.backgr);

		window.display();
	}
	return 0;
}