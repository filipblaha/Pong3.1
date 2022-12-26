#include "Menuprofil.h"

//-----------------------  Input  -----------------------//

int MenuProfil::VstupMenu(Profily& data)
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
		else if (data.pocet_profilu == 2)
		{
			oznaceni.at(y) += 2;
		}
		else if(*data.NacteniJmenProfilu().begin() != *aktual_nazvy.begin())
		{
			Rozhodovac(data, 0, 1);
			TextProfilVykresleni(data);
		}
		else
		{
			AktualNazevProfilu(data, data.pocet_profilu, 3);
			oznaceni.at(y) = zavory.at(1);
			TextProfilVykresleni(data);
		}
		OznaceniVykresleni();
		break;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y) += 2;
		}
		else if (data.pocet_profilu == 2)
		{
			oznaceni.at(y) -= 2;
		}
		else if (*data.NacteniJmenProfilu().rbegin() != *aktual_nazvy.rbegin())
		{
			Rozhodovac(data, 0, -1);
			TextProfilVykresleni(data);
		}
		else
		{
			AktualNazevProfilu(data, 0, 0);
			oznaceni.at(y) = zavory.at(0);
			TextProfilVykresleni(data);
		}
		OznaceniVykresleni();
		break;
	}
	case 224:
	{
		switch (_getch())
		{
		case 72:
			OznaceniSmazani();
			if (oznaceni.at(y) > zavory.at(0))
			{
				oznaceni.at(y) -= 2;
			}
			else if (data.pocet_profilu == 2)
			{
				oznaceni.at(y) += 2;
			}
			else if (*data.NacteniJmenProfilu().begin() != *aktual_nazvy.begin())
			{
				Rozhodovac(data, 0, 1);
				TextProfilVykresleni(data);
			}
			else
			{
				AktualNazevProfilu(data, data.pocet_profilu, 3);
				oznaceni.at(y) = zavory.at(1);
				TextProfilVykresleni(data);
			}
			OznaceniVykresleni();
			break;
		case 80:
			OznaceniSmazani();
			if (oznaceni.at(y) < zavory.at(1))
			{
				oznaceni.at(y) += 2;
			}
			else if (data.pocet_profilu == 2)
			{
				oznaceni.at(y) -= 2;
			}
			else if (*data.NacteniJmenProfilu().rbegin() != *aktual_nazvy.rbegin())
			{
				Rozhodovac(data, 0, -1);
				TextProfilVykresleni(data);
			}
			
			else
			{
				AktualNazevProfilu(data, 0, 0);
				oznaceni.at(y) = zavory.at(0);
				TextProfilVykresleni(data);
			}
			OznaceniVykresleni();
			break;
		}
		break;
	}
	case '\r': case ' ':
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
	case 'r':
	{
		if (IndexProfilu() != 0 || oznaceni.at(y) != 8)
			Rozhodovac(data, zmena_nazvu);
		break;
		
	}
	case 'l':
	{
		JazykSet(data);
		MenuSTARTVykresleni();
		ProfilVykresleni(data);
		break;
	}
	}
}
void MenuProfil::Rozhodovac(Profily &data, int prikaz, int inkrement)
{
	int index = 0;
	int poradi = 0;
	if (oznaceni.at(y) == 7)
	{
		index = IndexProfilu();
		poradi = 0;
	}
	if (oznaceni.at(y) == 9)
	{
		index = IndexProfilu(1);
		poradi = 1;
	}
	if (oznaceni.at(y) == 11)
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
			data.VytvoreniNovehoProfilu(NazevProfiluSet());
			data.VybraniProfilu(1);
		}
		else
		{
			data.VybraniProfilu(index);
		}
		break;
	}
	case del:
	{
		if (index != 0)
		{
			data.OdstraneniProfilu(index);
			RamecekSmazani();
			AktualNazevProfilu(data, index, poradi, 0, 1);
			OznaceniSet(data);
			TextProfilVykresleni(data);
		}
		break;
	}
	case zmena_nazvu:
	{
		if (index != 0)
		{
			data.ZmenaNazvu(NazevProfiluSet(), index);
			RamecekSmazani();
			AktualNazevProfilu(data, index, poradi);
			TextProfilVykresleni(data);
		}
		break;
	}
	default:
		AktualNazevProfilu(data, index, poradi, inkrement);
	}
}

//-----------------------  Vykresleni -----------------------//

