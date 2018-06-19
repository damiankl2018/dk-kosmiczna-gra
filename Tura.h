#pragma once

#include "Stan.h"
#include "Rakieta_Gracz.h"
#include "Rakieta_Auto.h"
#include "skala.h"
#include "wynik.h"

class Tura : public Podstan

{
public:
	void Rozpocznij(sf::RenderWindow* okno);
	void Odswiez(sf::RenderWindow* okno);
	void Renderuj(sf::RenderWindow* okno);
	void Zniszcz(sf::RenderWindow* okno);
private:
	Rakieta_Gracz* graczA;
	Rakieta_Auto* graczB;
	skala* meteor;
	info_Wynik* wynikgraczaA;
	info_Wynik* wynikgraczaB;
	sf::Text* napisNaprzerwe;
	sf::Font* font;

	bool wstrzymana, wcisniety;
};