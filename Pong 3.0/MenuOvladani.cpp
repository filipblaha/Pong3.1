#include "MenuOvladani.h"

//-----------------------  Input  -----------------------//

int MenuOvladani::VstupMenu(int strana)
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
int MenuOvladani::Rozhodovac(int prikaz)
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

void MenuOvladani::OvladaniVykresleni(int jazyk)
{
	set.SetCursorPosition(9, 7);
	std::wcout << "W";
	set.SetCursorPosition(7, 8);
	std::wcout << "A S D";
	set.SetCursorPosition(17, 8);
	set.SetCursorPosition(26, 8);
	std::wcout << "Q";

	set.SetCursorPosition(7, 12);
	for (int i = 0; i < 20;i++)
		std::wcout << ".";
	set.SetCursorPosition(7, 13);
	for (int i = 0; i < 20;i++)
		std::wcout << ".";
	set.SetCursorPosition(7, 14);
	for (int i = 0; i < 20;i++)
		std::wcout << ".";
	set.SetCursorPosition(7, 15);
	for (int i = 0; i < 20;i++)
		std::wcout << ".";

	OznaceniVykresleni();
	TextOvladaniVykresleni(jazyk);
}
void MenuOvladani::TextOvladaniVykresleni(int jazyk)
{
	transl.jazyk = jazyk;
	text = transl.NacteniTextOvladani();

	///-------  Text  -------//

	set.SetCursorPosition(15, 3);
	std::wcout << text.at(0);
	set.SetCursorPosition(6, 5);
	std::wcout << text.at(1);
	set.SetCursorPosition(17, 8);
	std::wcout << text.at(2);
	set.SetCursorPosition(6, 10);
	std::wcout << text.at(3);
	set.SetCursorPosition(7, 12);
	std::wcout << text.at(4);
	set.SetCursorPosition(29, 12);
	
	set.SetCursorPosition(7, 13);
	std::wcout << text.at(5);
	set.SetCursorPosition(29, 13);
	
	set.SetCursorPosition(7, 14);
	std::wcout << text.at(6);
	set.SetCursorPosition(29, 14);
	
	std::wcout << text.at(7);
	//std::wcout << (char)navod_menu.pouziti_schopnosti;

	set.SetCursorPosition(7, 15);
	std::wcout << text.at(8);
	set.SetCursorPosition(29, 15);
	std::wcout << "Esc";
	//std::wcout << (char)navod_menu.pauza;
}