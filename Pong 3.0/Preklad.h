#pragma once
#include "Profily.h"


class Preklad
{
public:
	Profily data;

	Preklad()
	{
		profil_stringu = 0;
		hlavni_stringu = 0;
		herni_mody_stringu = 0;
		vzhled_plosiny_stringu = 0;
		nastaveni_stringu = 0;
		ovladani_stringu = 0;
		konec_kola_stringu = 0;

	}
	enum jazyk_e
	{
		CZ,
		EN,
	};


	vector<string> vektor_stringu;
	vector<wstring> vektor_wstringu;

	//-----------------------  Premena string na wstring  -----------------------//

	vector<wstring> StringToWString(vector<string> s);
	list<wstring> StringToWStringList(list<string> s);

	//-----------------------  Nacteni textu  -----------------------//

	vector<wstring> NacteniTextProfil(Profily data);
	vector<wstring> NacteniTextHlavni(Profily data);
	vector<wstring> NacteniTextHerniMody(Profily data);
	vector<wstring> NacteniTextVzhledPlosiny(Profily data);
	vector<wstring> NacteniTextNastaveni(Profily data);
	vector<wstring> NacteniTextOvladani(Profily data);
	vector<wstring> NacteniTextKonecKola(Profily data);
private:
	int profil_stringu;
	int hlavni_stringu;
	int herni_mody_stringu;
	int vzhled_plosiny_stringu;
	int nastaveni_stringu;
	int ovladani_stringu;
	int konec_kola_stringu;
};

