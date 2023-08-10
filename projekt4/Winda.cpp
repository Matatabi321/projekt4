#include "Winda.h"

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

void Winda::eventupdate()
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
}

void Winda::update()
{
	this->eventupdate();
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


