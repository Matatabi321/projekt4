#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Winda
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::RectangleShape liftshaft, lift, floor;
	
	//definuja okno
	void ivariables();
	void iwindow();

public:
	//konstruktor destrukor
	 Winda();
	 virtual ~Winda();

	const bool run() const;
	void eventupdate();
	void update();
	void render();
};

