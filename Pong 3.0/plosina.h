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
		data.plosina_skin = 1; //SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS//

		pohyb = 0;
		velikost = 6;
		x = (pole.delka - velikost) / 2;
		y = pole.vyska - 3;

		FormovaniSkiny();
	}

	int pohyb;
	int velikost;
	int x;
	int y;
	list<wchar_t> skin;

	void FormovaniSkiny();
};
