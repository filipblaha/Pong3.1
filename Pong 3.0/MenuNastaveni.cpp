#include "MenuNastaveni.h"

//-----------------------  Input  -----------------------//

int MenuNastaveni::Rozhodovac(Profily& data, int prikaz)
{
	if (oznaceni.at(y) == 10)
	{
		return ovladani_e;
	}
	if (oznaceni.at(y) == 12)
	{
		SpodniZavoraSet();
		if (!balic)
		{
			balic = 1; 
			return balic_e;
		}
		if (balic)
		{
			balic = 0;
			return balic_e;
		}
	}
	if (oznaceni.at(y) == 14 || oznaceni.at(y) == 16)
	{
		JazykSet(data);

		balic = 0;

		set.Prechod();
		MenuSTARTVykresleni();
		NastaveniVykresleni(data);

		return balic_e;
	}
}

//-----------------------  Vykresleni -----------------------//

void MenuNastaveni::NastaveniVykresleni(Profily& data)
{
	OznaceniVykresleni();
	VykresleniUroven(data);
	TextNastaveniVykresleni(data);
}
void MenuNastaveni::TextNastaveniVykresleni(Profily& data)
{
	text = transl.NacteniTextNastaveni(data);

	///-------  Text  -------//

	set.SetCursorPosition(15, 4);
	wcout << text.at(0);
	set.SetCursorPosition(6, 10);
	wcout << text.at(1);
	set.SetCursorPosition(6, 12);
	wcout << text.at(2);

	if (balic)
	{
		set.SetCursorPosition(9, 14);
		wcout << text.at(3);
		set.SetCursorPosition(9, 16);
		wcout << text.at(4);
	}
	else
	{
		set.SetCursorPosition(9, 14);
		wcout << "        ";
		set.SetCursorPosition(9, 16);
		wcout << "        ";
	}
}

//-----------------------  Set -----------------------//

void MenuNastaveni::SpodniZavoraSet()
{
	OznaceniSmazani();
	if (!balic)
	{
		oznaceni.at(x) = 4;
		oznaceni.at(y) = 10;

		zavory.at(0) = 10;
		zavory.at(1) = 12;
	}
	else
	{
		oznaceni.at(x) = 6;
		oznaceni.at(y) = 14;

		zavory.at(0) = 14;
		zavory.at(1) = 16;
	}
}