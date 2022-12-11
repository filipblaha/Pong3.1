#pragma once
#include <vector>
#include <list>

#include "tinyxml2.h"
#include "Commands.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;

class Profily
{
public:

	Profily()
	{
		pouzit = 0;
		jazyk = CZ;
		plosina_skin = 0;
		highscore_cas = 0;
		highscore_znicenych_bloku = 0;
		level = 0;
		exp = 0;
	}

	enum jazyk_e
	{
		CZ,
		EN,
	};

	int pocet_profilu_s = 0;

	int pouzit;
	int jazyk;
	int plosina_skin;
	int highscore_cas;
	int highscore_znicenych_bloku;
	int level;
	int exp;

	std::list<std::string>::iterator itr;
	std::list<std::string> nazev_profil;

	int ulozeni_profilu(int profil, bool zmena_jmena = 0);
	std::vector<int> nacteni_dat_profilu(int profil);
	std::list<std::string> nacteni_jmen_profilu();
	void nacteni_poctu_profilu();

	std::vector<int> vlozeni_dat_do_vektoru(int profil);
	void vlozeni_jmen_do_vektoru(int profil, std::list<std::string> &nazev_profil);
	void zmena_jmeno_profilu(int profil);
};