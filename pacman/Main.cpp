#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "map.h"
#include "menu.h"
#include "opening.h"
#include <sstream>
#include <windows.h>
using namespace sf;
int score = 0;
int life = 1;
int flag = 1;
//int level_time = 20;
RenderWindow window(sf::VideoMode(800, 600), "Pacman");
float x = 60;
float y = 35;
float* inter_with_map(float dx, float dy, float x, float y) {
	int w = 29;
	int h = 29;//sprite size
	for (int i = y / 32; i < (y + h) / 32; i++)
	for (int j = x / 32; j < (x + w) / 32; j++)
	{
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
			if (dx > 0) {
				x = j * 32 - w;//stopped a hero
				float coord[2] = { x,y };
				return coord;
			}
			if (dx < 0) {//go to the left
				x = j * 32 + 32;
				float coord[2] = { x,y };
				return coord;
			}
		}
		if (TileMap[i][j] == '1') {
			TileMap[i][j] = ' ';
			score++;
			float coord[2] = { x,y };
			return coord;
		}
		if (TileMap[i][j] == 'b') {
			TileMap[i][j] = ' ';
			score+=20;
			float coord[2] = { 60,35 };
			return coord;
		}
		if (TileMap[i][j] == 'd') {
			TileMap[i][j] = ' ';
			score+=40;
			float coord[2] = { x,y };
			return coord;
		}
	}
	float coord[2] = { x,y };
	return coord;
}
float* update(float time, int dir, float speed, float x, float y)
{
	float dx, dy;
	dx = dy = 0.5;
	switch (dir)
	{
	case 0: dx = speed; dy = 0; break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
	case 1: dx = -speed; dy = 0; break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
	case 2: dx = 0; dy = speed; break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
	case 3: dx = 0; dy = -speed; break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
	}
	x += dx * time;
	y += dy * time;

	float back[4] = { x, y,dx,dy };
	return back;
}
void check_button(float time,Sprite spr_hero){
	float dx, dy;
	int dir = 0;
	float speed = 0;
	if (Keyboard::isKeyPressed(Keyboard::Left) && life) {
	dir = 1;
	speed = 0.15;
	spr_hero.setTextureRect(IntRect(92, 49, -43, 40));
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && life) {
		dir = 0;
		speed = 0.15;
		spr_hero.setTextureRect(IntRect(46, 49, 43, 40));
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && life) {
		dir = 3;
		speed = 0.15;
		spr_hero.setTextureRect(IntRect(46, 294, 43, -40));
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && life) {
		dir = 2;
		speed = 0.15;
		spr_hero.setTextureRect(IntRect(46, 245, 43, 40));
	}
	x = update(time, dir, speed, x, y)[0];
	y = update(time, dir, speed, x, y)[1];
	dx = update(time, dir, speed, x, y)[2];
	dy = update(time, dir, speed, x, y)[3];
	x = inter_with_map(dx, dy, x, y)[0];
	y = inter_with_map(dx, dy, x, y)[1];
	spr_hero.setPosition(x, y);
	window.draw(spr_hero);
}

int main() {
	if (flag == 1) statements();
	flag = 0;
	int life = 1;
	int level_time = 20;
	Image map_image, hero_image, coins_image, death_image, bonus_image;
	map_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\tileset1.png");
	hero_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\hero.png");
	coins_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\coins.png");
	death_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\death.png");
	bonus_image.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\bonuses.png");
	Texture map, herotexture, coins, death, bonus;
	map.loadFromImage(map_image);
	coins.loadFromImage(coins_image);
	herotexture.loadFromImage(hero_image);
	death.loadFromImage(death_image);
	bonus.loadFromImage(bonus_image);
	Sprite spr_map, spr_hero, spr_coins, spr_death, spr_diamond, spr_cherry;
	spr_map.setTexture(map);
	spr_hero.setTexture(herotexture);
	spr_hero.setTextureRect(IntRect(48, 49, 40, 43));
	spr_hero.scale(0.7f, 0.75f);
	spr_coins.setTexture(coins);
	spr_coins.setTextureRect(IntRect(32, 0, 30, 30));
	spr_coins.scale(0.5f, 0.5f);
	spr_cherry.setTexture(bonus);
	spr_diamond.setTexture(bonus);
	spr_diamond.setTextureRect(IntRect(0, 290, 50, 50));
	spr_cherry.setTextureRect(IntRect(50, 0, 40, 45));
	spr_cherry.scale(0.7f, 0.6f);
	spr_diamond.scale(0.7f, 0.6f);

	RectangleShape backgr(Vector2f(32.f, 32.f));
	backgr.setFillColor(Color::Black);
	Font font;
	font.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\font\\bold_font.ttf");
	Text score_text("", font, 30);
	Text timer_text("", font, 30);
	Text menuScore("", font, 30);
	timer_text.setFillColor(Color::Black);
	score_text.setFillColor(Color::Black);

	Clock clock;
	Clock gametime;

	int playtime=0;
	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;

		std::ostringstream player_score, gameTimeString;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++) {
				if (TileMap[i][j] == ' ') { backgr; backgr.setPosition(j * 32, i * 32); }
				if (TileMap[i][j] == '0') { spr_map.setTextureRect(IntRect(64, 0, 32, 32)); spr_map.setPosition(j * 32, i * 32); }
				if (TileMap[i][j] == '1') { spr_coins; spr_coins.setPosition(j * 32, i * 32); }
				if (TileMap[i][j] == 'b') { spr_cherry; spr_cherry.setPosition(j * 32, i * 32); }
				if (TileMap[i][j] == 'd') { spr_diamond; spr_diamond.setPosition(j * 32, i * 32); }
				window.draw(spr_map);
				window.draw(spr_coins);
				window.draw(spr_diamond);
				window.draw(spr_cherry);
				window.draw(backgr);
				score_text.setPosition(30, 0);
				timer_text.setPosition(500, 0);
			}
		check_button(time, spr_hero);
		player_score << score;
		score_text.setString("Score:" + player_score.str());
		menuScore.setString("Your Score:" + player_score.str());
		playtime = gametime.getElapsedTime().asSeconds();

		if (playtime == level_time) life = 0;

		if (!life) {
			spr_death.setTextureRect(IntRect(0, 110, 43, 40));
			spr_hero = spr_death;
			playtime = level_time;
			window.close();
			menu(menuScore);
			return main();
		}
		gameTimeString << playtime;
		timer_text.setString("Time:" + gameTimeString.str());
		window.draw(score_text);
		window.draw(timer_text);
		window.display();
	}
	return 0;
}