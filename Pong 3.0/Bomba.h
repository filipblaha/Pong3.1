#pragma once
#include "Objekt.h"

class Bomba : public Objekt
{
public:
	Bomba()
	{

		x = x_d = start_x;
		y = y_d = start_y;
		ax = 0;
		ay = 1;
		skin = L"\x263c";
	}

	int start_x = 0;
	const int start_y = pole.vyska / 2 + 2;

	void PocatekPoziceBomba();
};