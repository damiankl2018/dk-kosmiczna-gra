#include "skala.h"

skala::skala(info_Wynik* wynikgraczaA, info_Wynik* wynikgraczaB, Rakieta* graczA, Rakieta* graczB)
{
	this->graczA = graczA;
	this->graczB = graczB;
	this->wynikgraczaA = wynikgraczaA;
	this->wynikgraczaB = wynikgraczaB;
	this->wgrajElement("skala.png");
	
}

void skala::Odswiez(sf::RenderWindow* okno)
{
	if (this->czyKontakt(this->graczA))
	{
		this->predkosc.x *= -1;
		if (this->predkosc.y > 0)
		{
			if (this->graczA->predkosc.y > 0)
			{
				this->predkosc.y += this->predkosc.y * 1.25f;
			}
			else if (this->graczA->predkosc.y < 0)
			{
				this->predkosc.y += this->predkosc.y * -1.25f;
			}
		}
		else if (this->predkosc.y < 0)
		{
			if (this->graczA->predkosc.y > 0)
			{
				this->predkosc.y += this->predkosc.y * -1.25f;
			}
			else if (this->graczA->predkosc.y < 0)
			{
				this->predkosc.y += this->predkosc.y * 1.25f;
			}
		}
	
	}
	if (this->czyKontakt(this->graczB))
	{
		this->predkosc.x *= -1;
		if (this->predkosc.y > 0)
		{
			if (this->graczB->predkosc.y > 0)
			{
				this->predkosc.y += this->predkosc.y * 1.25f;
			}
			else if (this->graczB->predkosc.y < 0)
			{
				this->predkosc.y += this->predkosc.y * -1.25f;
			}
		}
		else if (this->predkosc.y < 0)
		{
			if (this->graczB->predkosc.y > 0)
			{
				this->predkosc.y += this->predkosc.y * -1.25f;
			}
			else if (this->graczB->predkosc.y < 0)
			{
				this->predkosc.y += this->predkosc.y * 1.25f;
			}
		}

	}
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height >okno->getSize().y)
	{
		this->predkosc.y *= -1;
		
	}

	if (this->getPosition().x < this->graczA->getGlobalBounds().width - 5)
	{
		this->wynikgraczaB->zwieksz_Wynik();
		this->Kasuj(okno);
	}
	if (this->getPosition().x + this->getGlobalBounds().width > okno->getSize().x - this->graczB->getGlobalBounds().width + 5)
	{
		this->wynikgraczaA->zwieksz_Wynik();
		this->Kasuj(okno);
	}
	Element::Odswiez();
}

void skala::Kasuj(sf::RenderWindow* okno)
{
	this->predkosc.x = 1.0f;
	this->predkosc.y = ((rand() % 2) == 0) ? 1.2f : -1.2f;
	this->setPosition(okno->getSize().x / 2, okno->getSize().y / 2);
	this->graczA->setPosition(0, okno->getSize().y / 2 - this->graczA->getGlobalBounds().height / 2);
	this->graczB->setPosition(okno->getSize().x - this->graczB->getGlobalBounds().width, okno->getSize().y / 2 - this->graczB->getGlobalBounds().height / 2);
}

skala::~skala()
{
	

}