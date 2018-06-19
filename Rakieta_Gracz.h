#pragma once

#include "Rakieta.h"

class Rakieta_Gracz : public Rakieta
{
public:
	Rakieta_Gracz(int id_pojazdu);
	void Odswiez();
private:
	int id_pojazdu;
};