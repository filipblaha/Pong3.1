#include "Menu.h"

//-----------------------  Input  -----------------------//

int Menu::VstupMenu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) > zavory.at(0))
		{
			oznaceni.at(y) -= 2;
		}
		/*if ((oznaceni.at(y) > zavory.at(0)) && (strana == 0 || strana == 1))
			{
				oznaceni.at(y) -= 2;
			}

			if ((oznaceni.at(y) > zavory.at(0)) && (strana == 2))
			{
				oznaceni.at(y) -= 4;
			}
			if ((oznaceni.at(y) > zavory.at(0)) && (strana == 3))
			{
				if (oznaceni.at(y) <= 12)
				{
					oznaceni.at(x) = 4;
				}
				else
				{
					oznaceni.at(x) = 7;
				}
				oznaceni.at(y) -= 2;
			}
			if ((oznaceni.at(y) > zavory.at(0)) && (strana == 4))
			{
				oznaceni.at(y) = oznaceni.at(y)--;
			}*/
		return posun;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y) += 2;
		}
		/*if ((oznaceni.at(y) < zavory.at(1)) && (strana == 0 || strana == 1))
			{
				oznaceni.at(y) += 2;
			}
			if ((oznaceni.at(y) < zavory.at(1)) && (strana == 2))
			{
				oznaceni.at(y) += 4;
			}
			if ((oznaceni.at(y) < zavory.at(1)) && (strana == 3))
			{
				if (oznaceni.at(y) <= 8)
				{
					oznaceni.at(x) = 4;
				}
				else
				{
					oznaceni.at(x) = 7;
				}
				oznaceni.at(y) += 2;
			}
			if ((oznaceni.at(y) < zavory.at(1)) && (strana == 4))
			{
				oznaceni.at(y)++;
			}*/
		return posun;
	}
	case 'a':
	{
		OznaceniSmazani();
		{
			if (oznaceni.at(x) > zavory.at(2) && (strana == vzhled_plosiny_e))
			{
				oznaceni.at(x) -= 10;
			}
			return posun;
		}
		break;
	}
	case 'd':
	{
		OznaceniSmazani();
		if (oznaceni.at(x) < zavory.at(3) && (strana == vzhled_plosiny_e))
		{
			oznaceni.at(x) += 10;
		}
		return posun;
	}
	case '\r':
	{
		return enter;
	}
	case ' ':
	{
		/*if (strana == -1)
		{
			return exit;
		}*/
	}
	case 'q':
	{
		set.Prechod();
		return exit;
	}
	}
}
int Menu::JazykSet(bool zmena)
{
	vector<int> v = profil.nacteni_dat_profilu(profil.jsem_v_profilu);

	if (zmena)
	{
		if (v.at(0) == CZ)
			profil.jazyk = 1;
		if (v.at(0) == EN)
			profil.jazyk = 0;
	}
	return profil.jazyk;
}

//-----------------------  Vykresleni  -----------------------//

void Menu::MenuSTARTVykresleni()
{
	_setmode(_fileno(stdout), _O_U16TEXT);  // nastaveni graficke vizualizace
	set.SetCursorPosition(0, 0);
	////////////    vykreslovani plocha    ////////////
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 0 && i == 0)
			{
				wcout << L"\x2554";
			}
			else if (i == 0 && j == vyska_menu - 1)
			{
				wcout << L"\x255a";
			}
			else if (j == 0 && i == delka_menu - 1)
			{
				wcout << L"\x2557";
			}
			else if (j == vyska_menu - 1 && i == delka_menu - 1)
			{
				wcout << L"\x255d";
			}
			else if (j == 0 || j == vyska_menu - 1)
			{
				wcout << L"\x2550";
			}
			else if (i == 0 || i == delka_menu - 1)
			{
				wcout << L"\x2551";
			}
			else
			{
				wcout << ' ';
			}
		}
		if (!(j == vyska_menu - 1))
			wcout << '\n';
	}
}
void Menu::OznaceniVykresleni()
{
	set.SetCursorPosition(oznaceni.at(x), oznaceni.at(y));
	wcout << L"\x25ba";
}
void Menu::OznaceniSmazani()
{
	set.SetCursorPosition(oznaceni.at(x), oznaceni.at(y));
	wcout << ' ';
}
void Menu::OtazkaSmazani()
{
	set.SetCursorPosition(5, 2);
	wcout << "                               ";
	set.SetCursorPosition(26, 3);
	wcout << "       ";
}

//-----------------------  Profil  -----------------------//

int Menu::IndexProfilu(int inkrement)
{
	int index = 0;
	list<string> temp = profil.nacteni_jmen_profilu();
	list<string>::iterator itr = temp.begin();
	while (*itr != *aktual.begin())
	{
		itr++;
	}
	for (int i = 0; i < abs(inkrement); i++)
	{
		if (inkrement > 0)
			itr++;
		if (inkrement < 0)
			itr--;
	}

	while (itr != temp.begin())
	{
		index++;
		itr--;
	}
	return index;
}
void Menu::AktualNazevProfiluSTART()
{
	aktual = profil.nacteni_jmen_profilu();

	while (aktual.size() > 3)
	{
		aktual.pop_back();
	}
}
void Menu::AktualNazevProfilu(int index, int poradi, int inkrement, bool del)
{
	list<string> temp = profil.nacteni_jmen_profilu();
	list<string>::iterator itr = temp.begin();
	
	if (del)
	{
		if (poradi == 0 || (poradi == 2 && index == profil.pocet_profilu_s && profil.pocet_profilu_s >= 3) || (poradi == 1 && index + 1 == profil.pocet_profilu_s && profil.pocet_profilu_s > 3))
		{
			inkrement = 1;
		}
	}
	itr = temp.begin();
	advance(itr, index - poradi);
	if (inkrement == -1)
		itr++;
	if (inkrement == 1)
		itr--;
	

	aktual.clear();
	int n = 0;
	if (profil.pocet_profilu_s >= 3)
		n = 3;
	else
		n = profil.pocet_profilu_s;
	for (int i = 0; i < n; i++)
	{
		aktual.push_back(*itr);
		itr++;
	}
}
