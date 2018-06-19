#pragma once

#include <SFML/Graphics.hpp>

class Podstan
{
public:
	virtual void Rozpocznij(sf::RenderWindow* okno)
	{
	}

	virtual void Odswiez(sf::RenderWindow* okno)
	{
	}

	virtual void Renderuj(sf::RenderWindow* okno)
	{
	}

	virtual void Zniszcz(sf::RenderWindow* okno)
	{
	}
};

class Stan
{
public:
	Stan()
	{
		this->jeden_stan = NULL;
	}

	void zbudujOkno(sf::RenderWindow* okno)
	{
		this->okno = okno;
	}

	void generujStan(Podstan* jeden_stan)
	{
		if (this->jeden_stan != NULL)
		{
			this->jeden_stan->Zniszcz(this->okno);
		}
		this->jeden_stan = jeden_stan;
		if (this->jeden_stan != NULL)
		{
			this->jeden_stan->Rozpocznij(this->okno);
		}
	}

	void Odswiez()
	{
		if (this->jeden_stan != NULL)
		{
			this->jeden_stan->Odswiez(this->okno);
		}
	}
	void Renderuj()
	{
		if (this->jeden_stan != NULL)
		{
			this->jeden_stan->Renderuj(this->okno);
		}
	}

	~Stan()
	{
		if (this->jeden_stan != NULL)
		{
			this->jeden_stan->Zniszcz(this->okno);
		}
	}
private:
	sf::RenderWindow* okno;
	Podstan* jeden_stan;
};

extern Stan Rozgrywka;
extern bool czyWyjsc;

