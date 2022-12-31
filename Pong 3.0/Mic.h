#pragma once
#include "Objekt.h"

class Mic : public Objekt
{
public:
	Mic()
	{
		x = x_d = start_x;
		y = y_d = start_y;
		ax = 1;
		ay = -1;
		skin = L"\x058e";
	}

	const int start_x = pole.delka / 2;
	const int start_y = pole.vyska - 5;
};