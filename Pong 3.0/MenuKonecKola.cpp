#include "MenuKonecKola.h"

bool MenuKonecKola::VstupKonecKola()
{
	while(1)
	{
		switch (_getch())
		{
		case ' ':
		{
			return 1;
		}
		case 'q':
		{
			return 0;
		}
		default:
			break;
		}
	}
}
void MenuKonecKola::Logika(Profily& data, bool vyhra)
{
	//-------  Pricitani expu  -------//

	if (vyhra)
		n_exp += 7;
	n_exp += data.pocet_rozbitych_bloku;

	//-------  Highscore  -------//
	if (vyhra)
	{
		if (data.highscore_cas == 0)
			data.highscore_cas = data.cas;
		if (data.cas < data.highscore_cas)
		{
			data.highscore_cas = data.cas;
			n_exp = +4;
		}
	}

	//-------  Level bar  -------//

	exp_pole.clear();
	int docas_exp = 0;
	int level_up = 0;
	while (n_exp >= 20)
	{
		n_exp -= 20;
		level_up++;
		docas_exp = n_exp;
	}

	data.exp += n_exp;
	if (data.exp >= 20)
	{
		data.exp -= 20;
		docas_exp = data.exp;
		level_up++;
	}
	if (level_up > 0)
	{
		data.level += level_up;
		for (int i = 0; i < docas_exp; i++)
		{
			exp_pole.push_back(1);
		}
		for (int i = 0; i < 20 - docas_exp; i++)
		{
			exp_pole.push_back(0);
		}
	}
	else
	{
		for (int i = 0; i < data.exp - n_exp; i++)
		{
			exp_pole.push_back(2);
		}
		for (int i = 0; i < n_exp; i++)
		{
			exp_pole.push_back(1);
		}
		for (int i = 0; i < 20 - data.exp; i++)
		{
			exp_pole.push_back(0);
		}
	}
}

void MenuKonecKola::VykresleniKonecKola(Profily& data)
{	
	for (int i = 3; i <= 16; i++)
	{
		set.SetCursorPosition(4, i);
		wcout << L"\x2551";
	}
	for (int i = 3; i <= 16; i++)
	{
		set.SetCursorPosition(35, i);
		wcout << L"\x2551";
	}
	set.SetCursorPosition(4, 2);
	wcout << L"\x2554";
	for (int i = 0; i < 30; i++)
	{
		wcout << L"\x2550";
	}
	wcout << L"\x2557";
	set.SetCursorPosition(4, 6);
	wcout << L"\x2560";
	for (int i = 0; i < 30; i++)
	{
		wcout << L"\x2550";
	}
	std::wcout << L"\x2563";
	set.SetCursorPosition(4, 17);
	std::wcout << L"\x255a";
	for (int i = 0; i < 30; i++)
	{
		wcout << L"\x2550";
	}
	std::wcout << L"\x255d";
}
void MenuKonecKola::VykresleniLevelBar()
{
	set.SetCursorPosition(10, 14);
	for (int i = 0; i < exp_pole.size(); i++)
	{
		if (exp_pole.at(i) == 2)
			std::wcout << L"\x2588";
		if (exp_pole.at(i) == 1)
			std::wcout << L"\x2593";
		if (exp_pole.at(i) == 0)
			std::wcout << L"\x2591";
	}
}
void MenuKonecKola::TextVykresleniVyhra(Profily& data)
{
	text = transl.NacteniTextHlavni(data);

	///-------  Text  -------//

	set.SetCursorPosition(14, 4);
	std::wcout << text.at(1);
	set.SetCursorPosition(6, 16);
	std::wcout << text.at(2);
	set.SetCursorPosition(27, 16);
	std::wcout << text.at(3);
	set.SetCursorPosition(6, 8);
	std::wcout << text.at(4) << data.highscore_cas;
	set.SetCursorPosition(8, 10);
	std::wcout << text.at(5) << data.cas;
	set.SetCursorPosition(16, 12);
	std::wcout << text.at(7) << data.level;
}
void MenuKonecKola::TextVykresleniProhra(Profily& data)
{
	text = transl.NacteniTextKonecKola(data);

	///-------  Text  -------//

	set.SetCursorPosition(14, 4);
	std::wcout << text.at(0);
	set.SetCursorPosition(6, 16);
	std::wcout << text.at(2);
	set.SetCursorPosition(27, 16);
	std::wcout << text.at(3);
	set.SetCursorPosition(6, 8);
	std::wcout << text.at(4);
	if (data.highscore_cas == 0)
		std::wcout << '-';
	else
		std::wcout << data.highscore_cas;
	set.SetCursorPosition(8, 10);
	std::wcout << text.at(6) << data.pocet_bloku;
	set.SetCursorPosition(16, 12);
	std::wcout << text.at(7) << data.level;
}