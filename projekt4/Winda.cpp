#include "Winda.h"
#include <iostream>
#include <Windows.h>

void Winda::ivariables()
{
	this->window= nullptr;
}

void Winda::iwindow()
{
	//definuje okno ktore sie wyswietla
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 960), "Winda", sf::Style::Titlebar | sf::Style::Close);
}

const bool Winda::run() const
{
	//sprawdzam czy okno jest otwarte
	return this->window->isOpen();
}

/*void Winda::eventupdate()
{
	//Zamyka okni kiedy klikniesz X mozna taez dodac inne guziki
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}


	uznalem ze za madre to usunalem funkcje

}*/
int Winda::which(int numer,int diff)
{
	int n=1;

	switch (numer)
	{
	case 1:

		if (diff <= 40) n = 5;
		else if (diff <= 80) n = 4;
		else if (diff <= 120) n = 3;
		else if (diff <= 160) n = 2;
		break;

	case 2:
		if (diff <= 40) n = 5;
		else if (diff <= 80) n = 4;
		else if (diff <= 120) n = 3;
		else if (diff <= 160) n = 1;

		break;
	case 3:
		if (diff <= 40) n = 5;
		else if (diff <= 80) n = 4;
		else if (diff <= 120) n = 2;
		else if (diff <= 160) n = 1;

		break;
	case 4:
		if (diff <= 40) n = 5;
		else if (diff <= 80) n = 3;
		else if (diff <= 120) n = 2;
		else if (diff <= 160) n = 1;

		break;
	case 5:
		if (diff <= 40) n = 4;
		else if (diff <= 80) n = 3;
		else if (diff <= 120) n = 2;
		else if (diff <= 160) n = 1;

		break;
	}

	return n;
}

void Winda::update()
{
	int diff;
	//this->eventupdate();
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}

	
	/*
		sprawdza czy guzik byl klikniety i puszczony

		-sprawdza na ktorym pietrze byl
		-wysyla to do funkcji which() roznice
		-which() w zaleznosci od roznicy sprawdza ktore pietro

		(wyswietla sie w kolejnosci na ktorym pietrze co wcisniete)
	*/

	std::cout<<sf::Mouse::getPosition(*this->window).x<<" "<< sf::Mouse::getPosition(*this->window).y <<"\n";
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		Sleep(30);//bo inaczej przytrzymanie spami (bez tego jak klikniesz raz to wyswietlaja sie 3 komunikaty) jak masz pomysl na inaczej to zmien
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (sf::Mouse::getPosition(*this->window).x < 40 && sf::Mouse::getPosition(*this->window).y < 257 && sf::Mouse::getPosition(*this->window).x >0 && sf::Mouse::getPosition(*this->window).y >97)
			{
				diff = sf::Mouse::getPosition(*this->window).y - 97;
				std::cout << "guziki p5 w";
				std::cout << this->which(5, diff) << " ";
			}
			if (sf::Mouse::getPosition(*this->window).x < 40 && sf::Mouse::getPosition(*this->window).y < 534 && sf::Mouse::getPosition(*this->window).x >0 && sf::Mouse::getPosition(*this->window).y >374)
			{
				diff = sf::Mouse::getPosition(*this->window).y - 374;
				std::cout << "guziki p3 w";
				std::cout << this->which(3, diff) << " ";
			}
			if (sf::Mouse::getPosition(*this->window).x < 40 && sf::Mouse::getPosition(*this->window).y < 856 && sf::Mouse::getPosition(*this->window).x >0 && sf::Mouse::getPosition(*this->window).y >696)
			{
				diff = sf::Mouse::getPosition(*this->window).y - 696;
				std::cout << "guziki p1 w";
				std::cout << this->which(1, diff) << " ";
			}
			if (sf::Mouse::getPosition(*this->window).x < 1280 && sf::Mouse::getPosition(*this->window).y < 425 && sf::Mouse::getPosition(*this->window).x >1240 && sf::Mouse::getPosition(*this->window).y >265)
			{
				diff = sf::Mouse::getPosition(*this->window).y - 265;
				std::cout << "guziki p4 w";
				std::cout << this->which(4, diff) << " ";
			}
			if (sf::Mouse::getPosition(*this->window).x < 1280 && sf::Mouse::getPosition(*this->window).y < 710 && sf::Mouse::getPosition(*this->window).x >1240 && sf::Mouse::getPosition(*this->window).y >550)
			{
				diff = sf::Mouse::getPosition(*this->window).y - 550;
				std::cout << "guziki p2 w";
				std::cout << this->which(2, diff) << " ";
			}
		}
	}
}

