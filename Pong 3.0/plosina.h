#pragma once
#include "Profily.h"
#include "HraciPole.h"

class Plosina
{
public:
	Profily data;
	HraciPole pole;

	Plosina()
	{
		data.plosina_skin = 0;
		skin = data.NacteniSkiny().at(4);

		pohyb = 0;
		velikost = 6;
		x = (pole.delka - velikost) / 2;
	}

	int pohyb;
	int velikost;
	int x;
	wstring skin;

private:
};
