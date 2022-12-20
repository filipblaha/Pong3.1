#pragma once
#include <iostream>
#include <vector>
#include "Commands.h"

using namespace std;
class HraciPole
{
public:
	Commands set;

	HraciPole()
	{
		zed_skin = L"\x2588";
		blok1_skin = L"\x2591";
		blok2_skin = L"\x2592";
		blok3_skin = L"\x2593";

		set.Font(20, 20);
		set.SetWindow(delka, vyska);
		set.Prechod();
	}

	const int delka = 20;
	const int vyska = 20;

	const wchar_t* zed_skin;
	const wchar_t* blok1_skin;
	const wchar_t* blok2_skin;
	const wchar_t* blok3_skin;

};