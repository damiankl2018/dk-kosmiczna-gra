#pragma once

#include "Rakieta.h"
#include "skala.h"

class Rakieta_Auto : public Rakieta
{
public:
	Rakieta_Auto(int id_pojazdu);
	void wezSkale(skala* skalka);
	void Odswiez();
private:
	skala* meteor;
	int id_pojazdu;
	float predkosc_komp;
};