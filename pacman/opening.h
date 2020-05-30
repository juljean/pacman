#include <SFML\Graphics.hpp>
using namespace sf;

RenderWindow open_window(sf::VideoMode(800, 600), "Opening");
int statements() {
	Texture stat1, stat2, stat3, stat_st, menuBackground;
	stat1.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\cherry_st.png");
	stat2.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\diamond_st.png");
	stat3.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\limit.png");
	stat_st.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\Start.png");
	menuBackground.loadFromFile("C:\\Users\\Jul\\Documents\\vs projects\\pacman\\tile\\cute.jpg");
	Sprite cherry(stat1), diamond(stat2), limit(stat3), start(stat_st), menuback(menuBackground);
	bool isOpening = 1;
	int menuNum = 0;
	cherry.setScale(0.7f, 0.7f);
	diamond.setScale(0.7f, 0.7f);
	limit.setScale(0.7f, 0.7f);
	start.setScale(0.7f, 0.7f);

	cherry.setPosition(-40, 20);
	diamond.setPosition(-20, 160);
	limit.setPosition(-30, 300);
	start.setPosition(200, 480);
	menuback.setScale(1.5, 1.5);
	menuback.setPosition(0, 0);

	while (isOpening)
	{
		Event event;
		while (open_window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				open_window.close();
		}
		cherry.setColor(Color::Black);
		diamond.setColor(Color::Black);
		limit.setColor(Color::Black);
		start.setColor(Color::Black);
		menuNum = 0;
		open_window.clear(Color(255, 200, 227));

		if (IntRect(200, 500, 100, 70).contains(Mouse::getPosition(open_window))) { start.setColor(Color(255, 200, 227)); menuNum = 1; }

		if (Mouse::isButtonPressed(Mouse::Left)&& menuNum==1)
		{
			open_window.close(); return 0;
		}
		open_window.draw(menuback);
		open_window.draw(cherry);
		open_window.draw(diamond);
		open_window.draw(limit);
		open_window.draw(start);
		open_window.display();
	}
	return 0;
}