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

	int jazyk;
	int plosina_skin;
	int highscore_cas;
	int highscore_znicenych_bloku;
	int level;
	int exp;

	std::list<std::string>::iterator itr;
	std::list<std::vector<int>>::iterator itri;

	void ulozeni_profilu(int profil, std::vector<int> d = {0}, bool zmena_jmena = 0);
	void vytvoreni_noveho_profilu(std::string nazev_noveho_profilu);
	void odstraneni_profilu(int profil);
	int zapsani_profilu(std::list<int> uroven_profil, std::list<std::vector<int>> data, std::list<std::string> nazvy);

	std::vector<int> nacteni_dat_profilu(int profil);
	std::list<int> nacteni_urovni_profilu();
	std::list<std::string> nacteni_jmen_profilu();
	void nacteni_poctu_profilu();

	std::vector<int> vlozeni_dat_do_vektoru(int profil, std::vector<int> d);
	//void vlozeni_jmen_do_vektoru(int profil, std::list<std::string> &nazev_profil);
	//void zmena_jmeno_profilu(int profil);
};