void Winda::render()
{
	this->window->clear(sf::Color::White);

	//definiuje szyb windy
	this->liftshaft.setSize(sf::Vector2f(200.f, 950.f));
	this->liftshaft.setOutlineThickness(5.f);
	this->liftshaft.setOutlineColor(sf::Color::Black);
	this->liftshaft.setPosition(540.f, 5.f);

	//definiuje winde
	this->lift.setSize(sf::Vector2f(190.f, 250.f));
	this->lift.setOutlineThickness(3.f);
	this->lift.setOutlineColor(sf::Color::Red);
	this->lift.setPosition(545.f, 10.f);

	//definiuje pietra
	this->floor.setSize(sf::Vector2f(540.f, 5.f));
	this->floor.setFillColor(sf::Color::Black);

	this->floor.setPosition(0.f, 257.f);
	this->window->draw(this->floor);

	this->floor.setPosition(0.f, 534.f);
	this->window->draw(this->floor);

	this->floor.setPosition(0.f, 856.f);
	this->window->draw(this->floor);

	this->floor.setPosition(740.f, 710.f);
	this->window->draw(this->floor);

	this->floor.setPosition(740.f, 425.f);
	this->window->draw(this->floor);

	
	//rysuje przyciski do windy (każdy przycisk ma rozmiar 40x40
	sf::Texture obraz1;
	obraz1.loadFromFile("C:\\projekt winda\\tekstury\\obraz1.png");
	sf::Sprite przycisk1;
	przycisk1.setTexture(obraz1);
	przycisk1.setScale(0.08, 0.08);

	sf::Texture obraz2;
	obraz2.loadFromFile("C:\\projekt winda\\tekstury\\obraz2.png");
	sf::Sprite przycisk2;
	przycisk2.setTexture(obraz2);
	przycisk2.setScale(0.08, 0.08);

	sf::Texture obraz3;
	obraz3.loadFromFile("C:\\projekt winda\\tekstury\\obraz3.png");
	sf::Sprite przycisk3;
	przycisk3.setTexture(obraz3);
	przycisk3.setScale(0.08, 0.08);

	sf::Texture obraz4;
	obraz4.loadFromFile("C:\\projekt winda\\tekstury\\obraz4.png");
	sf::Sprite przycisk4;
	przycisk4.setTexture(obraz4);
	przycisk4.setScale(0.08, 0.08);

	sf::Texture obraz5;
	obraz5.loadFromFile("C:\\projekt winda\\tekstury\\obraz5.png");
	sf::Sprite przycisk5;
	przycisk5.setTexture(obraz5);
	przycisk5.setScale(0.08, 0.08);


	przycisk2.setPosition(0.f, 816.f);
	this->window->draw(przycisk2);
	przycisk3.setPosition(0.f, 776.f);
	this->window->draw(przycisk3);
	przycisk4.setPosition(0.f, 736.f);
	this->window->draw(przycisk4);
	przycisk5.setPosition(0.f, 696.f);
	this->window->draw(przycisk5);

	przycisk1.setPosition(0.f, 494.f);
	this->window->draw(przycisk1);
	przycisk2.setPosition(0.f, 454.f);
	this->window->draw(przycisk2);
	przycisk4.setPosition(0.f, 414.f);
	this->window->draw(przycisk4);
	przycisk5.setPosition(0.f, 374.f);
	this->window->draw(przycisk5);

	przycisk1.setPosition(0.f, 217.f);
	this->window->draw(przycisk1);
	 przycisk2.setPosition(0.f, 177.f);
	 this->window->draw(przycisk2);
	 przycisk3.setPosition(0.f, 137.f);
	 this->window->draw(przycisk3);
	 przycisk4.setPosition(0.f, 97.f);
	 this->window->draw(przycisk4);

	przycisk1.setPosition(1240.f, 670.f);
	this->window->draw(przycisk1);
	przycisk3.setPosition(1240.f, 630.f);
	this->window->draw(przycisk3);
	przycisk4.setPosition(1240.f, 590.f);
	this->window->draw(przycisk4);
	przycisk5.setPosition(1240.f, 550.f);
	this->window->draw(przycisk5);

	przycisk1.setPosition(1240.f, 385.f);
	this->window->draw(przycisk1);
	przycisk2.setPosition(1240.f, 345.f);
	this->window->draw(przycisk2);
	przycisk3.setPosition(1240.f, 305.f);
	this->window->draw(przycisk3);
	przycisk5.setPosition(1240.f, 265.f);
	this->window->draw(przycisk5);

	//rysuje winnde i szyb
	this->window->draw(this->liftshaft);
	this->window->draw(this->lift);
	this->window->display();
}

Winda::Winda()
{
	this->ivariables();
	this->iwindow();
}
Winda::~Winda()
{
	delete this->window;
}


