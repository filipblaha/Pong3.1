#include "Menu.h"

//-----------------------  Input  -----------------------//

int Menu::VstupMenu()
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
		else
		{
			oznaceni.at(y) = zavory.at(1);
		}
		return 1;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y) += 2;
		}
		else
		{
			oznaceni.at(y) = zavory.at(0);
		}
		return 1;
	}
	case '\r':
	{
		return enter;
	}
	case 'q':
	{
		set.Prechod();
		return exit;
	}
	}
}
void Menu::JazykSet(Profily& data)
{
	if (data.jazyk == CZ)
		data.jazyk = EN;
	else if (data.jazyk == EN)
		data.jazyk = CZ;
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
void Menu::VykresleniUroven(Profily data)
{
	text = transl.NacteniTextProfil(data);
	set.SetCursorPosition(27, 17);
	std::wcout << text.at(9) << data.level;
	set.SetCursorPosition(17, 18);
	for (int i = 0; i < exp_pole.size(); i++)
	{
		if (exp_pole.at(i) == 2)
			std::wcout << L"\x2588";
		if (exp_pole.at(i) == 0)
			std::wcout << L"\x2591";
	}
}

//-----------------------  Profil  -----------------------//

int Menu::IndexProfilu(int inkrement)
{
	int index = 0;
	list<string> temp = data.NacteniJmenProfilu();
	list<string>::iterator itr = temp.begin();
	while (*itr != *aktual_nazvy.begin())
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
void Menu::AktualNazevProfilu(Profily data, int index, int poradi, int inkrement, bool del)
{
	list<string> temps = data.NacteniJmenProfilu();
	list<int> tempi = data.NacteniUrovniProfilu();
	list<string>::iterator itrs = temps.begin();
	list<int>::iterator itri = tempi.begin();
	
	if (del)
	{
		if (poradi == 0 || (poradi == 2 && index == data.pocet_profilu && data.pocet_profilu >= 3) || (poradi == 1 && index + 1 == data.pocet_profilu && data.pocet_profilu >= 3))
		{
			inkrement = 1;
		}
	}
	advance(itrs, index - poradi);
	advance(itri, index - poradi);
	if (inkrement == -1)
	{
		itrs++;
		itri++;
	}
	if (inkrement == 1)
	{
		itrs--;
		itri--;
	}
	

	aktual_nazvy.clear();
	aktual_urovne.clear();
	int n = 0;
	if (data.pocet_profilu >= 3)
		n = 3;
	else
		n = data.pocet_profilu;
	for (int i = 0; i < n; i++)
	{
		aktual_nazvy.push_back(*itrs);
		itrs++;
		aktual_urovne.push_back(*itri);
		itri++;
	}
}


//-----------------------  Exp  -----------------------//

void Menu::NaplneniExpBar(Profily data)
{
	for (int i = 0; i < data.exp; i++)
	{
		exp_pole.push_back(2);
	}
	for (int i = 0; i < 20 - data.exp; i++)
	{
		exp_pole.push_back(0);
	}
}
