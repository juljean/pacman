﻿#include "Map.h"
#include "Pacman.h"
#include "Positions.h"

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

		
		Map map_helper(window, sprite_help);
		Pacman main_charact(map_helper, map_helper.window, sprite_help);


		while (true)
		{
			window.clear(); //reduces a trail after sprite 
			map_helper.DrawMap();
			main_charact.UserInput();
			main_charact.UpdatePos();
			main_charact.CheckCollision();
			main_charact.Draw();
			window.display();
		}

	}
	return 0;
}