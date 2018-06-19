#include "Rakieta_Gracz.h"

Rakieta_Gracz::Rakieta_Gracz(int ktoryGracz)
{
	this->id_pojazdu = ktoryGracz;
	switch (this->id_pojazdu)
	{
	case 0:
		this->wgrajElement("statek1.png");
		break;
	default:
		this->wgrajElement("statek2.png");
		break;
	}
}

void Rakieta_Gracz::Odswiez()
{
	switch (this->id_pojazdu)
	{
	case 0:
		this->predkosc.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		break;
	
	}
	Element::Odswiez();

	if (this->getPosition().y < 0)
	{
		this->move(0, 1.5f);
	}
	if (this->getPosition().y + this->getGlobalBounds().height > 800)
	{
		this->move(0, -1.5f);
	}
}
