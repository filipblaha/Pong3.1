#include "MenuHlavni.h"

//-----------------------  Input  -----------------------//

int MenuHlavni::Rozhodovac(Profily& data)
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

void MenuHlavni::HlavniVykresleni(Profily& data)
{
	LogoHlavniVykresleni();
	OznaceniVykresleni();
	VykresleniUroven(data);
	TextHlavniVykresleni(data);
}
void MenuHlavni::LogoHlavniVykresleni()
{
	int m = 10;
	int n = 2;
	set.SetCursorPosition(m, n);
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 3 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 || i == 18)
					wcout << L"\x2588";
				else if (i == 1 || i == 2 || i == 6 || i == 7 || i == 16 || i == 17)
					wcout << L"\x2580";
				else
				{
					if (i < 19)
						wcout << ' ';
				}
			}
		}
	}
	set.SetCursorPosition(m, n + 1);
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 3 || i == 5 || i == 8 || i == 10 || i == 11 || i == 13 || i == 15)
					wcout << L"\x2588";
				else
				{
					if (i < 19)
						wcout << ' ';
				}
			}
		}
	}
	set.SetCursorPosition(m, n + 2);
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 5 || i == 8 || i == 10 || i == 12 || i == 13 || i == 15 || i == 18)
					wcout << L"\x2588";
				else if (i > 0 && i < 4 || i == 17)
					wcout << L"\x2580";
				else
				{
					if (i < 19)
						wcout << ' ';
				}
			}
		}
	}
	set.SetCursorPosition(m, n + 3);
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 || i == 18)
					wcout << L"\x2588";
				else if (i == 6 || i == 7 || i == 16 || i == 17)
					wcout << L"\x2584";
				else
				{
					if (i < 19)
						wcout << ' ';
				}
			}
		}
	}
}
void MenuHlavni::TextHlavniVykresleni(Profily& data)
{
	text = transl.NacteniTextHlavni(data);

	///-------  Text  -------//

	set.SetCursorPosition(6, 10);
	wcout << text.at(0);
	set.SetCursorPosition(6, 12);
	wcout << text.at(1);
	set.SetCursorPosition(6, 14);
	wcout << text.at(2);
	set.SetCursorPosition(2, 18);
	wcout << text.at(3) << "3.0";
}