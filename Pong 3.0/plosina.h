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
		x_start = (pole.delka - velikost) / 2;
		x = x_start;
		y = y_start;


		FormovaniSkiny();
	}

	int pohyb;
	int velikost;
	int x;
	int y;

	int x_start;
	const int y_start = pole.vyska - 3;


	list<wchar_t> skin;

	void FormovaniSkiny();
};
