#pragma once
#include "HraciPole.h"

using namespace std;
class Mic
{
public:
	HraciPole pole;

	Mic()
	{
		x = start_x;
		y = start_y;
		ax = 1;
		ay = -1;
		skin = L"\x058e";
	}

	int x;
	int y;
	int ax;
	int ay;

	const int start_x = pole.delka / 2;
	const int start_y = pole.vyska - 5;

	const wchar_t* skin;
};