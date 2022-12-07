#pragma once
#include <iostream>
#include <vector>

#include "tinyxml2.h"
#include "Commands.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;

class Profily
{
public:

	enum jazyk_e
	{
		CZ,
		EN,
	};

	int pouzit = 0;
	int jazyk = CZ;
	int plosina_skin = 0;
	int highscore_cas = 0;
	int highscore_znicenych_bloku = 0;
	int level = 0;
	int exp = 0;

	std::vector<std::string> jmena_profilu;

	int ulozeni_profilu(int profil, std::vector<std::string> nazev_profil);
	std::vector<std::vector<int>> nacteni_dat_profilu();
	std::vector<std::string> nacteni_jmen_profilu();

	void vlozeni_dat_do_vektoru(int profil, std::vector<std::vector<int>> &data_profil);
	void zmena_jmeno_profilu(int profil);

};