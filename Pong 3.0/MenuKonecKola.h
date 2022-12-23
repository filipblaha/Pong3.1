#pragma once
#include "Menu.h"
#include "HerniMody.h"
class MenuKonecKola : public Menu
{
public:
	Commands set;

	MenuKonecKola(Profily& data)
	{
		n_exp = 0;

		set.Prechod(delka_menu, vyska_menu);
		set.SetFont(0, 20);
		set.SetWindow(delka_menu, vyska_menu - 2);
	}

	bool VstupKonecKola();
	void Logika(Profily& data, bool vyhra);
	void TextVykresleniVyhra(Profily& data);
	void TextVykresleniProhra(Profily& data);
	void VykresleniKonecKola(Profily& data);
	void VykresleniLevelBar();

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
	int n_exp;
	vector<int> exp_pole;
};

