#include "HerniMody.h"

//-----------------------  Input -----------------------//

void HerniMody::VstupHra(bool start)
{
	if (GetAsyncKeyState(data.pohyb_vlevo)) //if (_getch() == 'd')
	{
		if (!(plosina.x == pole.delka - plosina.velikost - 1)) //zed vpravo
		{
			plosina.pohyb = 1;
		}
	}
	else if (GetAsyncKeyState(data.pohyb_vpravo)) //else if (_getch() == 'a')
	{
		if (!(plosina.x == 1)) // zed vlevo
		{
			plosina.pohyb = -1;
		}
	}
	/*else if (GetAsyncKeyState(data.pouziti_schopnosti))
	{
		if (navod.slow)
		{
			navod.slow = 0;
			smazani_HUD_power_up(navod);
			navod.trvani = 1;

		}
	}*/
	else
		plosina.pohyb = 0;
	if (start)
		mic.ax = plosina.pohyb;
}

//-----------------------  Vykresleni -----------------------//

void HerniMody::VykresleniPole()
{
	set.SetCursorPosition(0, 0);
	for (int j = 0; j < pole.vyska - 1; j++)
	{
		for (int i = 0; i < pole.delka; i++)
		{
			if (j == 0 || i == 0 || i == pole.delka - 1)
			{
				wcout << pole.zed_skin;
			}
			else
			{
				wcout << " ";
			}
		}
		wcout << "\n";
	}
}
void HerniMody::VykresleniBloky()
{
	for (int j = 0; j < pole.bloky.size(); j++)
	{
		for (int i = 0; i < pole.bloky.at(j).size(); i++)
		{
			if (pole.bloky.at(j).at(i) == 1)
			{
				set.SetCursorPosition(i, j);
				std::wcout << pole.blok1_skin;
				pocet_bloku++;
			}
			if (pole.bloky.at(j).at(i) == 2)
			{
				set.SetCursorPosition(i, j);
				std::wcout << pole.blok2_skin;
				pocet_bloku += 2;
			}
			if (pole.bloky.at(j).at(i) == 3)
			{
				set.SetCursorPosition(i, j);
				std::wcout << pole.blok3_skin;
				pocet_bloku +=  3;
			}
		}
	}
}
void HerniMody::VykresleniPlosina()
{
	set.SetCursorPosition(plosina.x, pole.vyska - 3);
	wcout << plosina.skin;
}
void HerniMody::VykresleniMic()
{
	set.SetCursorPosition(mic.x, mic.y);
	wcout << mic.skin;
}
void HerniMody::VykresleniHUD()
{
	set.SetCursorPosition(0, pole.vyska - 1);
	for (int i = 0; i < pole.delka; i++)
	{
		if (i == 0 || i == pole.delka - 1)
			std::wcout << L"\x2580";
		else
			std::wcout << '-';
	}
	set.SetCursorPosition(2, pole.vyska);
	std::wcout << pole.blok2_skin << pocet_bloku;

	set.SetCursorPosition(pole.delka - 4, pole.vyska);
	std::wcout << cas;

	set.SetCursorPosition(8, pole.vyska);
	for (int i = 0; i < pocet_zivotu; i++)
		std::wcout << zivoty_skin;
}