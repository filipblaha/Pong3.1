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
		_setmode(_fileno(stdout), _O_U16TEXT);  // nastaveni graficke vizualizace

		pocet_profilu = NacteniPoctuProfilu();
	}

	int pocet_profilu;
	int jsem_v_profilu;

	int jazyk;
	int level;
	int exp;
	int plosina_skin;
	int highscore_cas;
	int highscore_znicenych_bloku;

	int cas;
	int pocet_bloku;
	int pocet_rozbitych_bloku;

	char pohyb_vlevo;
	char pohyb_vpravo;
	char pouziti_schopnosti;
	char pauza;


	//-----------------------  Ulozeni profilu  -----------------------//

	void UlozeniProfilu(int profil);

	void VytvoreniNovehoProfilu(string nazev_noveho_profilu);
	void OdstraneniProfilu(int profil);

	//-----------------------  Nacteni profilu  -----------------------//

	vector<vector<int>> NacteniDat();
	vector<vector<char>> NacteniOvladani();
	int NacteniPoctuProfilu();
	list<int> NacteniUrovniProfilu();
	vector<int> NacteniDatProfilu(int profil);
	vector<char> NacteniOvladaniProfilu(int profil);
	list<string> NacteniNazvuProfilu();

	void VybraniProfilu(int profil);

	//-----------------------  Nacteni Skinu  -----------------------//

	vector<wstring> NacteniSkiny();

	//-----------------------  Zmena jmena  -----------------------//

	void ZmenaNazvu(string jmeno, int profil);

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
	enum jazyk_e
	{
		CZ,
		EN,
	};

	list<string>::iterator itrs;
	list<vector<int>>::iterator itri;
	list<vector<char>>::iterator itrc;

	void ZapsaniProfilu(list<string> nazev, list<vector<int>> data, list<vector<char>> ovladani);
	void ZapsaniDatAOvladaniProfilu(list<vector<int>> data, list<vector<char>> ovladani);
	void ZapsaniNazvuProfilu(list<string> nazev);
	vector<int> VlozeniDatDoVektoru();
	vector<char> VlozeniOvladaniDoVektoru();
};