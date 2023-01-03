#include "Intro.h"

bool Intro::IntroDo()
{
	int n = 0;
	int a = 0;
	for (int j = 0; j < 9; j++)
	{
		if (j == 0)
			n = 6;
		else if (j == 1)
		{
			RozbitiBlokuIntro(8, 10, 2);
			mic.ax = -1;
			n = 2;
		}
		else if (j == 2)
		{
			RozbitiBlokuIntro(5, 7, 1);
			mic.ay = 1;
			n = 1;
		}
		else if (j == 3)
		{
			RozbitiBlokuIntro(3, 9, 2);
			mic.ax = 1;
			n = 4;
		}
		else if (j == 4)
		{
			RozbitiBlokuIntro(9, 13, 1);
			mic.ax = -1;
			n = 1;
		}
		else if (j == 5)
		{
			mic.ay = -1;
			n = 3;
		}
		else if (j == 6)
		{
			RozbitiBlokuIntro(3, 11, 1);
			mic.ax = 1;
			n = 2;
		}
		else if (j == 7)
		{
			RozbitiBlokuIntro(7, 8, 1);
			mic.ax = -1;
			mic.ay = 1;
			n = 15;
		}
		for (int i = 0; i < n; i++, a++)
		{
			if (a >= 21)
			{
				VykresleniVybuchIntro(a - 21);
			}
			if (j >= 5 && a < 21)
			{
				if (a > 14 && a < 18)
				{
					SmazaniHoupacka();
					VykresleniHoupacka(a - 14);
				}
				VykresleniObjekt(bomba_e, bomba.x, bomba.y, bomba.skin);
			}
			if (a < 25)
				VykresleniObjekt(mic_e, mic.x, mic.y, mic.skin);


			Sleep(200);
			if (VstupIntro())
			{
				if (j >= 5 && a < 21)
					SmazaniObjekt(bomba_e, bomba.x, bomba.y);
				if (a < 25)
					SmazaniObjekt(mic_e, mic.x, mic.y);
				VypocetZrychleni(mic_e, mic.x_d, mic.y_d, mic.x, mic.y, mic.ax, mic.ay);
				if (j == 5 )
				{
					bomba.y--;
					if (i == 2)
						bomba.x--;
				}
				else if (j == 6)
				{
					bomba.y--;
					if (i == 1)
						bomba.x--;
				}
				else if (j == 7)
				{
					bomba.y--;
					if (i == 1)
						bomba.x--;
				}
			}
			else
				return 0;
		}
	}
	VykresleniLogoIntro();
	Sleep(3000);
	return 1;
}

bool Intro::VstupIntro()
{
	if (_kbhit())
		return 0;
	else
		return 1;
}

