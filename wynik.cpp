#include "wynik.h"

info_Wynik::info_Wynik(sf::Font &font, int size) : sf::Text("Punkty: 0", font, size)
{
	this->tyle = 0;
}

void info_Wynik::zwieksz_Wynik()
{
	this->tyle += 1;
}

void info_Wynik::pokaz_Wynik()
{
	this->setString("Punktów: " + std::to_string(this->tyle));
}