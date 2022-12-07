#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <fcntl.h>
#include <io.h> // graficke knihovny

//#include "Profily.h"
//#include "Plosina.h"
#include "Commands.h"


class Menu
{
public:
	Menu()
	{}
	Menu(int strana, int x = 0, int y = 0, int horni_z = 0, int dolni_z = 0, int leva_z = 0, int prava_z = 0)
	{
		Commands set;

		oznaceni.push_back(x); // oznaceni a jeho zavory jednotlivych stran
		oznaceni.push_back(y);

		zavory.push_back(horni_z);
		zavory.push_back(dolni_z);
		zavory.push_back(leva_z);
		zavory.push_back(prava_z);


		_setmode(_fileno(stdout), _O_U16TEXT);  // nastaveni graficke vizualizace
		set.prechod();
		set.font(0, 20);
		set.SetWindow(delka_menu, vyska_menu - 2);


		vykresleni_menu_start();
		vykresleni_oznaceni();
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
	};
	enum vstup
	{
		exit,
		enter,
		del,
	};
	enum jazyk_e
	{
		CZ,
		EN,
	};
	int jazyk = CZ;

	std::vector<int> zavory;
	std::vector<int> oznaceni;


	void vykresleni_menu_start();
	void vykresleni_oznaceni();
	void smazani_oznaceni();


	/////////////////////    Input     //////////////////////////
	int vstup_menu(int strana);
	int rozhodovac(int strana, int prikaz);


	//void vykresleni_otazka();
	void smazani_otazka();



};
