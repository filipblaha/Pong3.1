#pragma once
#include "Objekt.h"

class Bomba : public Objekt
{
public:
	Bomba()
	{
		x = start_x;
		y = start_y;
		ax = 0;
		ay = 1;
		skin = L"\x263c";
	}

	int start_x;
	int start_y;
};