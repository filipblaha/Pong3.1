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

	switch (prikaz)
	{
	case enter:
	{
		if (index == 0)
		{
			NazevProfiluVykresleni();
			profil.vytvoreni_noveho_profilu(NazevProfiluSet());
			profil.vybraniprofilu(1);
		}
		else
		{
			profil.vybraniprofilu(index);
		}
		break;
	}
	case del:
	{
		if (index != 0)
		{
			profil.odstraneni_profilu(index);
			RamecekSmazani();
			AktualNazevProfilu(index, poradi, 0, 1);
			OznaceniSet();
			ProfilVykresleni(JazykSet());
		}
		break;
	}
	default:
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
			wcout << L"\x250c";
		else if (i == 23)
			wcout << L"\x2510";
		else
			wcout << L"\x2500";
	}
	for (int j = 8; j < 13; j++)
	{
		set.SetCursorPosition(8, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				wcout << L"\x2502";
		}
	}
	for (int j = 8; j < 13; j++)
	{
		set.SetCursorPosition(31, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				wcout << L"\x2502";
		}
	}
	set.SetCursorPosition(8, 13);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			wcout << L"\x2514";
		else if (i == 23)
			wcout << L"\x2518";
		else
			wcout << L"\x2500";
	}
	///////    DEL   ///////
	set.SetCursorPosition(32, 16);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			wcout << L"\x250c";
		else if (i == 6)
			wcout << L"\x2510";
		else
			wcout << L"\x2500";
	}
	set.SetCursorPosition(32, 17);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || i == 6)
			wcout << L"\x2502";
		else if (i == 3)
			wcout << char(17);
		else if (i == 4 || i == 5)
			wcout << L"\x2500";
		else
			wcout << ' ';
	}
	set.SetCursorPosition(32, 18);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			wcout << L"\x2514";
		else if (i == 6)
			wcout << L"\x2518";
		else
			wcout << L"\x2500";
	}
	///////    Zmena jazyka   ///////
	set.SetCursorPosition(1, 16);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			wcout << L"\x250c";
		else if (i == 4)
			wcout << L"\x2510";
		else
			wcout << L"\x2500";
	}
	set.SetCursorPosition(1, 17);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
			wcout << L"\x2502";
		else if (i == 2)
			wcout << L'L';
		else
			wcout << ' ';
	}
	set.SetCursorPosition(1, 18);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			wcout << L"\x2514";
		else if (i == 4)
			wcout << L"\x2518";
		else
			wcout << L"\x2500";
	}
	TextProfilVykresleni(jazyk);
}
void MenuProfil::TextProfilVykresleni(int jazyk)
{
	transl.jazyk = jazyk;
	text = transl.NacteniTextProfil();

	list<wstring> wl = transl.StringToWStringList(aktual);
	list<int> p = profil.nacteni_urovni_profilu();
	vector<int> v = profil.nacteni_dat_profilu(0);

	list<wstring>::iterator itr;
	list<int>::iterator itri;
	itr = wl.begin();
	itri = p.begin();

	RamecekSmazani();
	OznaceniVykresleni();

	///-------  Text  -------//

	set.SetCursorPosition(10, 5);
	wcout << text.at(0);

	set.SetCursorPosition(12, 8);
	if (*aktual.begin() == "Novy_profil")
		wcout << text.at(1);
	else
		wcout << *itr << "  (" << text.at(7) << *itri << ")";
	itr++;
	itri++;
	if (itr != wl.end())
	{
		set.SetCursorPosition(12, 10);
		wcout << *itr << "  (" << text.at(7) << *itri << ")";
		itr++;
		itri++;
		if (itr != wl.end())
		{
			set.SetCursorPosition(12, 12);
			wcout << *itr << "  (" << text.at(7) << *itri << ")";
		}
	}

	set.SetCursorPosition(7, 17);
	wcout << text.at(2);
	if (!transl.jazyk)
		set.SetCursorPosition(18, 17);
	if (transl.jazyk)
		set.SetCursorPosition(17, 17);
	wcout << text.at(3);

}
void MenuProfil::OtazkaVykresleni()
{
	set.SetCursorPosition(5, 2);
	wcout << text.at(4);
	set.SetCursorPosition(26, 3);
	wcout << text.at(5);
}

// private
void MenuProfil::NazevProfiluVykresleni()
{
	RamecekSmazani();
	set.SetCursorPosition(10, 8);
	wcout << text.at(6);
}
void MenuProfil::RamecekSmazani()
{
	for (int j = 8; j < 13; j++)
	{
		set.SetCursorPosition(9, j);
		for (int i = 0; i < 22; i++)
		{
			wcout << ' ';
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
string MenuProfil::NazevProfiluSet()
{
	string nazev;
	set.SetCursorPosition(10, 10);
	cin >> nazev;
	while (nazev.size() >= 12)
	{
		set.SetCursorPosition(10, 10);
		RamecekSmazani();
		cin >> nazev;
	}
	RamecekSmazani();
	return nazev;
}

