#pragma once

#include <SFML/Graphics.hpp>
#include <string>


class Element: public sf::Sprite
{
public:
	sf::Vector2f predkosc;

	Element()
	{
		this->mapa = new sf::Texture();
	}

	void wgrajElement(std::string nazwa)
	{
		this->mapa->loadFromFile("Przedmioty/" + nazwa);
		this->setTexture(*this->mapa);
	}

	virtual void Odswiez()
	{
		this->move(this->predkosc);
	}

	bool czyKontakt(Element* przedmiot)
	{
		return this->getGlobalBounds().intersects(przedmiot->getGlobalBounds());
	}

	~Element()
	{
		delete this->mapa;
	}
private:
	sf::Texture* mapa;
};

