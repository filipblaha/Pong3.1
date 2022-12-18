#include "MenuVzhledPlosiny.h"

//-----------------------  Input  -----------------------//

int MenuVzhledPlosiny::VstupMenu(Profily& data, int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) > zavory.at(0))
		{
			oznaceni.at(y) -= 4;
		}

		return posun;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y) += 4;
		}
		return posun;
	}
	case 'a':
	{
		OznaceniSmazani();
		if (oznaceni.at(x) > zavory.at(2))
		{
			oznaceni.at(x) -= 10;
		}
		return posun;
	}
	case 'd':
	{
		OznaceniSmazani();
		if (oznaceni.at(x) < zavory.at(3))
		{
			oznaceni.at(x) += 10;
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
int MenuVzhledPlosiny::Rozhodovac(Profily& data, int prikaz)
{
	if (oznaceni.at(y) == 9)
	{
		if (oznaceni.at(x) == 6)
		{
			if (data.level < potrebna_uroven.at(0))
				NedostatecnaUrovenVykresleni();
			else
				data.plosina_skin = 0;
		}
		if (oznaceni.at(x) == 16) 
		{
			if (data.level < potrebna_uroven.at(1))
				NedostatecnaUrovenVykresleni();
			else
				data.plosina_skin = 1;
		}
		if (oznaceni.at(x) == 26)
		{
			if (data.level < potrebna_uroven.at(2))
				NedostatecnaUrovenVykresleni();
			else
				data.plosina_skin = 2;
		}
	}
	else if (oznaceni.at(y) == 13)
	{

		if (oznaceni.at(x) == 6)
		{
			if (data.level < potrebna_uroven.at(3))
				NedostatecnaUrovenVykresleni();
			else
				data.plosina_skin = 3;
		}
		if (oznaceni.at(x) == 16)
		{
			if (data.level < potrebna_uroven.at(4))
				NedostatecnaUrovenVykresleni();
			else
				data.plosina_skin = 4;
		}
		if (oznaceni.at(x) == 26)
		{
			if (data.level < potrebna_uroven.at(5))
				NedostatecnaUrovenVykresleni();
			else
				data.plosina_skin = 5;
		}
	}
	return 1;
}

//-----------------------  Vykresleni -----------------------//

void MenuVzhledPlosiny::VzhledPlosinyVykresleni(Profily& data)
{
	SkinyVykresleni(data);
	OznaceniVykresleni();
	VykresleniUroven(data);
	TextVzhledPlosinyVykresleni(data);
}
void MenuVzhledPlosiny::SkinyVykresleni(Profily data)
{
	int n = 7;
	int m = 10;
	for (int i = 0; i < 6; i++)
	{
		if (i == 3)
		{
			n = 7;
			m = 14;
		}
		set.SetCursorPosition(n, m);
		if (data.level >= potrebna_uroven.at(i))
			wcout << skiny.at(i + 1);
		else
			wcout << skiny.at(0);

		n += 10;
	}
}
void MenuVzhledPlosiny::TextVzhledPlosinyVykresleni(Profily& data)
{
	text = transl.NacteniTextVzhledPlosiny(data);

	///-------  Text  -------//

	set.SetCursorPosition(13, 3);
	wcout << text.at(0);
}
void MenuVzhledPlosiny::OznaceniVykresleni()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (j == 0 && i == 0)
			{
				set.SetCursorPosition(oznaceni.at(x), oznaceni.at(y));
				std::wcout << L"\x2554";
			}
			if (j == 0 && i == 7)
			{
				set.SetCursorPosition(oznaceni.at(x) + 7, oznaceni.at(y));
				std::wcout << L"\x2557";
			}
			if (j == 2 && i == 0)
			{
				set.SetCursorPosition(oznaceni.at(x), oznaceni.at(y) + 2);
				std::wcout << L"\x255a";
			}
			if (j == 2 && i == 7)
			{
				set.SetCursorPosition(oznaceni.at(x) + 7, oznaceni.at(y) + 2);
				std::wcout << L"\x255d";
			}
		}
	}
}
void MenuVzhledPlosiny::OznaceniSmazani()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == 0 && j == 0)
			{
				set.SetCursorPosition(oznaceni.at(x), oznaceni.at(y));
				std::wcout << ' ';
			}
			if (i == 7 && j == 0)
			{
				set.SetCursorPosition(oznaceni.at(x) + 7, oznaceni.at(y));
				std::wcout << ' ';
			}
			if (i == 0 && j == 2)
			{
				set.SetCursorPosition(oznaceni.at(x), oznaceni.at(y) + 2);
				std::wcout << ' ';
			}
			if (i == 7 && j == 2)
			{
				set.SetCursorPosition(oznaceni.at(x) + 7, oznaceni.at(y) + 2);
				std::wcout << ' ';
			}
		}
	}
}
void MenuVzhledPlosiny::NacteniSkiny()
{
	wstring s0 = L"??????";
	wstring s1 = L"IIIIII";
	wstring s2 = L"======";
	wstring s3 = L"FELZCU";
	wstring s4 = L"8====D";
	wstring s5;
	for (int i = 0; i < 3; i++)
		s5.push_back(wchar_t(171));
	for (int i = 0; i < 3; i++)
		s5.push_back(wchar_t(187));
	wstring s6 = L"______";

	skiny = { s0, s1, s2, s3, s4, s5 };
}
void MenuVzhledPlosiny::NedostatecnaUrovenVykresleni()
{
	set.SetCursorPosition(9, 7);
	wcout << text.at(1);
}