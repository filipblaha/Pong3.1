#pragma once
#include "Profily.h"


class Preklad
{
public:
	Profily data;
	Commands set;

	//-----------------------  Nacteni textu  -----------------------//

	vector<wstring> NacteniTextProfil(Profily data);
	vector<wstring> NacteniTextHlavni(Profily data);
	vector<wstring> NacteniTextHerniMody(Profily data);
	vector<wstring> NacteniTextSkiny(Profily data);
	vector<wstring> NacteniTextNastaveni(Profily data);
	vector<wstring> NacteniTextOvladani(Profily data);
	vector<wstring> NacteniTextKonecKola(Profily data);

private:///////////////////////////////////  PRIVATE  /////////////////////////////////////////

	enum jazyk_e
	{
		CZ,
		EN,
	};

	vector<string> vektor_stringu;
};

