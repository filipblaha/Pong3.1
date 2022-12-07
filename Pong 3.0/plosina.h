#pragma once
#include "Hraci_pole.h"
class Plosina
{
public:
	Hraci_pole pole;
	int velikost_plosina;
	int x_plosina;

	Plosina()
	{
		velikost_plosina = 6;
		x_plosina = (pole.DELKA - velikost_plosina) / 2;
	}


private:
};
