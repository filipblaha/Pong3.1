#pragma once
#include "Objekt.h"

class Bomba : public Objekt
{
public:
	Bomba()
	{
		Start();
		SpawnPozice();
		rychlost = 3;
		pocitadlo = 0;

		skin = L"\x263c";
		skin_start = L"\x25cc";
	}

	bool existence_start = 0;
	int spawn_cas = 0;
	int pocitadlo;

	int start_x = 0;
	const int start_y = pole.vyska / 2 + 2;

	const wchar_t* skin_start;

	void Start();
	void SpawnPozice();
	int SpawnCas();
};