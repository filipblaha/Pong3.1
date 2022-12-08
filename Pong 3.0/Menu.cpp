#include "Menu.h"

Commands set;
Profily profil;

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
			if ((oznaceni.at(y) > zavory.at(0)) && (strana == profil_e))
			{
				if (oznaceni.at(y) <= 12)
				{
					oznaceni.at(y) -= 2;
				}
				else
				{
					oznaceni.at(y) -= 5;
					oznaceni.at(x) = 10;
				}
			}
			else
			{
				//profil.nacteni_jmen_profilu()
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
			if ((oznaceni.at(y) < zavory.at(1)) && (strana == profil_e))
			{
				if (oznaceni.at(y) < 12)
				{
					oznaceni.at(y) += 2;
				}
				else
				{
					oznaceni.at(y) += 5;
					oznaceni.at(x) = 2;
				}
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
			if (oznaceni.at(x) > zavory.at(2))
			{
				oznaceni.at(x) -= 10;
			}
		}
		break;
	}
	case 'd':
	{
		smazani_oznaceni();
		{
			if (oznaceni.at(x) < zavory.at(3))
			{
				oznaceni.at(x) += 10;
			}
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
	case char(8) :
	{
		if (strana == profil_e)
		{
			return del;
		}
		break;
	}
	default:
		break;
	}
}
int Menu::rozhodovac(int strana, int prikaz)
{
	////////    Profily     ////////
	if (strana == profil_e)
	{
		if (oznaceni.at(y) == 8)
		{
			if (prikaz == enter)
			{
				profil.nacteni_dat_profilu();
				return enter;
			}
		}
	}
	return 0; //
}