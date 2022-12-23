#pragma once
#include "Profily.h"
#include "HraciPole.h"

class Plosina
{
public:
	HraciPole pole;
	Plosina()
	{
		pohyb = 0;
		velikost = 6;
		x_start = (pole.delka - velikost) / 2;
		x = x_start;
		y = y_start;
	}

	int pohyb = 0;
	int velikost = 0;
	int x = 0;
	int y = 0;

	int x_start = 0;
	const int y_start = pole.vyska - 3;


	list<wchar_t> skin;

	void FormovaniSkiny(Profily& data);
};
