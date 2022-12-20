#pragma once
#include "HraciPole.h"

using namespace std;
class Mic
{
public:
	HraciPole pole;

	Mic()
	{
		pohyb = 0;
		x = pole.delka / 2;
		y = pole.vyska - 5;
		ax = 1;
		ay = -1;
		skin = L"\x058e";
	}

	int pohyb;
	int x;
	int y;
	int ax;
	int ay;

	const wchar_t* skin;
};