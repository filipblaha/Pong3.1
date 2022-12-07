#pragma once
#include <iostream>
#include <vector>

#include "tinyxml2.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;

class Profily
{
public:

	/*int ulozeni_profilu(std::vector<std::vector<int>> data_profil, std::vector< std::vector<char>> nazev_profil);*/
	std::vector<std::vector<int>> nacteni_dat_profilu();
	std::vector<std::vector<char>> nacteni_jmen_profilu();
};