#include "MenuProfil.h"

//-----------------------  Input  -----------------------//

int MenuProfil::VstupMenu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) > zavory.at(0))
		{
			oznaceni.at(y) -= 2;
		}
		else
		{
			if (*profil.nacteni_jmen_profilu().begin() != *aktual.begin())
			{
				Rozhodovac(0, 1);
				TextProfilVykresleni(JazykSet());
			}
		}
		return posun;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y) += 2;
		}
		else
		{
			if (*profil.nacteni_jmen_profilu().rbegin() != *aktual.rbegin())
			{
				Rozhodovac(0, -1);
				TextProfilVykresleni(JazykSet());
			}
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
	case char(8) :
	{
		if (IndexProfilu() != 0 || oznaceni.at(y) != 8)
			return del;
		break;
	}
	case 'l':
	{
		ProfilVykresleni(JazykSet(1));
	}
	}
}
void MenuProfil::Rozhodovac(int prikaz, int inkrement)
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
			ProfilVykresleni(JazykSet());
		}
	}
	else
	{
		AktualNazevProfilu(index, poradi, inkrement);
	}
}

//-----------------------  Vykresleni -----------------------//

// public
void MenuProfil::ProfilVykresleni(int jazyk)
{
	///////    Ramecek   ///////
	set.SetCursorPosition(8, 7);
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
		set.SetCursorPosition(8, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2502";
		}
	}
	for (int j = 8; j < 13; j++)
	{
		set.SetCursorPosition(31, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2502";
		}
	}
	set.SetCursorPosition(8, 13);
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
	set.SetCursorPosition(32, 16);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 6)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	set.SetCursorPosition(32, 17);
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
	set.SetCursorPosition(32, 18);
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
	set.SetCursorPosition(1, 16);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 4)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	set.SetCursorPosition(1, 17);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
			std::wcout << L"\x2502";
		else if (i == 2)
			std::wcout << L'L';
		else
			std::wcout << ' ';
	}
	set.SetCursorPosition(1, 18);
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
}
void MenuProfil::TextProfilVykresleni(int jazyk)
{
	transl.jazyk = jazyk;
	text = transl.NacteniTextProfil();

	std::list<std::wstring> wl = transl.StringToWStringList(aktual);
	std::list<int> p = profil.nacteni_urovni_profilu();
	std::vector<int> v = profil.nacteni_dat_profilu(0);

	std::list<std::wstring>::iterator itr;
	std::list<int>::iterator itri;
	itr = wl.begin();
	itri = p.begin();

	RamecekSmazani();
	OznaceniVykresleni();

	///-------  Text  -------//

	set.SetCursorPosition(10, 5);
	std::wcout << text.at(0);

	set.SetCursorPosition(12, 8);
	if (*aktual.begin() == "Novy_profil")
		std::wcout << text.at(1);
	else
		std::wcout << *itr << "  (" << text.at(7) << *itri << ")";
	itr++;
	itri++;
	if (itr != wl.end())
	{
		set.SetCursorPosition(12, 10);
		std::wcout << *itr << "  (" << text.at(7) << *itri << ")";
		itr++;
		itri++;
		if (itr != wl.end())
		{
			set.SetCursorPosition(12, 12);
			std::wcout << *itr << "  (" << text.at(7) << *itri << ")";
		}
	}

	set.SetCursorPosition(7, 17);
	std::wcout << text.at(2);
	if (!transl.jazyk)
		set.SetCursorPosition(18, 17);
	if (transl.jazyk)
		set.SetCursorPosition(17, 17);
	std::wcout << text.at(3);

}
void MenuProfil::OtazkaVykresleni()
{
	set.SetCursorPosition(5, 2);
	std::wcout << text.at(4);
	set.SetCursorPosition(26, 3);
	std::wcout << text.at(5);
}

// private
void MenuProfil::NazevProfiluVykresleni()
{
	RamecekSmazani();
	set.SetCursorPosition(10, 8);
	std::wcout << text.at(6);
}
void MenuProfil::RamecekSmazani()
{
	for (int j = 8; j < 13; j++)
	{
		set.SetCursorPosition(9, j);
		for (int i = 0; i < 22; i++)
		{
			std::wcout << ' ';
		}
	}
}

//-----------------------  Set -----------------------//

void MenuProfil::SpodniZavoraSet()
{
	profil.nacteni_poctu_profilu();
	if (profil.pocet_profilu_s == 1)
		zavory.at(1) = 8;
	else if (profil.pocet_profilu_s == 2)
		zavory.at(1) = 10;
	else if (profil.pocet_profilu_s >= 3)
		zavory.at(1) = 12;
}
void MenuProfil::OznaceniSet()
{
	SpodniZavoraSet();
	if (profil.pocet_profilu_s < 3)
		oznaceni.at(y) = zavory.at(1);
}
std::string MenuProfil::NazevProfiluSet()
{
	std::string nazev;
	set.SetCursorPosition(10, 10);
	std::cin >> nazev;
	while (nazev.size() >= 12)
	{
		set.SetCursorPosition(10, 10);
		RamecekSmazani();
		std::cin >> nazev;
	}
	RamecekSmazani();
	return nazev;
}

