#include <SFML\Graphics.hpp>
using namespace sf;

RenderWindow menu_window(sf::VideoMode(800, 600), "Menu");
int menu(Text score_text) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\New Game.png");
	menuTexture2.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\Exit.png");
	menuBackground.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\cute.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menuback(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(40, 60);
	menu2.setPosition(80, 200);
	menuback.setScale(1.5, 1.5);
	menuback.setPosition(0, 0);
	//score_text.setFillColor(Color(179, 179, 179));
	score_text.setFillColor(Color::Black);
	score_text.setPosition(110, 500);
	while (isMenu)
	{
		Event event;
		while (menu_window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				menu_window.close();
		}
		menu1.setColor(Color::Black);
		menu2.setColor(Color::Black);
		menuNum = 0;
		menu_window.clear(Color(255, 200, 227));

		if (IntRect(40, 60, 500, 70).contains(Mouse::getPosition(menu_window))) { menu1.setColor(Color(255, 200, 227)); menuNum = 1; }
		if (IntRect(80, 200, 500, 70).contains(Mouse::getPosition(menu_window))) { menu2.setColor(Color(255, 200, 227)); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { menu_window.close(); return 0; }
			if (menuNum == 2) {isMenu = false; return 0;
		}//если нажали вторую кнопку, то выходим из меню 

		}
		menu_window.draw(menuback);
		menu_window.draw(menu1);
		menu_window.draw(menu2);
		menu_window.draw(score_text);
		menu_window.display();
	}
	return 0;
}