// public
void MenuProfil::ProfilVykresleni(Profily& data)
{
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

	///////    Zmena jmena   ///////

	set.SetCursorPosition(1, 13);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			wcout << L"\x250c";
		else if (i == 4)
			wcout << L"\x2510";
		else
			wcout << L"\x2500";
	}
	set.SetCursorPosition(1, 14);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
			wcout << L"\x2502";
		else if (i == 2)
			wcout << 'R';
		else
			wcout << ' ';
	}
	set.SetCursorPosition(1, 15);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			wcout << L"\x2514";
		else if (i == 4)
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
			wcout << 'L';
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
	RamecekVykresleni();
	TextProfilVykresleni(data);
}
void MenuProfil::RamecekVykresleni()
{
	set.SetCursorPosition(8, 6);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			wcout << L"\x250c";
		else if (i == 23)
			wcout << L"\x2510";
		else
			wcout << L"\x2500";
	}
	for (int i = 7; i < 12; i++)
	{
		set.SetCursorPosition(8, i);
		wcout << L"\x2502";
	}
	for (int i = 7; i < 12; i++)
	{
		set.SetCursorPosition(31, i);
		wcout << L"\x2502";
	}
	set.SetCursorPosition(8, 12);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			wcout << L"\x2514";
		else if (i == 23)
			wcout << L"\x2518";
		else
			wcout << L"\x2500";
	}
}
void MenuProfil::TextProfilVykresleni(Profily& data)
{
	text = transl.NacteniTextProfil(data);

	list<wstring> wl = transl.set.StringToWStringList(aktual_nazvy);
	list<int> p = aktual_urovne;

	list<wstring>::iterator itr;
	list<int>::iterator itri;
	itr = wl.begin();
	itri = p.begin();

	RamecekSmazani();
	OznaceniVykresleni();

	///-------  Text  -------//

	set.SetCursorPosition(10, 4);
	wcout << text.at(0);

	set.SetCursorPosition(12, 7);
	if (*aktual_nazvy.begin() == "Novy_profil")
		wcout << text.at(1);
	else
		wcout << *itr << " (" << text.at(8) << *itri << ")";
	itr++;
	itri++;
	if (itr != wl.end())
	{
		set.SetCursorPosition(12, 9);
		wcout << *itr << " (" << text.at(8) << *itri << ")";
		itr++;
		itri++;
		if (itr != wl.end())
		{
			set.SetCursorPosition(12, 11);
			wcout << *itr << " (" << text.at(8) << *itri << ")";
		}
	}
	set.SetCursorPosition(7, 14);
	wcout << text.at(2);
	set.SetCursorPosition(7, 17);
	wcout << text.at(3);
	if (!data.jazyk)
		set.SetCursorPosition(18, 17);
	if (data.jazyk)
		set.SetCursorPosition(17, 17);
	wcout << text.at(4);

}
void MenuProfil::OtazkaVykresleni()
{
	set.SetCursorPosition(5, 2);
	wcout << text.at(5);
	set.SetCursorPosition(26, 3);
	wcout << text.at(6);
}
void MenuProfil::OtazkaSmazani()
{
	set.SetCursorPosition(5, 2);
	wcout << "                               ";
	set.SetCursorPosition(26, 3);
	wcout << "       ";
}

// private
void MenuProfil::ZadejProfilVykresleni()
{
	RamecekSmazani();
	set.SetCursorPosition(10, 7);
	wcout << text.at(7);
}
void MenuProfil::RamecekSmazani()
{
	for (int j = 7; j <= 11; j++)
	{
		set.SetCursorPosition(9, j);
		for (int i = 0; i < 21; i++)
		{
			wcout << ' ';
		}
	}
}

//-----------------------  Set -----------------------//

void MenuProfil::SpodniZavoraSet(Profily data)
{
	data.NacteniPoctuProfilu();
	if (data.pocet_profilu == 1)
		zavory.at(1) = 7;
	else if (data.pocet_profilu == 2)
		zavory.at(1) = 9;
	else if (data.pocet_profilu >= 3)
		zavory.at(1) = 11;
}
void MenuProfil::OznaceniSet(Profily data)
{
	SpodniZavoraSet(data);
	if (data.pocet_profilu < 3)
		oznaceni.at(y) = zavory.at(1);
}
string MenuProfil::NazevProfiluSet()
{
	ZadejProfilVykresleni();

	string nazev;
	set.SetCursorPosition(10, 9);
	cin >> nazev;
	while (nazev.size() >= 10)
	{
		RamecekSmazani();
		set.SetCursorPosition(10, 9);
		cin >> nazev;
	}
	RamecekSmazani();
	return nazev;
}

