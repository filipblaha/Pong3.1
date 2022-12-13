#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <fcntl.h>
#include <io.h>

#include "tinyxml2.h"
using namespace tinyxml2;
class Preklad
{
public:

	Preklad()
	{
		profil_stringu = 0;
		hlavni_stringu = 0;
		herni_mody_stringu = 0;
		vzhled_plosiny_stringu = 0;
		nastaveni_stringu = 0;
		ovladani_stringu = 0;
		konec_kola_stringu = 0;

		jazyk = CZ;
	}

	enum jazyk_e
	{
		CZ,
		EN,
	};

	int profil_stringu;
	int hlavni_stringu;
	int herni_mody_stringu;
	int vzhled_plosiny_stringu;
	int nastaveni_stringu;
	int ovladani_stringu;
	int konec_kola_stringu;

	int jazyk;

	std::vector<std::string> vektor_stringu;
	std::vector<std::wstring> vektor_wstringu;

	//-----------------------  Premena string na wstring  -----------------------//

	std::vector<std::wstring> StringToWString(std::vector<std::string> s);
	std::list<std::wstring> StringToWStringList(std::list<std::string> s);

	//-----------------------  Nacteni textu  -----------------------//

	std::vector<std::wstring> NacteniTextProfil();
	std::vector<std::wstring> NacteniTextHlavni();
	std::vector<std::wstring> NacteniTextHerni_mody();
	std::vector<std::wstring> NacteniTextVzhled_plosiny();
	std::vector<std::wstring> NacteniTextNastaveni();
	std::vector<std::wstring> NacteniTextOvladani();
	std::vector<std::wstring> NacteniTextKonec_kola();
};

