#include "Sprites.h"
#include <iostream>

void SpriteCreator:: ImageCreation() {
	map_image.loadFromFile("tile\\tileset1.png");
	hero_image.loadFromFile("tile\\hero.png");
	coins_image.loadFromFile("tile\\coins.png");
	death_image.loadFromFile("tile\\death.png");
	bonus_image.loadFromFile("tile\\bonuses.png");
	blinky_image.loadFromFile("tile\\pacman.png");

	backgr.setSize(Vector2f(32.f, 32.f));
	backgr.setFillColor(Color::Black);
	
}

void SpriteCreator::TextureCreation() {
	map.loadFromImage(map_image);
	coins.loadFromImage(coins_image);
	hero.loadFromImage(hero_image);
	hero.setSmooth(true);
	death.loadFromImage(death_image);
	bonus.loadFromImage(bonus_image);
	blinky.loadFromImage(blinky_image);
}

void SpriteCreator::SpriteCreation() {
	spr_map.setTexture(map);
	spr_hero.setTexture(hero);
	spr_hero.setTextureRect(IntRect(52, 52, 28, 38));
	spr_hero.scale(0.7f, 0.75f);

	spr_coins.setTexture(coins);
	spr_coins.setTextureRect(IntRect(32, 0, 30, 30));
	spr_coins.scale(0.5f, 0.5f);

	spr_cherry.setTexture(bonus);
	spr_cherry.setTextureRect(IntRect(50, 0, 40, 45));
	spr_cherry.scale(0.7f, 0.6f);

	spr_diamond.setTexture(bonus);
	spr_diamond.scale(0.7f, 0.6f);
	spr_diamond.setTextureRect(IntRect(0, 290, 50, 50));

	spr_blinky.setTexture(blinky);
	spr_blinky.setTextureRect(IntRect(0, 40, 40, 60));
	spr_blinky.scale(0.7f, 0.75f);
}
