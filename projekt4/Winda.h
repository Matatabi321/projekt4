#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>

class Winda
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Sprite> osoby;
	sf::Sprite osoba1, osoba2, osoba3, osoba4, osoba5;
	sf::Texture ludzik1, ludzik2, ludzik3, ludzik4, ludzik5;
	sf::Event event;
	sf::RectangleShape liftshaft, lift, floor;
	float lvl=600;
	std::queue<float> liftLVL;
	
	//definuja okno
	void ivariables();
	void iwindow();
	void initpas();

public:
	//konstruktor destrukor
	 Winda();
	 virtual ~Winda();

	const bool run() const;
	int cordy(int numer);
	//void eventupdate();
	int which(int numer, int diff);
	void update();
	void render();
	void Movement();
	void robpas(int numer, int diff);	
};

