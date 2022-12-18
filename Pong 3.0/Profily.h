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
		jsem_v_profilu = 0;
		pocet_profilu = NacteniPoctuProfilu();
		VybraniProfilu(0);
	}

	enum jazyk_e
	{
		CZ,
		EN,
	};

	int pocet_profilu;
	int jsem_v_profilu;

	int jazyk;
	int level;
	int exp;
	int plosina_skin;
	int highscore_cas;
	int highscore_znicenych_bloku;


	//-----------------------  Ukladani profilu  -----------------------//

	void UlozeniProfilu(int profil);
	vector<int> VlozeniDatDoVektoru();

	void VytvoreniNovehoProfilu(string nazev_noveho_profilu);
	void OdstraneniProfilu(int profil);

	int ZapsaniProfilu(list<vector<int>> data, list<string> nazvy);

	//-----------------------  Nacteni profilu  -----------------------//

	vector<vector<int>> NacteniDat();
	int NacteniPoctuProfilu();
	list<int> NacteniUrovniProfilu();
	vector<int> NacteniDatProfilu(int profil);
	list<string> NacteniJmenProfilu();

	void VybraniProfilu(int profil);
	void PrepsaniDat(int& jazyk_v,int& plosina_skin, int& highscore_cas, int& highscore_znicenych_bloku, int& level, int& exp);

	//-----------------------  Zmena jmena  -----------------------//

	void ZmenaJmena(string jmeno, int profil);

private:
	list<string>::iterator itr;
	list<vector<int>>::iterator itri;
};