#include <iostream>
#include "w_Menu.h"
#include "Tura.h"

void w_Menu::Rozpocznij(sf::RenderWindow* okno)
{
	this->wybrany = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("Przedmioty/font.ttf");

	this->tytul = new sf::Text("Kosmiczna kolizja", *this->font, 128U);
	this->tytul->setOrigin(this->tytul->getGlobalBounds().width / 2, this->tytul->getGlobalBounds().height / 2);
	this->tytul->setPosition(okno->getSize().x / 2, okno->getSize().y / 8);

	this->graj = new sf::Text("Gram", *this->font, 64U);
	this->graj->setOrigin(this->graj->getGlobalBounds().width / 2, this->graj->getGlobalBounds().height / 2);
	this->graj->setPosition(okno->getSize().x / 2, okno->getSize().y / 4);

	this->wyjdz = new sf::Text("Uciekam", *this->font, 64U);
	this->wyjdz->setOrigin(this->wyjdz->getGlobalBounds().width / 2, this->wyjdz->getGlobalBounds().height / 2);
	this->wyjdz->setPosition(okno->getSize().x / 2, okno->getSize().y / 4 + 2*this->graj->getGlobalBounds().height);
}
void w_Menu::Odswiez(sf::RenderWindow* okno)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		this->wybrany -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		this->wybrany += 1;
	}
	if (this->wybrany > 1)
	{
		this->wybrany = 0;
	}
	if (this->wybrany < 0)
	{
		this->wybrany = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->wybrany)
		{
		case 0:
			Rozgrywka.generujStan(new Tura());
			break;
		case 1:
			czyWyjsc = true;
			break;
		}
	}
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}
void w_Menu::Renderuj(sf::RenderWindow* okno)
{
	this->graj->setFillColor(sf::Color::Black);
	this->wyjdz->setFillColor(sf::Color::Black);
	switch (this->wybrany)
	{
	case 0:
		this->graj->setFillColor(sf::Color::Red);
		break;
	case 1:
		this->wyjdz->setFillColor(sf::Color::Red);
		break;
	}
	okno->draw(*this->tytul);
	okno->draw(*this->graj);
	okno->draw(*this->wyjdz);
}
void w_Menu::Zniszcz(sf::RenderWindow* okno)
{
	delete this->font;
	delete this->tytul;
	delete this->graj;
	delete this->wyjdz;
}
