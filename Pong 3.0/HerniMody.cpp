#include "HerniMody.h"

//-----------------------  Input -----------------------//

void HerniMody::VstupHra(Profily data, bool start)
{
	if (GetAsyncKeyState(data.pohyb_vpravo))
	{
		if (plosina.x != pole.delka - plosina.velikost - 1) //zed vpravo
			plosina.pohyb = 1;
		else
			plosina.pohyb = 0;
	}
	else if (GetAsyncKeyState(data.pohyb_vlevo))
	{
		if (plosina.x != 1) // zed vlevo
			plosina.pohyb = -1;
		else
			plosina.pohyb = 0;
	}
	/*else if (GetAsyncKeyState(data.pouziti_schopnosti))
	{
		if (slow)
		{
			slow = 0;
			smazani_HUD_power_up(navod);
			trvani = 1;

		}
	}*/
	else
		plosina.pohyb = 0;
	if (start)
		mic.ax = plosina.pohyb;
}
//#include <conio.h>
//void HerniMody::VstupHra(bool start)
//{
//	switch (_getch())
//	{
//	case 'd':
//	{
//		if (plosina.x != pole.delka - plosina.velikost - 1) //zed vpravo
//			plosina.pohyb = 1;
//		else
//			plosina.pohyb = 0;
//		break;
//	}
//	case 'a':
//	{
//		if (plosina.x != 1) // zed vlevo
//			plosina.pohyb = -1;
//		else
//			plosina.pohyb = 0;
//		break;
//	}
//	/*case ' ':
//	{
//		if (slow)
//		{
//			slow = 0;
//			smazani_HUD_power_up(navod);
//			trvani = 1;
//
//		}
//	}*/
//	default:
//	{
//		plosina.pohyb = 0;
//		break;
//	}
//	}
//	if (start)
//		mic.ax = plosina.pohyb;
//}

//-----------------------  Vykresleni / Smazani  -----------------------//

