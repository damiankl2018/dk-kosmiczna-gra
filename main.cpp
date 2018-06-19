
#include "w_Menu.h"
#include "Stan.h"


Stan Rozgrywka;
//czy wyj�� z gry
bool czyWyjsc = false;

int main()
{
	sf::RenderWindow okno(sf::VideoMode(1000,800), "Kosmiczna kolizja 2D");

	Rozgrywka.zbudujOkno(&okno);
	Rozgrywka.generujStan(new w_Menu());

	// najwazniejsze: program ma dzia�a�, jak d�ugo okno otwarte!
	while (okno.isOpen())
	{
		
		sf::Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			// zamykanie okna
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();
		}

		okno.clear(sf::Color::White);

		Rozgrywka.Odswiez();
		Rozgrywka.Renderuj();

		okno.display();

		if (czyWyjsc)
		{
			okno.close();
		}

		
	}

	return 0;
}
