#include "MenuVzhledPlosiny.h"

//-----------------------  Input  -----------------------//

int MenuVzhledPlosiny::VstupMenu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) > zavory.at(0))
		{
			oznaceni.at(y)--;
		}

		return posun;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y)++;
		}
		return posun;
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
int MenuVzhledPlosiny::Rozhodovac(int prikaz)
{
	if (oznaceni.at(y) == 10)
	{
		return herni_mody_e;
	}
	if (oznaceni.at(y) == 12)
	{
		return vzhled_plosiny_e;
	}
	if (oznaceni.at(y) == 14)
	{
		return nastaveni_e;
	}
}

//-----------------------  Vykresleni -----------------------//

void MenuVzhledPlosiny::VzhledPlosinyVykresleni(int jazyk)
{
	/*set.SetCursorPosition(7, 10);
	std::wcout << "IIIIII";

	if (navod_menu.level >= navod_menu.potr_urov1)
	{
		set.SetCursorPosition(17, 10);
		std::wcout << "======";
	}
	else
	{
		set.SetCursorPosition(17, 10);
		std::wcout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov2)
	{
		set.SetCursorPosition(27, 10);
		std::wcout << "FELZCU";
	}
	else
	{
		set.SetCursorPosition(27, 10);
		std::wcout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov3)
	{
		set.SetCursorPosition(7, 14);
		std::wcout << "8====D";
	}
	else
	{
		set.SetCursorPosition(7, 14);
		std::wcout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov4)
	{
		set.SetCursorPosition(17, 14);
		std::wcout << char(174) << char(174) << char(174) << char(175) << char(175) << char(175);
	}
	else
	{
		set.SetCursorPosition(17, 14);
		std::wcout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov5)
	{
		set.SetCursorPosition(27, 14);
		std::wcout << "______";
	}
	else
	{
		set.SetCursorPosition(27, 14);
		std::wcout << "??????";
	}*/

	OznaceniVykresleni();
	TextVzhledPlosinyVykresleni(jazyk);
}
void MenuVzhledPlosiny::TextVzhledPlosinyVykresleni(int jazyk)
{
	transl.jazyk = jazyk;
	text = transl.NacteniTextVzhledPlosiny();

	///-------  Text  -------//

	set.SetCursorPosition(13, 3);
	std::wcout << text.at(0);
	set.SetCursorPosition(18, 3);
	std::wcout << text.at(1);
}