void Intro::VykresleniStart()
{
	set.SetCursorPosition(0, 0);
	for (int j = 0; j < vyska; j++)
	{
		for (int i = 0; i < delka; i++)
		{
			if (j == 0 && i == 0)
			{
				wcout << L"\x2554";
			}
			else if (i == 0 && j == vyska - 1)
			{
				wcout << L"\x255a";
			}
			else if (j == 0 && i == delka - 1)
			{
				wcout << L"\x2557";
			}
			else if (j == vyska - 1 && i == delka - 1)
			{
				wcout << L"\x255d";
			}
			else if (j == 0 || j == vyska - 1)
			{
				wcout << L"\x2550";
			}
			else if (i == 0 || i == delka - 1)
			{
				wcout << L"\x2551";
			}
			else
			{
				wcout << ' ';
			}
		}
		if (!(j == vyska - 1))
			wcout << '\n';
	}
}
void Intro::VykresleniHoupacka(int poloha)
{
	int m = 7;
	int n = 0;

	if (poloha == 0)
	{
		n = 16;

		set.SetCursorPosition(m, n - 1);
		wcout << L"\x2584";
		for (int i = 0; i < 3; i++, m += 2, n++)
		{
			set.SetCursorPosition(m, n);
			wcout << L"\x2580";
			wcout << L"\x2588";
			wcout << L"\x2584";
		}
		set.SetCursorPosition(m, n);
		wcout << L"\x2580";
	}
	if (poloha == 1)
	{
		n = 16;
		for (int j = 0; j < 2; j++, n++, m += 3)
		{
			for (int i = 0; i < 2; i++, m++)
			{
				set.SetCursorPosition(m, n);
				wcout << L"\x2584";
				set.SetCursorPosition(m, n + 1);
				wcout << L"\x2580";
			}
		}
		n = 17;
		m = 9;
		for (int i = 0; i < 3; i++, m++)
		{
			set.SetCursorPosition(m, n);
			wcout << L"\x2588";
		}
	}
	if (poloha == 2)
	{
		n = 17;
		set.SetCursorPosition(m - 1, n);
		wcout << L"\x2590";

		for (int i = 0; i < 7; i++, m++)
		{
			set.SetCursorPosition(m, n);
			wcout << L"\x2588";
		}
		set.SetCursorPosition(m, n);
		wcout << L"\x258c";
	}
	if (poloha == 3)
	{
		n = 17;
		for (int j = 0; j < 2; j++, n--, m += 3)
		{
			for (int i = 0; i < 2; i++, m++)
			{
				set.SetCursorPosition(m, n);
				wcout << L"\x2584";
				set.SetCursorPosition(m, n + 1);
				wcout << L"\x2580";
			}
		}
		n = 17;
		m = 9;
		for (int i = 0; i < 3; i++, m++)
		{
			set.SetCursorPosition(m, n);
			wcout << L"\x2588";
		}
	}
	if (poloha == 4)
	{
		n = 18;

		set.SetCursorPosition(m, n + 1);
		wcout << L"\x2580";
		for (int i = 0; i < 3; i++, m += 2, n--)
		{
			set.SetCursorPosition(m, n);
			wcout << L"\x2584";
			wcout << L"\x2588";
			wcout << L"\x2580";
		}
		set.SetCursorPosition(m, n);
		wcout << L"\x2584";
	}




	set.SetCursorPosition(10, 18);
	wcout << L"\x25b2";
	set.SetCursorPosition(10, 19);
	wcout << L"\x2580";
}
void Intro::SmazaniHoupacka()
{
	int m = 6, n = 15;

	for (int j = 0; j < 5; j++, n++)
	{
		m = 6;
		for (int i = 0; i < 9; i++, m++)
		{
			set.SetCursorPosition(m, n);
			wcout << " ";
		}
	}
}
void Intro::VykresleniBlokyIntro()
{
	for (int i = 1; i <= 5; i++)
	{
		set.SetCursorPosition(1, i);
		for (int j = 0; j < 9; j++)
		{
			wcout << L"\x2593";
		}
	}
	for (int i = 6; i <= 7; i++)
	{
		set.SetCursorPosition(2, i);
		for (int j = 0; j < 8; j++)
		{
			wcout << L"\x2592";
		}
	}
	set.SetCursorPosition(9, 1);
	wcout << L"\x2592";
	set.SetCursorPosition(9, 2);
	wcout << L"\x2592";
	set.SetCursorPosition(10, 1);
	wcout << L"\x2591";
	set.SetCursorPosition(10, 2);
	wcout << L"\x2592";
	set.SetCursorPosition(10, 3);
	wcout << L"\x2592";
	set.SetCursorPosition(10, 4);
	wcout << L"\x2592";
	set.SetCursorPosition(10, 6);
	wcout << L"\x2591";
	set.SetCursorPosition(10, 7);
	wcout << L"\x2591";
	set.SetCursorPosition(11, 6);
	wcout << L"\x2591";
	set.SetCursorPosition(11, 1);
	wcout << L"\x2591";
	set.SetCursorPosition(11, 2);
	wcout << L"\x2591";
	set.SetCursorPosition(8, 6);
	wcout << L"\x2593";
	set.SetCursorPosition(9, 6);
	wcout << L"\x2593";
	set.SetCursorPosition(8, 7);
	wcout << L"\x2593";
	set.SetCursorPosition(9, 7);
	wcout << L"\x2593";
	set.SetCursorPosition(8, 8);
	wcout << L"\x2591";
	set.SetCursorPosition(7, 8);
	wcout << L"\x2591";
	set.SetCursorPosition(10, 5);
	wcout << L"\x2592";
	set.SetCursorPosition(11, 4);
	wcout << L"\x2592";
	set.SetCursorPosition(11, 5);
	wcout << L"\x2592";
	set.SetCursorPosition(3, 5);
	wcout << L"\x2592";
	set.SetCursorPosition(4, 4);
	wcout << L"\x2592";
	set.SetCursorPosition(4, 5);
	wcout << L"\x2592";
	set.SetCursorPosition(5, 5);
	wcout << L"\x2592";
	set.SetCursorPosition(7, 5);
	wcout << L"\x2592";
	set.SetCursorPosition(1, 6);
	wcout << L"\x2592";
	set.SetCursorPosition(3, 7);
	wcout << L"\x2592";
	set.SetCursorPosition(4, 7);
	wcout << L"\x2591";
	set.SetCursorPosition(5, 7);
	wcout << L"\x2591";
	set.SetCursorPosition(3, 8);
	wcout << L"\x2592";
	set.SetCursorPosition(3, 9);
	wcout << L"\x2592";
	set.SetCursorPosition(3, 10);
	wcout << L"\x2591";
	set.SetCursorPosition(3, 11);
	wcout << L"\x2591";
	set.SetCursorPosition(2, 9);
	wcout << L"\x2592";
	set.SetCursorPosition(2, 10);
	wcout << L"\x2592";
	set.SetCursorPosition(9, 8);
	wcout << L"\x2593";
	set.SetCursorPosition(10, 8);
	wcout << L"\x2593";
	set.SetCursorPosition(9, 9);
	wcout << L"\x2593";
	set.SetCursorPosition(9, 10);
	wcout << L"\x2592";
	set.SetCursorPosition(8, 9);
	wcout << L"\x2592";
	set.SetCursorPosition(8, 10);
	wcout << L"\x2592";
	set.SetCursorPosition(10, 9);
	wcout << L"\x2592";
	set.SetCursorPosition(9, 11);
	wcout << L"\x2591";
	set.SetCursorPosition(9, 12);
	wcout << L"\x2591";
	set.SetCursorPosition(9, 13);
	wcout << L"\x2591";
	set.SetCursorPosition(11, 9);
	wcout << L"\x2591";
}
void Intro::RozbitiBlokuIntro(int x, int y, int stupen)
{
	set.SetCursorPosition(x, y);
	if (stupen == 3)
		wcout << L"\x2592";
	else if (stupen == 2)
		wcout << L"\x2591";
	else if (stupen == 1)
		wcout << " ";
}
void Intro::VykresleniVybuchIntro(int vzdalenost)
{
	int zavory = 0;
	double v1 = 0;
	double v2 = 0;

	if (vzdalenost < 4)
	{
		zavory = vzdalenost;

		v1 = vzdalenost / 3;
		v2 = vzdalenost * 2 / 3;
	}
	else if (vzdalenost > 13)
	{
		zavory = 10;
		v1 = vzdalenost * 2 / 3;
		v2 = vzdalenost * 4 / 5;
	}
	else
	{
		zavory = vzdalenost - 3;

		v1 = vzdalenost * 2 / 3;
		v2 = vzdalenost * 4 / 5;
	}


	for (int j = -zavory; j <= zavory; j++)
	{
		for (int i = -zavory; i <= zavory; i++)
		{
			if ((abs(i) + abs(j)) <= vzdalenost)
			{
				set.SetCursorPosition(10 - i, 10 - j);
				if (abs(i) + abs(j) <= v1)
					wcout << L"\x2593";
				if (abs(i) + abs(j) > v1 && abs(i) + abs(j) <= v2)
					wcout << L"\x2592";
				if (abs(i) + abs(j) > v2)
					wcout << L"\x2591";
			}
		}
	}
}
void Intro::VykresleniLogoIntro()
{
	int n = 7;
	for (int j = 0; j < 7; j++, n++)
	{
		Sleep(200);
		int m = 1;
		for (int i = 0; i < 19; i++, m++)
		{
			if ( i % 5 != 4)
			{
				if (i == 0 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 
					|| j == 0 && (i <= 9 || i >= 15) || (j == 2 || j == 3) && i == 11 
					|| (j == 4 || j == 5) && i == 12 || i == 3 && (j > 0 && j < 4)
					|| j == 3 && (i == 1 || i == 2) || j == 6 && ( i == 6 || i == 7 || i == 16 || i == 17) 
					|| i == 18 && (j == 3 || j == 4 || j == 5 || j == 6) || j == 3 && i == 17)
				{
					set.SetCursorPosition(m, n);
					wcout << " ";
				}
			}
			
		}
	}
}