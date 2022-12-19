#include "MenuOvladani.h"

//-----------------------  Input  -----------------------//

int MenuOvladani::VstupMenu()
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
		else
		{
			oznaceni.at(y) = zavory.at(1);
		}
		return 1;
	}
	case 's':
	{
		OznaceniSmazani();
		if (oznaceni.at(y) < zavory.at(1))
		{
			oznaceni.at(y)++;
		}
		else
		{
			oznaceni.at(y) = zavory.at(0);
		}
		return 1;
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
void MenuOvladani::Rozhodovac(Profily& data)
{
	if (oznaceni.at(y) == 12)
	{
		ZmenaOvladaniSmazani(12);
		data.pohyb_vlevo = ZmenaOvladani();
	}
	else if (oznaceni.at(y) == 13)
	{
		ZmenaOvladaniSmazani(13);
		data.pohyb_vpravo = ZmenaOvladani();
	}
	else if (oznaceni.at(y) == 14)
	{
		ZmenaOvladaniSmazani(14);
		data.pouziti_schopnosti = ZmenaOvladani();
	}
	else if (oznaceni.at(y) == 15)
	{
		ZmenaOvladaniSmazani(15);
		data.pauza = ZmenaOvladani();
	}

	data.UlozeniProfilu(data.jsem_v_profilu);
	set.Prechod();
	MenuSTARTVykresleni();
	OvladaniVykresleni(data);
}

void MenuOvladani::ZmenaOvladaniSmazani(int poradi)
{
	set.SetCursorPosition(29, poradi);
	wcout << "        ";
	set.SetCursorPosition(29, poradi);
}
char MenuOvladani::ZmenaOvladani()
{
	char zmena;
	zmena = _getche();

	return zmena;
}

//-----------------------  Vykresleni -----------------------//

void MenuOvladani::OvladaniVykresleni(Profily& data)
{
	set.SetCursorPosition(9, 7);
	wcout << "W";
	set.SetCursorPosition(7, 8);
	wcout << "A S D";
	set.SetCursorPosition(17, 8);
	set.SetCursorPosition(26, 8);
	wcout << "Q";

	for (int  j= 12; j <= 15; j++)
	{
		set.SetCursorPosition(12, j);
		for (int i = 0; i < 15;i++)
			wcout << ".";
	}

	OznaceniVykresleni();
	VykresleniUroven(data);
	TextOvladaniVykresleni(data);
}
void MenuOvladani::TextOvladaniVykresleni(Profily& data)
{
	text = transl.NacteniTextOvladani(data);
	vector<wstring> ovladani = BlbyZnakyCheck(data);

	///-------  Text  -------//

	set.SetCursorPosition(15, 3);
	wcout << text.at(0);
	set.SetCursorPosition(6, 5);
	wcout << text.at(1);
	set.SetCursorPosition(17, 8);
	wcout << text.at(2);
	set.SetCursorPosition(6, 10);
	wcout << text.at(3);
	set.SetCursorPosition(7, 12);
	wcout << text.at(4);
	set.SetCursorPosition(29, 12);
	wcout << ovladani.at(0);
	set.SetCursorPosition(7, 13);
	wcout << text.at(5);
	set.SetCursorPosition(29, 13);
	wcout << ovladani.at(1);
	set.SetCursorPosition(7, 14);
	wcout << text.at(6);
	set.SetCursorPosition(29, 14);
	wcout << ovladani.at(2);
	set.SetCursorPosition(7, 15);
	wcout << text.at(7);
	set.SetCursorPosition(29, 15);
	wcout << ovladani.at(3);
}

//-----------------------  Znak Check -----------------------//

vector<wstring> MenuOvladani::BlbyZnakyCheck(Profily& data)
{
	vector<char> ovladani_char = data.NacteniOvladaniProfilu(data.jsem_v_profilu);
	vector<wstring> ovladani_string;
	vector<wstring> text = transl.NacteniTextOvladani(data);

	for (int i = 0; i < ovladani_char.size(); i++)
	{
		wstring tempws;
		if (ovladani_char.at(i) == 32)
			ovladani_string.push_back(text.at(8));
		else if (ovladani_char.at(i) == 8)
			ovladani_string.push_back(text.at(9));
		else if (ovladani_char.at(i) == 127)
			ovladani_string.push_back(text.at(10));
		else if (ovladani_char.at(i) == 27)
			ovladani_string.push_back(text.at(11));
		else if (ovladani_char.at(i) == 13)
			ovladani_string.push_back(text.at(12));
		else if (ovladani_char.at(i) == 9)
			ovladani_string.push_back(text.at(13));
		else
		{
			tempws.push_back(ovladani_char.at(i));
			ovladani_string.push_back(tempws);
		}
	}
	return ovladani_string;
}