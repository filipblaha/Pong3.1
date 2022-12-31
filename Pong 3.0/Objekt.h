#pragma once
#include "HraciPole.h"

class Objekt
{
public:
	HraciPole pole;
	Commands set;
	Objekt()
	{

	}

	int x = 0;
	int y = 0;
	double x_d = 0;
	double y_d = 0;
	int ax = 0;
	int ay = 0;


	const wchar_t* skin = 0;
};