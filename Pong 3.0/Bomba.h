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

		skin = L"\x263c";
		skin_start = L"\x25cc";
	}

	int spawn_cas = 0;
	bool existence_start = 0;
	int start_x = 0;
	const int start_y = pole.vyska / 2 + 2;

	const wchar_t* skin_start;

	void Start();
	void SpawnPozice();
	int SpawnCas();
};