void HerniMody::Vykresleni()
{
	if (plosina.pohyb)
		VykresleniPlosina();
	VykresleniObjekt(mic.x, mic.y, mic.skin);

}
void HerniMody::Smazani()
{
	SmazaniBloky();
	if (plosina.pohyb)
		SmazaniPlosina();
	SmazaniObjekt(mic.x, mic.y);
}

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
				pocet_bloku += 3;
			}
		}
	}
}
void HerniMody::VykresleniPlosina()
{
	list<wchar_t>::iterator itr;
	set.SetCursorPosition(plosina.x, plosina.y);
	for (itr = plosina.skin.begin(); itr != plosina.skin.end(); itr++)
	{
		wcout << *itr;
	}
}
void HerniMody::VykresleniObjekt(int objekt_x, int objekt_y, const wchar_t* skin)
{
	set.SetCursorPosition(objekt_x, objekt_y);
	wcout << skin;
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

void HerniMody::SmazaniBloky()
{
	int C = pole.bloky.at(mic.y).at(mic.x);

	int U = pole.bloky.at(mic.y - 1).at(mic.x);
	int D = pole.bloky.at(mic.y + 1).at(mic.x);
	int L = pole.bloky.at(mic.y).at(mic.x - 1);
	int R = pole.bloky.at(mic.y).at(mic.x + 1);

	int DR = pole.bloky.at(mic.y + 1).at(mic.x + 1);
	int UL = pole.bloky.at(mic.y - 1).at(mic.x - 1);
	int UR = pole.bloky.at(mic.y - 1).at(mic.x + 1);
	int DL = pole.bloky.at(mic.y + 1).at(mic.x - 1);

	int SCX = mic.x;
	int SCY = mic.y;

	int SU = mic.y - 1;
	int SL = mic.x - 1;
	int SR = mic.x + 1;
	int SD = mic.y + 1;

	int platform = (mic.y == plosina.y - 1);
	int wallU = (mic.y == 1);
	int wallL = (mic.x == 1);
	int wallR = (mic.x == pole.delka - 2);

	if (L > 0 || U > 0 || R > 0 || D > 0)
	{
		if (L > 0) // levy
		{
			set.SetCursorPosition(SL, SCY);
			if (L == 1)
				std::wcout << " ";
			if (L == 2)
				std::wcout << pole.blok1_skin;
			if (L == 3)
				std::wcout << pole.blok2_skin;
		}
		if (R > 0) // pravy
		{
			set.SetCursorPosition(SR, SCY);
			if (R == 1)
				std::wcout << " ";
			if (R == 2)
				std::wcout << pole.blok1_skin;
			if (R == 3)
				std::wcout << pole.blok2_skin;
		}
		if (U > 0) // horni
		{
			set.SetCursorPosition(SCX, SU);
			if (U == 1)
				std::wcout << " ";
			if (U == 2)
				std::wcout << pole.blok1_skin;
			if (U == 3)
				std::wcout << pole.blok2_skin;
		}
		if (D > 0) // spodni
		{
			set.SetCursorPosition(SCX, SD);
			if (D == 1)
				std::wcout << " ";
			if (D == 2)
				std::wcout << pole.blok1_skin;
			if (D == 3)
				std::wcout << pole.blok2_skin;
		}
	}
	else if ((platform || wallR || wallL || wallU || L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
	{
		if (DR > 0)
		{
			if (U > 0 || wallU) // pravo/dolni - shora
			{
				if (U > 0)
				{
					set.SetCursorPosition(SCX, SU);
					if (U == 1)
						std::wcout << " ";
					if (U == 2)
						std::wcout << pole.blok1_skin;
					if (U == 3)
						std::wcout << pole.blok2_skin;
				}

			}
			if (L > 0 || wallL) // pravo/dolni - zleva
			{
				if (L > 0)
				{
					set.SetCursorPosition(SL, SCY);
					if (L == 1)
						std::wcout << " ";
					if (L == 2)
						std::wcout << pole.blok1_skin;
					if (L == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			set.SetCursorPosition(SR, SD);
			if (DR == 1)
				std::wcout << " ";
			if (DR == 2)
				std::wcout << pole.blok1_skin;
			if (DR == 3)
				std::wcout << pole.blok2_skin;
		}
		if (UL > 0)
		{
			if (D > 0 || platform) // levo/horni - zdola
			{
				if (D > 0)
				{
					set.SetCursorPosition(SCX, SD);
					if (D == 1)
						std::wcout << " ";
					if (D == 2)
						std::wcout << pole.blok1_skin;
					if (D == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			if (R > 0 || wallR) // levo/horni - zprava
			{
				if (R > 0)
				{
					set.SetCursorPosition(SR, SCY);
					if (R == 1)
						std::wcout << " ";
					if (R == 2)
						std::wcout << pole.blok1_skin;
					if (R == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			set.SetCursorPosition(SL, SU);
			if (UL == 1)
				std::wcout << " ";
			if (UL == 2)
				std::wcout << pole.blok1_skin;
			if (UL == 3)
				std::wcout << pole.blok2_skin;
		}
		if (DL > 0)
		{
			if (U > 0 || wallU) // levo/dolni - shora
			{
				if (U > 0)
				{
					set.SetCursorPosition(SCX, SU);
					if (U == 1)
						std::wcout << " ";
					if (U == 2)
						std::wcout << pole.blok1_skin;
					if (U == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			if (R > 0 || wallR) // levo/dolni - zprava
			{
				if (R > 0)
				{
					set.SetCursorPosition(SR, SCY);
					if (R == 1)
						std::wcout << " ";
					if (R == 2)
						std::wcout << pole.blok1_skin;
					if (R == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			set.SetCursorPosition(SL, SD);
			if (DL == 1)
				std::wcout << " ";
			if (DL == 2)
				std::wcout << pole.blok1_skin;
			if (DL == 3)
				std::wcout << pole.blok2_skin;
		}
		if (UR > 0)
		{
			if (D > 0 || platform) // pravo/dolni - zdola
			{
				if (D > 0)
				{
					set.SetCursorPosition(SCX, SD);
					if (D == 1)
						std::wcout << " ";
					if (D == 2)
						std::wcout << pole.blok1_skin;
					if (D == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			if (L > 0 || wallL) // pravo/dolni - zleva
			{
				if (L > 0)
				{
					set.SetCursorPosition(SL, SCY);
					if (L == 1)
						std::wcout << " ";
					if (L == 2)
						std::wcout << pole.blok1_skin;
					if (L == 3)
						std::wcout << pole.blok2_skin;
				}
			}
			set.SetCursorPosition(SR, SU);
			if (UR == 1)
				std::wcout << " ";
			if (UR == 2)
				std::wcout << pole.blok1_skin;
			if (UR == 3)
				std::wcout << pole.blok2_skin;
		}
	}
	else if (!(platform || wallR || wallL || wallU || L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
	{
		if (DL > 0 && mic.ax == -1 && mic.ay == 1) // levo/spodni
		{
			set.SetCursorPosition(SL, SD);
			if (DL == 1)
				std::wcout << " ";
			if (DL == 2)
				std::wcout << pole.blok1_skin;
			if (DL == 3)
				std::wcout << pole.blok2_skin;
		}
		if (DR > 0 && mic.ax == 1 && mic.ay == 1) // pravo/spodni
		{
			set.SetCursorPosition(SR, SD);
			if (DR == 1)
				std::wcout << " ";
			if (DR == 2)
				std::wcout << pole.blok1_skin;
			if (DR == 3)
				std::wcout << pole.blok2_skin;
		}
		if (UL > 0 && mic.ax == -1 && mic.ay == -1) // levo/horni
		{
			set.SetCursorPosition(SL, SU);
			if (UL == 1)
				std::wcout << " ";
			if (UL == 2)
				std::wcout << pole.blok1_skin;
			if (UL == 3)
				std::wcout << pole.blok2_skin;
		}
		if (UR > 0 && mic.ax == 1 && mic.ay == -1) // pravo/horni
		{
			set.SetCursorPosition(SR, SU);
			if (UR == 1)
				std::wcout << " ";
			if (UR == 2)
				std::wcout << pole.blok1_skin;
			if (UR == 3)
				std::wcout << pole.blok2_skin;
		}

	}
}
void HerniMody::SmazaniPlosina()
{
	if (plosina.pohyb)
	{
		set.SetCursorPosition(plosina.x, plosina.y);
		for (int i = 0; i < plosina.velikost; i++)
		{
			std::wcout << " ";
		}
	}
}
void HerniMody::SmazaniObjekt(int objekt_x, int objekt_y)
{
	set.SetCursorPosition(objekt_x, objekt_y);
	std::wcout << " ";
}

//-----------------------  Logika -----------------------//

void HerniMody::Logika()
{
	PosunPlosina();
	KolizeObjekt(mic.x, mic.y, mic.ax, mic.ay);
	VypocetZrychleni(mic.x, mic.y, mic.ax, mic.ay);
}

void HerniMody::PosunPlosina()
{
	if (plosina.pohyb == 1)
	{
		plosina.x++;
	}
	if (plosina.pohyb == -1)
	{
		plosina.x--;
	}
}
void HerniMody::KolizeObjekt(int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay)
{
	int C = pole.bloky.at(mic.y).at(mic.x);

	int U = pole.bloky.at(mic.y - 1).at(mic.x);
	int D = pole.bloky.at(mic.y + 1).at(mic.x);
	int L = pole.bloky.at(mic.y).at(mic.x - 1);
	int R = pole.bloky.at(mic.y).at(mic.x + 1);

	int DR = pole.bloky.at(mic.y + 1).at(mic.x + 1);
	int UL = pole.bloky.at(mic.y - 1).at(mic.x - 1);
	int UR = pole.bloky.at(mic.y - 1).at(mic.x + 1);
	int DL = pole.bloky.at(mic.y + 1).at(mic.x - 1);

	int SCX = mic.x;
	int SCY = mic.y;

	int SU = mic.y - 1;
	int SL = mic.x - 1;
	int SR = mic.x + 1;
	int SD = mic.y + 1;

	int platform = (mic.y == plosina.y - 1);
	int wallU = (mic.y == 1);
	int wallL = (mic.x == 1);
	int wallR = (mic.x == pole.delka - 2);
	//if (!ztrata_zivotu && pokracovani)
	{
		////  plosina - mic  ////
		if (platform)
		{
			if (objekt_x > plosina.x - 1 && objekt_x <= (plosina.x + plosina.velikost / 2))
			{
				objekt_ay = -1; // vlevo
				objekt_ax = -1;
			}
			if (objekt_x >= (plosina.x + plosina.velikost / 2) && objekt_x < (plosina.x + plosina.velikost + 1))
			{
				objekt_ay = -1; // vpravo
				objekt_ax = 1;
			}
		}
		while (pole.bloky.at(objekt_y + objekt_ay).at(objekt_x + objekt_ax) > 0 || pole.bloky.at(objekt_y).at(objekt_x + objekt_ax) > 0 ||
			pole.bloky.at(objekt_y + objekt_ay).at(objekt_x) > 0 || (objekt_x + objekt_ax == pole.delka - 1) || (objekt_x + objekt_ax == 0) || (objekt_y + objekt_ay == 0))
		{
			if (wallR || wallL || wallU)
			{
				////  steny - mic ////

				if (wallR) // prava wall
				{
					objekt_ax = -1;
				}
				if (wallL) // leva wall
				{
					objekt_ax = 1;
				}
				if (wallU) // horni wall
				{
					objekt_ay = 1;
				}
			}
			////  bloky - mic  ////
			if (L > 0 || R > 0 || U > 0 || D > 0 || UL > 0 || UR > 0 || DL > 0 || DR > 0)
			{
				if (L > 0) // levy
				{
					pole.bloky.at(objekt_y).at(objekt_x - 1)--;
					objekt_ax = 1;
				}
				if (R > 0) // pravy
				{
					pole.bloky.at(objekt_y).at(objekt_x + 1)--;
					objekt_ax = -1;
				}
				if (U > 0) // hroni
				{
					pole.bloky.at(objekt_y - 1).at(objekt_x)--;
					objekt_ay = 1;
				}
				if (D > 0) // spodni
				{
					pole.bloky.at(objekt_y + 1).at(objekt_x)--;
					objekt_ay = -1;
				}
				if (DL > 0 && objekt_ax == -1 && objekt_ay == 1) // levo/spodni
				{
					pole.bloky.at(objekt_y + 1).at(objekt_x - 1)--;
					objekt_ax = 1;
					objekt_ay = -1;
				}
				if (DR > 0 && objekt_ax == 1 && objekt_ay == 1) // pravo/spodni
				{
					pole.bloky.at(objekt_y + 1).at(objekt_x + 1)--;
					objekt_ax = -1;
					objekt_ay = -1;
				}
				if (UL > 0 && objekt_ax == -1 && objekt_ay == -1) // levo/horni
				{
					pole.bloky.at(objekt_y - 1).at(objekt_x - 1)--;
					objekt_ax = 1;
					objekt_ay = 1;
				}
				if (UR > 0 && objekt_ax == 1 && objekt_ay == -1) // pravo/horni
				{
					pole.bloky.at(objekt_y - 1).at(objekt_x + 1)--;
					objekt_ax = -1;
					objekt_ay = 1;
				}
				kolize_s_blokem = 1;
				pocet_bloku--;
				pocet_rozbitych_bloku++;
			}
		}
	}
}
void HerniMody::VypocetZrychleni(int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay)
{
	if (objekt_ax == 1)
	{
		objekt_x++;
	}
	if (objekt_ax == -1)
	{
		objekt_x--;
	}
	if (objekt_ay == 1)
	{
		objekt_y++;
	}
	if (objekt_ay == -1)
	{
		objekt_y--;
	}
}

//-----------------------  Vybuch -----------------------//

void HerniMody::BlokyVybuch(int objekt_x, int objekt_y, int objekt_ax, int objekt_ay, int vzdalenost)
{
	int m, n;

	int leva_hranice, prava_hranice, dolni_hranice, horni_hranice;

	if (pole.vyska - objekt_y < vzdalenost)
		dolni_hranice = pole.vyska - objekt_y;
	else
		dolni_hranice = vzdalenost;

	if (objekt_y < vzdalenost)
		horni_hranice = objekt_y;
	else
		horni_hranice = vzdalenost;

	if (pole.vyska - objekt_x < vzdalenost)
		leva_hranice = pole.vyska - objekt_x;
	else
		leva_hranice = vzdalenost;

	if (objekt_x < vzdalenost)
		prava_hranice = objekt_x;
	else
		prava_hranice = vzdalenost;

	for (int j = -leva_hranice; j < prava_hranice; j++)
	{
		for (int i = -dolni_hranice; i < horni_hranice; i++)
		{
			if ((abs(i) + abs(j)) <= vzdalenost)
			{
				pole.bloky.at(objekt_ax - j).at(objekt_y - i)--;
			}
		}
	}




}