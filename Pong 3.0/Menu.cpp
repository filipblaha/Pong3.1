#include "Menu.h"

//-----------------------  Input  -----------------------//

int Menu::VstupMenu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		OznaceniSmazani();
		{
			if ((oznaceni.at(y) > zavory.at(0)) && (strana == profil_e/**/))
			{
				if (oznaceni.at(y) <= 12)
				{
					oznaceni.at(y) -= 2;
				}
				return posun;
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
		}
		break;
	}
	case 's':
	{
		OznaceniSmazani();
		{
			if ((oznaceni.at(y) < zavory.at(1)) && (strana == profil_e/**/))
			{
				if (oznaceni.at(y) < 12)
				{
					oznaceni.at(y) += 2;
				}
				return posun;
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
		}
		break;
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
		{
			if (oznaceni.at(x) < zavory.at(3) && (strana == vzhled_plosiny_e))
			{
				oznaceni.at(x) += 10;
			}
			return posun;
		}
		break;
	}
	case '\r':
	{
		{
			return enter;
		}
		break;
	}
	case ' ':
	{
		{
			/*if (strana == -1)
			{
				return exit;
			}*/
		}
		break;
	}
	case 'q':
	{
		{
			if (strana == profil_e)
			{
				return exit;
			}
		}
		break;
	}
	}
}
int Menu::JazykSet(bool zmena)
{
	std::vector<int> v = profil.nacteni_dat_profilu(0);
	std::vector<int> d;
	d.push_back(0);

	if (zmena)
	{
		if (v.at(0) == CZ)
			d.push_back(1);
		if (v.at(0) == EN)
			d.push_back(0);
	}
	else
	{
		d.push_back(v.at(0));
	}

	profil.ulozeni_profilu(0, d);
	v = profil.nacteni_dat_profilu(0);
	return v.at(0);
}

//-----------------------  Vykresleni  -----------------------//

void Menu::MenuSTARTVykresleni()
{
	_setmode(_fileno(stdout), _O_U16TEXT);  // nastaveni graficke vizualizace
	set.setCursorPosition(0, 0);
	////////////    vykreslovani plocha    ////////////
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 0 && i == 0)
			{
				std::wcout << L"\x2554";
			}
			else if (i == 0 && j == vyska_menu - 1)
			{
				std::wcout << L"\x255a";
			}
			else if (j == 0 && i == delka_menu - 1)
			{
				std::wcout << L"\x2557";
			}
			else if (j == vyska_menu - 1 && i == delka_menu - 1)
			{
				std::wcout << L"\x255d";
			}
			else if (j == 0 || j == vyska_menu - 1)
			{
				std::wcout << L"\x2550";
			}
			else if (i == 0 || i == delka_menu - 1)
			{
				std::wcout << L"\x2551";
			}
			else
			{
				std::wcout << ' ';
			}
		}
		if (!(j == vyska_menu - 1))
			std::wcout << '\n';
	}
}
void Menu::OznaceniVykresleni()
{
	set.setCursorPosition(oznaceni.at(x), oznaceni.at(y));
	std::wcout << L"\x25ba";
}
void Menu::OznaceniSmazani()
{
	set.setCursorPosition(oznaceni.at(x), oznaceni.at(y));
	std::wcout << ' ';
}
void Menu::OtazkaSmazani()
{
	set.setCursorPosition(5, 2);
	std::wcout << "                               ";
	set.setCursorPosition(26, 3);
	std::wcout << "       ";
}

//-----------------------  Profil  -----------------------//

int Menu::IndexProfilu(int inkrement)
{
	int index = 0;
	std::list<std::string> temp = profil.nacteni_jmen_profilu();
	std::list<std::string>::iterator itr = temp.begin();
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
std::list<std::string> Menu::AktualNazevProfilu(int index, int poradi, int inkrement, bool del)
{
	std::list<std::string> temp = profil.nacteni_jmen_profilu();
	std::list<std::string>::iterator itr = temp.begin();
	
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
	return aktual;
}
