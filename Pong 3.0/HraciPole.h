#pragma once
#include <iostream>
#include <vector>
#include "Commands.h"
class Hraci_pole
{
public:
	Commands set;
	int DELKA = 20;
	int VYSKA = 20;
	Hraci_pole()
	{
		set.SetWindow(DELKA, VYSKA);
	}
	

private:

	
	
};