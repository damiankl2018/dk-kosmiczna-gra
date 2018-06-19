#include "w_Menu.h"
#include "Tura.h"


void Tura::Rozpocznij(sf::RenderWindow* okno)
{
	this->font = new sf::Font();
	this->font->loadFromFile("Przedmioty/font.ttf");
	this->wynikgraczaA = new info_Wynik(*font, 32);
	this->wynikgraczaB = new info_Wynik(*font, 32);

	this->napisNaprzerwe = new sf::Text("Gra wstrzymana", *font, 64U);
	this->napisNaprzerwe->setOrigin(this->napisNaprzerwe->getGlobalBounds().width / 2, this->napisNaprzerwe->getGlobalBounds().height / 2);
	this->napisNaprzerwe->setPosition(okno->getSize().x / 2, okno->getSize().y / 2);

	this->wynikgraczaB->setPosition(okno->getSize().x - this->wynikgraczaB->getGlobalBounds().width, 0);

	this->graczA = new Rakieta_Gracz(0);
	this->graczB = new Rakieta_Auto(1);
	this->meteor = new skala(this->wynikgraczaA, this->wynikgraczaB, this->graczA, this->graczB);
	this->graczB->wezSkale(this->meteor);

	this->meteor->Kasuj(okno);

	this->wstrzymana = false;
	this->wcisniety = false;
}
void Tura::Odswiez(sf::RenderWindow* okno)
{
	if (this->wstrzymana)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && !this->wcisniety)
		{
			this->wstrzymana = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			Rozgrywka.generujStan(new w_Menu());
		}
	}
	else
	{
		this->meteor->Odswiez(okno);
		this->graczA->Odswiez();
		this->graczB->Odswiez();
		this->wynikgraczaA->pokaz_Wynik();
		this->wynikgraczaB->pokaz_Wynik();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && !this->wcisniety)
		{
			this->wstrzymana = true;
		}
	}

	this->wcisniety = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
}
void Tura::Renderuj(sf::RenderWindow* okno)
{
	okno->draw(*this->meteor);
	okno->draw(*this->graczA);
	okno->draw(*this->graczB);
	okno->draw(*this->wynikgraczaA);
	okno->draw(*this->wynikgraczaB);

	if (this->wstrzymana)
	{
		okno->draw(*this->napisNaprzerwe);
	}
}
void Tura::Zniszcz(sf::RenderWindow* okno)
{
	delete this->graczA;
	delete this->graczB;
	delete this->meteor;
	delete this->wynikgraczaA;
	delete this->wynikgraczaB;

	delete this->font;
}
