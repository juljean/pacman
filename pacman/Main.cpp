#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "map.h"
using namespace sf;

void inter_with_map(float dx, float dy, float time) {
	float y = dy * time;
	float x = dx * time;
	int w = 46;
	int h = 46;//sprite size
	for (int i = y/32; i < (y + h)/32; i++) 
	for (int j = x/32; j < (x + w)/32; j++)
	{
		if (TileMap[i][j] == '0') {
			std::cout << "HUY ";
			if (dy > 0) {//go down
				y = i * 32 - h;//stopped a hero
			}
			if (dy < 0) {//go up
				y = i * 32 + 32;
			}
			if (dx > 0) {//go to the right
				x = j * 32 - w;//stopped a hero
			}
			if (dx < 0) {//go to the left
				x = j * 32 + 32;
			}
		}
	}
}

float update(float time, int dir, float speed, Sprite spr_hero, float x, float y) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
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
	spr_hero.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	return x, y;
}

int main() {
	RenderWindow window(sf::VideoMode(800, 600), "Pacman");
	Image map_image, hero_image;
	map_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\tileset1.png");
	hero_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\hero.png");
	Texture map, herotexture;
	map.loadFromImage(map_image);
	herotexture.loadFromImage(hero_image);
	Sprite spr_map, spr_hero;
	spr_map.setTexture(map);
	spr_hero.setTexture(herotexture);
	spr_hero.setTextureRect(IntRect(46, 49, 46, 46));
	spr_hero.scale(0.8f, 0.8f);
	spr_hero.setPosition(50, 30);

	Clock clock;

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		float x, y;
		x = y = 0;
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == ' ') spr_map.setTextureRect(IntRect(95, 0, 32, 32));
			if (TileMap[i][j] == '0') spr_map.setTextureRect(IntRect(64, 0, 32, 32));

			spr_map.setPosition(j * 32, i * 32);
			window.draw(spr_map);
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) { int dir = 1; float speed = 0.15; spr_hero.setTextureRect(IntRect(92, 49, -46, 46)); x,y=update(time, dir, speed, spr_hero, x, y); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { int dir = 1; float speed = 0.15; spr_hero.setTextureRect(IntRect(46, 49, 46, 46)); x, y = update(time, dir, speed, spr_hero, x, y);}
		if (Keyboard::isKeyPressed(Keyboard::Up)) { int dir = 1; float speed = 0.15;  spr_hero.setTextureRect(IntRect(46, 294, 46, -46)); x, y = update(time, dir, speed, spr_hero, x, y);}
		if (Keyboard::isKeyPressed(Keyboard::Down)) { int dir = 1; float speed = 0.15;  spr_hero.setTextureRect(IntRect(46, 245, 46, 46)); x, y = update(time, dir, speed, spr_hero, x, y);}

		window.draw(spr_hero);
		window.display();
	}
	return 0;
}