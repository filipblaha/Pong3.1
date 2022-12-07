#include "Menu.h"

Commands set;

void Menu::vykresleni_menu_start()
{
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
	set.setCursorPosition(oznaceni.at(0), oznaceni.at(1));
	std::wcout << L"\x25ba";
}
void Menu::smazani_oznaceni()
{
	set.setCursorPosition(oznaceni.at(0), oznaceni.at(1));
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
			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 0))
			{
				if (oznaceni.at(1) <= 12)
				{
					oznaceni.at(1) -= 2;
				}
				else
				{
					oznaceni.at(1) -= 5;
					oznaceni.at(0) = 10;
				}
			}
			/*if ((oznaceni.at(1) > zavory.at(0)) && (strana == 0 || strana == 1))
			{
				oznaceni.at(1) -= 2;
			}

			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 2))
			{
				oznaceni.at(1) -= 4;
			}
			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 3))
			{
				if (oznaceni.at(1) <= 12)
				{
					oznaceni.at(0) = 4;
				}
				else
				{
					oznaceni.at(0) = 7;
				}
				oznaceni.at(1) -= 2;
			}
			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 4))
			{
				oznaceni.at(1) = oznaceni.at(1)--;
			}*/
		}
		break;
	}
	case 's':
	{
		smazani_oznaceni();
		{
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 0))
			{
				if (oznaceni.at(1) < 12)
				{
					oznaceni.at(1) += 2;
				}
				else
				{
					oznaceni.at(1) += 5;
					oznaceni.at(0) = 2;
				}
			}
			/*if ((oznaceni.at(1) < zavory.at(1)) && (strana == 0 || strana == 1))
			{
				oznaceni.at(1) += 2;
			}
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 2))
			{
				oznaceni.at(1) += 4;
			}
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 3))
			{
				if (oznaceni.at(1) <= 8)
				{
					oznaceni.at(0) = 4;
				}
				else
				{
					oznaceni.at(0) = 7;
				}
				oznaceni.at(1) += 2;
			}
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 4))
			{
				oznaceni.at(1)++;
			}*/
		}
		break;
	}
	case 'a':
	{
		smazani_oznaceni();
		{
			if (oznaceni.at(0) > zavory.at(2))
			{
				oznaceni.at(0) -= 10;
			}
		}
		break;
	}
	case 'd':
	{
		smazani_oznaceni();
		{
			if (oznaceni.at(0) < zavory.at(3))
			{
				oznaceni.at(0) += 10;
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
			if (strana == -1)
			{
				return exit;
			}
		}
		break;
	}
	case 'q':
	{
		{
			if (strana == 0)
			{
				return exit;
			}
			else if (strana == 4)
			{

			}
			else
			{

			}
		}
		break;
	}
	case char(8) :
	{
		if (strana == 0)
		{
			return del;
		}
		break;
	}
	default:
		break;
	}
}
//int Menu::rozhodovac(int strana, int prikaz)
//{
//	////////    Profily     ////////
//	if (strana == 0)
//	{
//		if (oznaceni.at(1) == 8)
//		{
//
//		}
//	}
//}