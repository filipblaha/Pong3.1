#include "Menu_profil.h"


//-----------------------  Input  -----------------------//

int Menu_profil::VstupMenu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		OznaceniSmazani();
		if ((oznaceni.at(y) > zavory.at(0)))
		{
			if (oznaceni.at(y) <= 12)
			{
				oznaceni.at(y) -= 2;
			}
			return posun;
		}
		else
		{
			if (*profil.nacteni_jmen_profilu().begin() != *aktual.begin())
			{
				Rozhodovac(0, 1);
				TextProfilVykresleni(JazykSet());
			}
			return posun;
		}
	}
	case 's':
	{
		OznaceniSmazani();
		if ((oznaceni.at(y) < zavory.at(1)) && (strana == profil_e))
		{
			if (oznaceni.at(y) < 12)
			{
				oznaceni.at(y) += 2;
			}
			return posun;
		}
		else
		{
			if (*profil.nacteni_jmen_profilu().rbegin() != *aktual.rbegin())
			{
				Rozhodovac(0, -1);
				TextProfilVykresleni(JazykSet());
			}
			return posun;
		}
	}
	case '\r':
	{
		return enter;
	}
	case 'q':
	{
		if (strana == profil_e)
		{
			return exit;
		}
	}
	case char(8) :
	{
		if (strana == profil_e)
		{
			return del;
		}
	}
	case 'l':
	{
		ProfilVykresleni(JazykSet(1));
	}
	}
}
void Menu_profil::Rozhodovac(int prikaz, int inkrement)
{
	int index = 0;
	int poradi = 0;
	if (oznaceni.at(y) == 8)
	{
		index = IndexProfilu();
		poradi = 0;
	}
	if (oznaceni.at(y) == 10)
	{
		index = IndexProfilu(1);
		poradi = 1;
	}
	if (oznaceni.at(y) == 12)
	{
		index = IndexProfilu(2);
		poradi = 2;
	}

	if (prikaz == enter)
	{
		if (index == 0)
		{
			NazevProfiluVykresleni();
			profil.vytvoreni_noveho_profilu(NazevProfiluSet());
			ProfilVykresleni(profil.jazyk);
		}
		else
		{
			ulozena_data = profil.nacteni_dat_profilu(index);
		}
	}
	if (prikaz == del)
	{
		if (index != 0)
		{
			profil.odstraneni_profilu(index);
			RamecekSmazani();
			AktualNazevProfilu(index, poradi, 0, 1);
			OznaceniSet();
			ProfilVykresleni(profil.jazyk);
		}
	}
	else
	{
		AktualNazevProfilu(index, poradi, inkrement);
	}
}

//-----------------------  Vykresleni -----------------------//

// public
void Menu_profil::ProfilVykresleni(int jazyk)
{
	MenuSTARTVykresleni();
	///////    Ramecek   ///////
	set.setCursorPosition(8, 7);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 23)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	for (int j = 8; j < 13; j++)
	{
		set.setCursorPosition(8, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2502";
		}
	}
	for (int j = 8; j < 13; j++)
	{
		set.setCursorPosition(31, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2502";
		}
	}
	set.setCursorPosition(8, 13);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			std::wcout << L"\x2514";
		else if (i == 23)
			std::wcout << L"\x2518";
		else
			std::wcout << L"\x2500";
	}
	///////    DEL   ///////
	set.setCursorPosition(32, 16);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 6)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	set.setCursorPosition(32, 17);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || i == 6)
			std::wcout << L"\x2502";
		else if (i == 3)
			std::wcout << char(17);
		else if (i == 4 || i == 5)
			std::wcout << L"\x2500";
		else
			std::wcout << ' ';
	}
	set.setCursorPosition(32, 18);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::wcout << L"\x2514";
		else if (i == 6)
			std::wcout << L"\x2518";
		else
			std::wcout << L"\x2500";
	}
	///////    Zmena jazyka   ///////
	set.setCursorPosition(1, 16);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 4)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	set.setCursorPosition(1, 17);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
			std::wcout << L"\x2502";
		else if (i == 2)
			std::wcout << L'L';
		else
			std::wcout << ' ';
	}
	set.setCursorPosition(1, 18);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			std::wcout << L"\x2514";
		else if (i == 4)
			std::wcout << L"\x2518";
		else
			std::wcout << L"\x2500";
	}
	TextProfilVykresleni(jazyk);
	OznaceniVykresleni();
}
void Menu_profil::TextProfilVykresleni(int jazyk)
{
	transl.jazyk = jazyk;
	t = transl.nacteni_textu_profil();
	OznaceniVykresleni();

	///////    Text   ///////

	RamecekSmazani();
	std::list<std::wstring> wl = transl.StringToWStringList(aktual);
	std::list<std::wstring>::iterator itr;
	std::list<int>::iterator itri;

	std::list<int> p = profil.nacteni_urovni_profilu();
	std::vector<int> v = profil.nacteni_dat_profilu(0);

	set.setCursorPosition(10, 5);
	std::wcout << t.at(0);

	itr = wl.begin();
	itri = p.begin();
	set.setCursorPosition(12, 8);
	if (*aktual.begin() == "Novy_profil")
		std::wcout << t.at(1);
	else
		std::wcout << *itr << "  (" << t.at(7) << *itri << ")";
	itr++;
	itri++;
	if (itr != wl.end())
	{
		set.setCursorPosition(12, 10);
		std::wcout << *itr << "  (" << t.at(7) << *itri << ")";
		itr++;
		itri++;
		if (itr != wl.end())
		{
			set.setCursorPosition(12, 12);
			std::wcout << *itr << "  (" << t.at(7) << *itri << ")";
		}
	}

	set.setCursorPosition(7, 17);
	std::wcout << t.at(2);
	if (!transl.jazyk)
		set.setCursorPosition(18, 17);
	if (transl.jazyk)
		set.setCursorPosition(17, 17);
	std::wcout << t.at(3);

}
void Menu_profil::OtazkaVykresleni()
{
	set.setCursorPosition(5, 2);
	std::wcout << t.at(4);
	set.setCursorPosition(26, 3);
	std::wcout << t.at(5);
}
// private
void Menu_profil::NazevProfiluVykresleni()
{
	RamecekSmazani();
	set.setCursorPosition(10, 8);
	std::wcout << t.at(6);
}
void Menu_profil::RamecekSmazani()
{
	for (int j = 8; j < 13; j++)
	{
		set.setCursorPosition(9, j);
		for (int i = 0; i < 22; i++)
		{
			std::wcout << ' ';
		}
	}
}

//-----------------------  Set -----------------------//

void Menu_profil::SpodniZavoraSet()
{
	profil.nacteni_poctu_profilu();
	if (profil.pocet_profilu_s == 1)
		zavory.at(1) = 8;
	else if (profil.pocet_profilu_s == 2)
		zavory.at(1) = 10;
	else if (profil.pocet_profilu_s >= 3)
		zavory.at(1) = 12;
}
void Menu_profil::OznaceniSet()
{
	SpodniZavoraSet();
	if (profil.pocet_profilu_s < 3)
		oznaceni.at(y) = zavory.at(1);
}
std::string Menu_profil::NazevProfiluSet()
{
	std::string nazev;
	set.setCursorPosition(10, 10);
	std::cin >> nazev;
	while (nazev.size() >= 12)
	{
		set.setCursorPosition(10, 10);
		RamecekSmazani();
		std::cin >> nazev;
	}
	RamecekSmazani();
	return nazev;
}

