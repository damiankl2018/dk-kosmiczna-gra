#pragma once

#include "Rakieta.h"
#include "wynik.h"

class skala : public Element
{
public:
	skala(info_Wynik* wynikgraczaA, info_Wynik* wynikgraczaB, Rakieta* graczA, Rakieta* graczB);
	void Odswiez(sf::RenderWindow* okno);
	void Kasuj(sf::RenderWindow* okno);
	~skala();
private:
	info_Wynik * wynikgraczaA;
	info_Wynik* wynikgraczaB;
	Rakieta* graczA;
	Rakieta* graczB;

	
};
