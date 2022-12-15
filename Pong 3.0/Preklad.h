#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <fcntl.h>
#include <io.h>

#include "Tinyxml2.h"

using namespace tinyxml2;
using namespace std;

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

	vector<string> vektor_stringu;
	vector<wstring> vektor_wstringu;

	//-----------------------  Premena string na wstring  -----------------------//

	vector<wstring> StringToWString(vector<string> s);
	list<wstring> StringToWStringList(list<string> s);

	//-----------------------  Nacteni textu  -----------------------//

	vector<wstring> NacteniTextProfil();
	vector<wstring> NacteniTextHlavni();
	vector<wstring> NacteniTextHerniMody();
	vector<wstring> NacteniTextVzhledPlosiny();
	vector<wstring> NacteniTextNastaveni();
	vector<wstring> NacteniTextOvladani();
	vector<wstring> NacteniTextKonecKola();
};

