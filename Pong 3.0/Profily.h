#pragma once
#include <vector>
#include <list>

#include "Tinyxml2.h"
#include "Commands.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;
using namespace std;

class Profily
{
public:

	Profily()
	{
		pocet_profilu_s = 0;
		jsem_v_profilu = 0;
	}

	enum jazyk_e
	{
		CZ,
		EN,
	};

	int pocet_profilu_s;
	int jsem_v_profilu;

	int jazyk = CZ;
	int level = 0;
	int exp = 0;
	int plosina_skin = 0;
	int highscore_cas = 0;
	int highscore_znicenych_bloku = 0;

	list<string>::iterator itr;
	list<vector<int>>::iterator itri;

	//-----------------------  Ukladani profilu  -----------------------//

	void ulozeni_profilu(int profil, vector<int> d = {0}, bool zmena_jmena = 0);
	vector<int> vlozeni_dat_do_vektoru(int profil, vector<int> d);

	void vytvoreni_noveho_profilu(string nazev_noveho_profilu);
	void odstraneni_profilu(int profil);

	int zapsani_profilu(list<int> uroven_profil, list<vector<int>> data, list<string> nazvy);

	//-----------------------  Nacteni profilu  -----------------------//

	void nacteni_poctu_profilu();
	list<int> nacteni_urovni_profilu();
	vector<int> nacteni_dat_profilu(int profil);
	list<string> nacteni_jmen_profilu();

	void vybraniprofilu(int profil);
	void prepsani_dat(int& jazyk_v,int& plosina_skin, int& highscore_cas, int& highscore_znicenych_bloku, int& level, int& exp);

	//-----------------------  Zmena jmena ?  -----------------------//
	
	//void zmena_jmeno_profilu(int profil);
};