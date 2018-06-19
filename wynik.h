#pragma once

#include <SFML/Graphics.hpp>

class info_Wynik : public sf::Text
{
public:
	info_Wynik(sf::Font &font, int size);
	void pokaz_Wynik();
	void zwieksz_Wynik();
private:
	int tyle;
};