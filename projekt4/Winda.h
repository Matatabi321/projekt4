#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include <iostream>
#include <Windows.h>
#include <queue>

class Winda
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::RectangleShape liftshaft, lift, floor;
	float lvl=600;
	std::queue<float> liftLVL;
	
	//definuja okno
	void ivariables();
	void iwindow();

public:
	//konstruktor destrukor
	 Winda();
	 virtual ~Winda();

	const bool run() const;
	//void eventupdate();
	int which(int numer, int diff);
	void update();
	void render();
	void Movement();
};

