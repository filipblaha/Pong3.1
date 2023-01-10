#include "MenuSkiny.h"

//-----------------------  Input  -----------------------//

int MenuSkiny::VstupMenu(Profily& data)
{
	switch (_getch())
	{
	case 'w': case 's':
	{
		if (nahore)
			nahore = 0;
		else
			nahore = 1;
		return 1;
	}
	case 'a':
	{
		if (nahore)
		{
			if (data.plosina_skin == 0)
				ref_plosina_skin = data.NacteniSkinyPlosina().size();
			else
				ref_plosina_skin--;
			NacteniAktualSkinyPlosina(data);
		}
		else
		{
			if (ref_mic_skin == 0)
				ref_mic_skin = data.NacteniSkinyMic().size();
			else
				ref_mic_skin--;
			NacteniAktualSkinyMic(data);
		}
		return 1;
	}
	case 'd':
	{
		if (nahore)
		{
			if (ref_plosina_skin == data.NacteniSkinyPlosina().size())
				ref_plosina_skin = 0;
			else
				ref_plosina_skin++;
			if (ref_mic_skin == 0)
				ref_mic_skin++;
			NacteniAktualSkinyPlosina(data);
		}
		else
		{
			if (ref_mic_skin == data.NacteniSkinyMic().size())
				ref_mic_skin = 0;
			else
				ref_mic_skin++;
			if (ref_mic_skin == 0)
				ref_mic_skin++;
			NacteniAktualSkinyMic(data);
		}
		return 1;
	}
	case 224:
	{
		switch (_getch())
		{
		case 72: case 80:
		{
			if (nahore)
				nahore = 0;
			else
				nahore = 1;
			return 1;
		}
		case 75:
		{
			if (nahore)
			{
				if (ref_plosina_skin == 0)
					ref_plosina_skin = data.NacteniSkinyPlosina().size();
				else
					ref_plosina_skin--;
				NacteniAktualSkinyPlosina(data);
			}
			else
			{
				if (ref_mic_skin == 0)
					ref_mic_skin = data.NacteniSkinyMic().size();
				else
					ref_mic_skin--;
				NacteniAktualSkinyMic(data);
			}
			return 1;
		}
		case 77:
		{
			if (nahore)
			{
				if (ref_plosina_skin == data.NacteniSkinyPlosina().size())
					ref_plosina_skin = 0;
				else
					ref_plosina_skin++;
				if (ref_mic_skin == 0)
					ref_mic_skin++;
				NacteniAktualSkinyPlosina(data);
			}
			else
			{
				if (ref_mic_skin == data.NacteniSkinyMic().size())
					ref_mic_skin = 0;
				else
					ref_mic_skin++;
				if (ref_mic_skin == 0)
					ref_mic_skin++;
				NacteniAktualSkinyMic(data);
			}
			return 1;
		}
		}
	}
	case 'q':
	{
		return exit;
	}
	}
}
void MenuSkiny::Rozhodovac(Profily& data)
{
	if (nahore)
	{
		if (data.level < potrebna_uroven.at(ref_plosina_skin))
		{
			NedostatecnaUrovenVykresleni(potrebna_uroven.at(ref_plosina_skin), 0);
			NedostatecnaUrovenSmazani(0);
		}
		else
		{
			data.plosina_skin = ref_plosina_skin;
		}

	}
	else
	{
		if (data.level < potrebna_uroven.at(data.plosina_skin))
		{
			NedostatecnaUrovenVykresleni(potrebna_uroven.at(ref_plosina_skin), 1);
		}
		else
		{
			NedostatecnaUrovenSmazani(1);
			data.mic_skin = ref_mic_skin;
		}
	}
}

//-----------------------  Vykresleni -----------------------//

