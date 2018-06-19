#pragma once

#include "Stan.h"

class w_Menu : public Podstan
{
public:
	void Rozpocznij(sf::RenderWindow* okno);
	void Odswiez(sf::RenderWindow* okno);
	void Renderuj(sf::RenderWindow* okno);
	void Zniszcz(sf::RenderWindow
		* okno);
private:
	sf::Font* font;
	sf::Text* tytul;
	sf::Text* graj;

	sf::Text* wyjdz;

	int wybrany;

	bool upKey, downKey;
};