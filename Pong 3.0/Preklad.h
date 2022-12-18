#pragma once
#include "Profily.h"


class Preklad
{
public:
	Profily data;

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
};

