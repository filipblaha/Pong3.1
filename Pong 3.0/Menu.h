#pragma once
#include <conio.h>

#include "Commands.h"
#include "Profily.h"
#include "Preklad.h"

class Menu
{
public:
	Preklad transl;
	Commands set;
	Profily profil;

	Menu()
	{}
	Menu(int strana, int x = 0, int y = 0, int horni_z = 0, int dolni_z = 0, int leva_z = 0, int prava_z = 0)
	{
		Commands set;

		oznaceni.push_back(x);
		oznaceni.push_back(y);

		zavory.push_back(horni_z);
		zavory.push_back(dolni_z);
		zavory.push_back(leva_z);
		zavory.push_back(prava_z);

		set.font(0, 20);
		set.SetWindow(delka_menu, vyska_menu - 2);
		set.prechod();
	}

	const int delka_menu = 40;
	const int vyska_menu = 20;

	enum menu_strana
	{
		profil_e,
		hlavni_e,
		herni_mody_e,
		vzhled_plosiny_e,
		nastaveni_e,
		ovladani_e,
		konec_kola_e,
	};
	enum vstup
	{
		exit,
		enter,
		posun,
		del,
	};
	enum jazyk_e
	{
		CZ,
		EN,
	};
	enum souradnice
	{
		x,
		y,
	};


	std::vector<int> ulozena_data;
	std::vector<int> zavory;
	std::vector<int> oznaceni;
	std::list<std::string> aktual;


	//-----------------------  Input  -----------------------//

	int VstupMenu(int strana);
	int JazykSet(bool zmena = 0);

	//-----------------------  Vykresleni  -----------------------//

	void MenuSTARTVykresleni();
	void OznaceniVykresleni();
	void OznaceniSmazani();
	void OtazkaSmazani();

	//-----------------------  Profil  -----------------------//

	int IndexProfilu(int inkrement = 0);
	void AktualNazevProfiluSTART();
	std::list<std::string> AktualNazevProfilu(int index, int poradi, int inkrement = 0, bool del = 0);
private:
};
