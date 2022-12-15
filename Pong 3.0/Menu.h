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

		set.Font(0, 20);
		set.SetWindow(delka_menu, vyska_menu - 2);
		set.Prechod();

		MenuSTARTVykresleni();
	}

	const int delka_menu = 40;
	const int vyska_menu = 20;


	enum jazyk_e
	{
		CZ,
		EN,
	};
	enum menu_strana
	{
		profil_e = 3,
		hlavni_e,
		herni_mody_e,
		vzhled_plosiny_e,
		nastaveni_e,
		ovladani_e,
		konec_kola_e,
	};
	enum herni_mody
	{
		klasik_e = 10,
		bloky_padaji_e,
		rogue_like_e,
	};
	enum vstup
	{
		exit = 13,
		enter,
		posun,
		del,
		balic_e,
	};
	enum souradnice
	{
		x,
		y,
	};

	vector<int> zavory;
	vector<int> oznaceni;
	list<string> aktual;

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
	void AktualNazevProfilu(int index, int poradi, int inkrement = 0, bool del = 0);
private:
};
