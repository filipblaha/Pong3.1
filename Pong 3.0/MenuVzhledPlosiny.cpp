#include "MenuVzhledPlosiny.h"

//-----------------------  Input  -----------------------//

int MenuVzhledPlosiny::VstupMenu(Profily& data)
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
		OznaceniVykresleni();
		return 1;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y) += 4;
		}
		OznaceniVykresleni();
		return 1;
	}
	case 'a':
	{
		OznaceniSmazani();
		if (oznaceni.at(x) > zavory.at(2))
		{
			oznaceni.at(x) -= 10;
		}
		OznaceniVykresleni();
		return 1;
	}
	case 'd':
	{
		OznaceniSmazani();
		if (oznaceni.at(x) < zavory.at(3))
		{
			oznaceni.at(x) += 10;
		}
		OznaceniVykresleni();
		return 1;
	}
	case 224:
	{
		switch (_getch())
		{
		case 72:
		{
			OznaceniSmazani();
			if (oznaceni.at(y) > zavory.at(0))
			{
				oznaceni.at(y) -= 4;
			}
			OznaceniVykresleni();
			return 1;
		}
		case 80:
		{
			OznaceniSmazani();
			if (oznaceni.at(y) < zavory.at(1))
			{
				oznaceni.at(y) += 4;
			}
			OznaceniVykresleni();
			return 1;
		}
		case 75:
		{
			OznaceniSmazani();
			if (oznaceni.at(x) > zavory.at(2))
			{
				oznaceni.at(x) -= 10;
			}
			OznaceniVykresleni();
			return 1;
		}
		case 77:
		{
			OznaceniSmazani();
			if (oznaceni.at(x) < zavory.at(3))
			{
				oznaceni.at(x) += 10;
			}
			OznaceniVykresleni();
			return 1;
		}
		}
	}
	case '\r': case ' ':
	{
		return enter;
	}
	case 'q':
	{
		return exit;
	}
	}
}
int MenuVzhledPlosiny::Rozhodovac(Profily& data)
{
	if (oznaceni.at(y) == 9)
	{
		if (oznaceni.at(x) == 6)
		{
			if (data.level < potrebna_uroven.at(0))
			{
				NedostatecnaUrovenVykresleni(potrebna_uroven.at(0));
				return 1;
			}
			else
			{
				data.plosina_skin = 1;
				return 0;
			}
		}
		if (oznaceni.at(x) == 16) 
		{
			if (data.level < potrebna_uroven.at(1))
			{
				NedostatecnaUrovenVykresleni(potrebna_uroven.at(1));
				return 1;
			}
			else
			{
				data.plosina_skin = 2;
				return 0;
			}
		}
		if (oznaceni.at(x) == 26)
		{
			if (data.level < potrebna_uroven.at(2))
			{
				NedostatecnaUrovenVykresleni(potrebna_uroven.at(2));
				return 1;
			}
			else
			{
				data.plosina_skin = 3;
				return 0;
			}
		}
	}
	else if (oznaceni.at(y) == 13)
	{

		if (oznaceni.at(x) == 6)
		{
			if(data.level < potrebna_uroven.at(3))
			{
				NedostatecnaUrovenVykresleni(potrebna_uroven.at(3));
				return 1;
			}
			else
			{
				data.plosina_skin = 4;
				return 0;
			}
		}
		if (oznaceni.at(x) == 16)
		{
			if (data.level < potrebna_uroven.at(4))
			{
				NedostatecnaUrovenVykresleni(potrebna_uroven.at(4));
				return 1;
			}
			else
			{
				data.plosina_skin = 5;
				return 0;
			}
		}
		if (oznaceni.at(x) == 26)
		{
			if (data.level < potrebna_uroven.at(5))
			{
				NedostatecnaUrovenVykresleni(potrebna_uroven.at(5));
				return 1;
			}
			else
			{
				data.plosina_skin = 6;
				return 0;
			}
		}
	}
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
void MenuVzhledPlosiny::NedostatecnaUrovenVykresleni(int uroven)
{
	set.SetCursorPosition(9, 7);
	wcout << text.at(1) << uroven;
}

//-----------------------  Vykresleni -----------------------//

void MenuVzhledProfily(Profily& data)
{

}