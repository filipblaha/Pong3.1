#pragma once
#include <iostream>
#include <vector>
#include "tinyxml2.h"
#include "menu.h"

using namespace tinyxml2;
class Preklad
{
public:

	Menu menu;

	int profil_stringu = 0;
	int hlavni_stringu = 0;
	int herni_mody_stringu = 0;
	int vzhled_plosiny_stringu = 0;
	int nastaveni_stringu = 0;
	int ovladani_stringu = 0;
	int konec_kola_stringu = 0;

	std::vector<std::wstring> vektor_stringu;

	std::vector<std::wstring> nacteni_textu_profil();
	std::vector<std::wstring> nacteni_textu_hlavni();
	std::vector<std::wstring> nacteni_textu_herni_mody();
	std::vector<std::wstring> nacteni_textu_vzhled_plosiny();
	std::vector<std::wstring> nacteni_textu_nastaveni();
	std::vector<std::wstring> nacteni_textu_ovladani();
	std::vector<std::wstring> nacteni_textu_konec_kola();
};

