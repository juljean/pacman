#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "map.h"
using namespace sf;
RenderWindow window(sf::VideoMode(800, 600), "Pacman");

float *inter_with_map(float dx, float dy,float x, float y) {
	int w = 29;
	int h = 29;//sprite size
	for (int i = y/32; i < (y + h)/32; i++) 
	for (int j = x/32; j < (x + w)/32; j++)
	{
		if (TileMap[i][j] == '1') TileMap[i][j] = ' ';
		if (TileMap[i][j] == '0') {
			if (dy > 0) {//go down
				y = i * 32 - h;//stopped a hero
				float coord[2] = { x,y };
				return coord;
			}
			if (dy < 0) {//go up
				y = i * 32 + 32;
				float coord[2] = { x,y };
				return coord;
			}
			if (dx > 0) {//go to the right
				x = j*32-w;//stopped a hero
				float coord[2] = { x,y };
				return coord;
			}
			if (dx < 0) {//go to the left
				x = j * 32 + 32;
				float coord[2] = { x,y };
				return coord;
			}
		}
	}
	float coord[2] = { x,y };
	return coord;
}

float* update(float time, int dir, float speed, float x, float y)
{
	float dx, dy;
	dx= dy = 0;	
	switch (dir)
	{	
	case 0: dx = speed; dy = 0; break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
	case 1: dx = -speed; dy = 0; break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
	case 2: dx = 0; dy = speed; break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
	case 3: dx = 0; dy = -speed; break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
	}
	x += dx * time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
	y += dy * time;//аналогично по игреку
	speed = 0;//зануляем скорость, чтобы персонаж остановился.
	float back[4] = { x, y,dx,dy };
	return back;
}

int main() {
	RenderWindow window(sf::VideoMode(800, 600), "Pacman");
	Image map_image, hero_image, coins_image;
	map_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\tileset1.png");
	hero_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\hero.png");
	coins_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\coins.png");
	Texture map, herotexture, coins;
	map.loadFromImage(map_image);
	coins.loadFromImage(coins_image);
	herotexture.loadFromImage(hero_image);
	Sprite spr_map, spr_hero, spr_coins;
	spr_map.setTexture(map);
	spr_hero.setTexture(herotexture);
	spr_hero.setTextureRect(IntRect(46, 49, 46, 46));
	spr_hero.scale(0.75f, 0.75f);
	spr_coins.setTexture(coins);
	spr_coins.setTextureRect(IntRect(32, 0, 32, 32));
	spr_coins.scale(0.5f, 0.5f);

	RectangleShape backgr(Vector2f(32.f, 32.f));
	backgr.setFillColor(Color(0, 0, 0));
	//CircleShape coins(10,4);
	//coins.setFillColor(Color(255,255,204));
	Clock clock;
	float x, y,dx,dy;
	x = 60;
	y = 35;
	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		int dir = 0;
		float speed = 0;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++) {
				if (TileMap[i][j] == ' ') { backgr; backgr.setPosition(j * 32, i * 32);}
				if (TileMap[i][j] == '0') { spr_map.setTextureRect(IntRect(64, 0, 32, 32)); spr_map.setPosition(j * 32, i * 32);}
				if (TileMap[i][j] == '1') { spr_coins; spr_coins.setPosition(j * 32, i * 32);}
			window.draw(spr_map);
			window.draw(spr_coins);
			window.draw(backgr);

		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			dir = 1;
			speed = 0.15; 
			spr_hero.setTextureRect(IntRect(92, 49, -46, 46));}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			dir = 0;
			speed = 0.15;
			spr_hero.setTextureRect(IntRect(46, 49, 46, 46));}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			dir = 3;
			speed = 0.15;
			spr_hero.setTextureRect(IntRect(46, 294, 46, -46));}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			dir = 2;
			speed = 0.15;
			spr_hero.setTextureRect(IntRect(46, 245, 46, 46));}
		x = update(time, dir, speed, x, y)[0];
		y = update(time, dir, speed, x, y)[1];
		dx = update(time, dir, speed, x, y)[2];
		dy = update(time, dir, speed, x, y)[3];
		x=inter_with_map(dx, dy, x, y)[0];
		y= inter_with_map(dx, dy, x, y)[1];
		spr_hero.setPosition(x, y);
		window.draw(spr_hero);
		window.display();
	}
	return 0;
}