void MenuSkiny::SkinyVykresleni(Profily data)
{
	PlosinaVykresleni(data);
	MicVykresleni(data);
	OznaceniVykresleni();
	VykresleniUroven(data);
	TextSkinyVykresleni(data);
}
void MenuSkiny::PlosinaVykresleni(Profily data)
{
	set.SetCursorPosition(7, 8);
	wcout << aktual_skiny_plosina.at(0);
	set.SetCursorPosition(17, 8);
	wcout << aktual_skiny_plosina.at(1);
	set.SetCursorPosition(27, 8);
	wcout << aktual_skiny_plosina.at(2);
}
void MenuSkiny::MicVykresleni(Profily data)
{
	set.SetCursorPosition(7, 14);
	wcout << aktual_skiny_mic.at(0);
	set.SetCursorPosition(13, 14);
	wcout << aktual_skiny_mic.at(1);
	set.SetCursorPosition(19, 14);
	wcout << aktual_skiny_mic.at(2);
	set.SetCursorPosition(25, 14);
	wcout << aktual_skiny_mic.at(3);
	set.SetCursorPosition(31, 14);
	wcout << aktual_skiny_mic.at(4);
}
void MenuSkiny::TextSkinyVykresleni(Profily data)
{
	text = transl.NacteniTextSkiny(data);

	///-------  Text  -------//

	set.SetCursorPosition(13, 3);
	wcout << text.at(0);

	set.SetCursorPosition(5, 5);
	wcout << text.at(1);
	set.SetCursorPosition(5, 11);
	wcout << text.at(2);

}
void MenuSkiny::OznaceniVykresleni()
{
	set.SetCursorPosition(3, 8);
	wcout << L"\x25c4";
	set.SetCursorPosition(36, 8);
	wcout << L"\x25ba";

	set.SetCursorPosition(3, 14);
	wcout << L"\x25c4";
	set.SetCursorPosition(36, 14);
	wcout << L"\x25ba";

	set.SetCursorPosition(17, 13);
	std::wcout << ' ';
	set.SetCursorPosition(17, 15);
	std::wcout << ' ';
	set.SetCursorPosition(21, 13);
	std::wcout << ' ';
	set.SetCursorPosition(21, 15);
	std::wcout << ' ';


	set.SetCursorPosition(15, 7);
	std::wcout << L"\x2554";
	set.SetCursorPosition(15, 9);
	std::wcout << L"\x255a";
	set.SetCursorPosition(24, 7);
	std::wcout << L"\x2557";
	set.SetCursorPosition(24, 9);
	std::wcout << L"\x255d";
}
void MenuSkiny::NedostatecnaUrovenVykresleni(int uroven, int objekt)
{
	if (objekt == 0)
		set.SetCursorPosition(15, 7);
	else
		set.SetCursorPosition(15, 13);

	wcout << text.at(3) << uroven;
}
void MenuSkiny::NedostatecnaUrovenSmazani(int objekt)
{
	if (objekt == 0)
		set.SetCursorPosition(15, 7);
	else
		set.SetCursorPosition(15, 13);

	for (int i = 0; i < 15; i++)
	{
		wcout << " ";
	}
}

//-----------------------  Scroll  -----------------------//

void MenuSkiny::NacteniAktualSkinyPlosina(Profily data)
{
	vector<wstring> skiny = data.NacteniSkinyPlosina();
	vector<wstring>::iterator itr = skiny.begin();
	aktual_skiny_plosina.clear();

	advance(itr, ref_plosina_skin - 1);
	if (itr == skiny.begin())
		itr = skiny.end();
	itr--;

	for (int i = 0; i < 3; i++)
	{
		if (itr == skiny.end())
		{
			itr = skiny.begin();
		}
		if (*itr == skiny.at(0))
			itr++;

		aktual_skiny_plosina.push_back(*itr);
		itr++;
	}
}
void MenuSkiny::NacteniAktualSkinyMic(Profily data)
{
	vector<wchar_t> skiny = data.NacteniSkinyMic();
	vector<wchar_t>::iterator itr = skiny.begin();
	aktual_skiny_mic.clear();

	advance(itr, ref_mic_skin - 1);
	for (int i = 0; i < 2; i++)
	{
		if (itr == skiny.begin())
			itr = skiny.end();
		itr--;
	}

	for (int i = 0; i < 5; i++)
	{
		if (itr == skiny.end())
		{
			itr = skiny.begin();
		}
		if (*itr == skiny.at(0))
			itr++;

		aktual_skiny_mic.push_back(*itr);
		itr++;
	}
}