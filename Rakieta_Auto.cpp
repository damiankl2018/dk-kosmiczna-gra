#include "Rakieta_Auto.h"

Rakieta_Auto::Rakieta_Auto(int ktoryGracz)
{
	this->id_pojazdu = ktoryGracz;
	this->meteor = meteor;
	this->predkosc_komp = 0.90f;


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

void Rakieta_Auto::wezSkale(skala* meteor)
{
	this->meteor = meteor;
}

void Rakieta_Auto::Odswiez()
{
	if (this->meteor != NULL)
	{
		if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->meteor->getPosition().y)
		{
			this->predkosc.y = this->predkosc_komp/2;
		}
		if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->meteor->getPosition().y)
		{
			this->predkosc.y = -this->predkosc_komp/2;
		}
	}
	Element::Odswiez();

	if (this->getPosition().y < 0)
	{
		this->move(0, this->predkosc_komp);
	}
	if (this->getPosition().y + this->getGlobalBounds().height > 800)
	{
		this->move(0, -this->predkosc_komp);
	}
}
