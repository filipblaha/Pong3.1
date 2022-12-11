#include "Menu.h"


void Menu::vykresleni_menu_start()
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
void Menu::vykresleni_oznaceni()
{
	set.setCursorPosition(oznaceni.at(x), oznaceni.at(y));
	std::wcout << L"\x25ba";
}
void Menu::smazani_oznaceni()
{
	set.setCursorPosition(oznaceni.at(x), oznaceni.at(y));
	std::wcout << ' ';
}



//void Menu::vykresleni_otazka()
//{
//	set.setCursorPosition(5, 2);
//	if (!jazyk)
//		std::wcout << smazani_pokrok_otazka1CZ;
//	if (jazyk)
//		std::wcout << smazani_pokrok_otazka1EN;
//	set.setCursorPosition(26, 3);
//	if (!jazyk)
//		std::wcout << smazani_pokrok_otazka2CZ;
//	if (jazyk)
//		std::wcout << smazani_pokrok_otazka2EN;
//}
void Menu::smazani_otazka()
{
	set.setCursorPosition(5, 2);
	std::wcout << "                               ";
	set.setCursorPosition(26, 3);
	std::wcout << "       ";
}


/////////////////////    Input     //////////////////////////
int Menu::vstup_menu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		smazani_oznaceni();
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
		smazani_oznaceni();
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
		smazani_oznaceni();
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
		smazani_oznaceni();
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
int Menu::rozhodovac(int strana, int prikaz)
{
	////////    Profily     ////////
	if (strana == profil_e)
	{
		int index = 0;
		if (oznaceni.at(y) == 8)
			index = index_profilu();
		if (oznaceni.at(y) == 10)
			index = index_profilu(1);
		if (oznaceni.at(y) == 12)
			index = index_profilu(2);

		if (prikaz == enter)
		{
			if (index == 0)
			{
				
			}
			else
			{
				ulozena_data = profil.nacteni_dat_profilu(index);
				return enter;
			}
		}

	}
}


void Menu::aktual_nazev_profilu_start()
{
	aktual = profil.nacteni_jmen_profilu();

	while (aktual.size() > 3)
	{
		aktual.pop_back();
	}
}
std::list<std::string> Menu::aktual_nazev_profilu(int inkrement)
{
	std::list<std::string> temp = profil.nacteni_jmen_profilu();
	std::list<std::string>::iterator itr = temp.begin();
	while (*itr != *aktual.begin())
	{
		itr++;
	}
	if (inkrement == 1)
		itr++;
	if (inkrement == -1)
		itr--;
	

	aktual.clear();
	for (int i = 0; i < 3; i++)
	{
		aktual.push_back(*itr);
		itr++;
	}
	return aktual;
}
int Menu::index_profilu(int inkrement)
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