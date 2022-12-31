#pragma once
#include "Objekt.h"

class Bomba : public Objekt
{
public:
	Bomba()
	{
		Start();
		rychlost = 3;

		skin = L"\x263c";
	}

	int spawn_cas = 0;
	const int start_x = set.Random(2, pole.delka - 3);
	const int start_y = pole.vyska / 2 + 2;

	void Start();
	void SpawnPozice();
	int SpawnCas();
};