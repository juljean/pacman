#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class SpriteCreator{
public:
	Image map_image, hero_image, coins_image, death_image, bonus_image;
	Texture map, hero, coins, death, bonus;
	Sprite spr_map, spr_hero, spr_coins, spr_death, spr_diamond, spr_cherry;
	RectangleShape backgr;

	void ImageCreation();
	void TextureCreation();
	void SpriteCreation();

};

