#include "HerniMody.h"

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