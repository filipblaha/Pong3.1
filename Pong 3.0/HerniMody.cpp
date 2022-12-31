#include "HerniMody.h"
#include <conio.h>

//-----------------------  Input -----------------------//

bool HerniMody::VstupHra(Profily data, bool start)
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
	else if (GetAsyncKeyState(37))
	{
		if (plosina.x != pole.delka - plosina.velikost - 1) //zed vpravo
			plosina.pohyb = 1;
		else
			plosina.pohyb = 0;
	}
	else if (GetAsyncKeyState(39))
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
	{
		mic.ax = plosina.pohyb;
		if (plosina.pohyb != 0)
			return 1;
		else
			return 0;
	}
}
//void HerniMody::VstupHra(Profily data, bool start)
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

	if (pocet_snimku % kvocient_rychlosti_hry == 0)
	{
		if (kolize_s_blokem)
			VykresleniBloky();
		VykresleniObjekt(mic.x, mic.y, mic.skin);
	}

}
void HerniMody::Smazani()
{
	if (Casomira())
		ZmenaCasomiraHUD();
	if (plosina.pohyb)
		SmazaniPlosina();

	if (pocet_snimku % kvocient_rychlosti_hry == kvocient_rychlosti_hry - 1)
	{
		SmazaniObjekt(mic.x, mic.y);
		if (kolize_s_blokem)
			ZmenaBlokyHUD();
	}
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
		set.SetCursorPosition(1, j);
		for (int i = 0; i < pole.bloky.at(j).size(); i++)
		{
			if (pole.bloky.at(j).at(i) == 1)
			{
				set.SetCursorPosition(i, j);
				std::wcout << pole.blok1_skin;
			}
			if (pole.bloky.at(j).at(i) == 2)
			{
				set.SetCursorPosition(i, j);
				std::wcout << pole.blok2_skin;
			}
			if (pole.bloky.at(j).at(i) == 3)
			{
				set.SetCursorPosition(i, j);
				std::wcout << pole.blok3_skin;
			}
			if (pole.bloky.at(j).at(i) == 0 && i < pole.bloky.size() - 2 && j > 0 && j < pole.bloky.at(j).size() / 2)
			{
				std::wcout << " ";
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

	set.SetCursorPosition(8, pole.vyska);
	for (int i = 0; i < pocet_zivotu; i++)
		std::wcout << zivoty_skin;

	set.SetCursorPosition(pole.delka - 4, pole.vyska);
	std::wcout << cas;
}
void HerniMody::SmazaniPlosina()
{
	set.SetCursorPosition(plosina.x, plosina.y);
	for (int i = 0; i < plosina.velikost; i++)
	{
		std::wcout << " ";
	}
}
void HerniMody::SmazaniObjekt(int objekt_x, int objekt_y)
{
	set.SetCursorPosition(objekt_x, objekt_y);
	std::wcout << " ";
}

void HerniMody::ZmenaBlokyHUD()
{
	set.SetCursorPosition(3, pole.vyska);
	std::wcout << "    ";
	set.SetCursorPosition(3, pole.vyska);
	std::wcout << pocet_bloku;
}
void HerniMody::ZmenaZivotyHUD()
{
	set.SetCursorPosition(8, pole.vyska);
	std::wcout << "    ";
	set.SetCursorPosition(8, pole.vyska);
	std::wcout << zivoty_skin;
}
void HerniMody::ZmenaCasomiraHUD()
{
	set.SetCursorPosition(pole.delka - 4, pole.vyska);
	std::wcout << "    ";
	set.SetCursorPosition(pole.delka - 4, pole.vyska);
	std::wcout << cas;
}

//-----------------------  Logika -----------------------//

int HerniMody::Logika(Profily& data)
{
	pocet_snimku++;

	if (pocet_bloku == 0)
	{
		UlozeniDat(data);
		return 1;
	}
	if (mic.y == plosina.y_start + 1)
	{
		UlozeniDat(data);
		if (pocet_zivotu == 1)
			return 0;
		else
			ZtrataZivotu(data);
		return 2;
	}
	PosunPlosina();

	if (pocet_snimku % kvocient_rychlosti_hry == 0)
	{
		KolizeObjekt(mic.x_d, mic.y_d, mic.x, mic.y, mic.ax, mic.ay);
		VypocetZrychleni(mic.x_d, mic.y_d, mic.x, mic.y, mic.ax, mic.ay);
	}
	return 2;
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
void HerniMody::KolizeObjekt(double objekt_x_d, double objekt_y_d, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay)
{
	kolize_s_blokem = 0;

	int temp = 0;
	int C = pole.bloky.at(objekt_y).at(objekt_x);

	int U = pole.bloky.at(objekt_y - 1).at(objekt_x);
	int D = pole.bloky.at(objekt_y + 1).at(objekt_x);
	int L = pole.bloky.at(objekt_y).at(objekt_x - 1);
	int R = pole.bloky.at(objekt_y).at(objekt_x + 1);

	int DR = pole.bloky.at(objekt_y + 1).at(objekt_x + 1);
	int UL = pole.bloky.at(objekt_y - 1).at(objekt_x - 1);
	int UR = pole.bloky.at(objekt_y - 1).at(objekt_x + 1);
	int DL = pole.bloky.at(objekt_y + 1).at(objekt_x - 1);

	int SCX = objekt_x;
	int SCY = objekt_y;

	int SU = objekt_y - 1;
	int SL = objekt_x - 1;
	int SR = objekt_x + 1;
	int SD = objekt_y + 1;
	
	bool platform = (objekt_y == plosina.y - 1);
	bool wallU = (objekt_y == 1);
	bool wallL = (objekt_x == 1);
	bool wallR = (objekt_x == pole.delka - 2);

	////  plosina  ////
	if (platform)
	{
		if (objekt_x == plosina.x - 1) // kraj vlevo
		{
			objekt_ax = -1;
			objekt_ay = -3; 
		}
		else if (objekt_x == plosina.x) // vlevo
		{
			objekt_ax = -1;
			objekt_ay = -2;
		}
		else if (objekt_x == plosina.x + 1) // vlevo
		{
			objekt_ax = -1;
			objekt_ay = -1;
		}
		else if (objekt_x == plosina.x + 2) // vlevo
		{
			objekt_ax = -2;
			objekt_ay = -1;
		}


		else if (objekt_x == plosina.x + plosina.velikost - 3) // vpravo
		{
			objekt_ax = 2;
			objekt_ay = -1;
		}
		else if (objekt_x == plosina.x + plosina.velikost - 2) // vpravo
		{
			objekt_ax = 1;
			objekt_ay = -1;
		}
		else if (objekt_x == plosina.x + plosina.velikost - 1) // vpravo
		{
			objekt_ax = 1;
			objekt_ay = -2;
		}
		else if (objekt_x == plosina.x + plosina.velikost) // kraj vpravo
		{
			objekt_ax = 1;
			objekt_ay = -3;
		}

	}
	while (pole.bloky.at(objekt_y_d + (1 / static_cast<double>(objekt_ay))).at(objekt_x_d + (1 / static_cast<double>(objekt_ax))) > 0 || pole.bloky.at(objekt_y_d).at(objekt_x_d + (1 / static_cast<double>(objekt_ax))) > 0 ||
		pole.bloky.at(objekt_y_d + (1 / static_cast<double>(objekt_ay))).at(objekt_x_d) > 0 || (objekt_x_d + (1 / static_cast<double>(objekt_ax)) >= pole.delka - 1) || (objekt_x_d + (1 / static_cast<double>(objekt_ax)) < 1) || (objekt_y_d + (1 / static_cast<double>(objekt_ay)) <= 0))
	{
		////  steny ////

		if (wallR || wallL || wallU)
		{

			if (wallR || wallL) // prava / leva wall
			{
				objekt_ax = -objekt_ax;
			}
			if (wallU) // horni wall
			{
				objekt_ay = -objekt_ay;
			}
		}
		////  bloky  ////

		if (L > 0 || R > 0 || U > 0 || D > 0)
		{
			if (L > 0 && objekt_ax < 0) // levy
			{
				pole.bloky.at(objekt_y).at(objekt_x - 1)--;
				objekt_ax = -objekt_ax;
				pocet_bloku--;
				pocet_rozbitych_bloku++;
			}
			if (R > 0 && objekt_ax > 0) // pravy
			{
				pole.bloky.at(objekt_y).at(objekt_x + 1)--;
				objekt_ax = -objekt_ax;
				pocet_bloku--;
				pocet_rozbitych_bloku++;
			}
			if (U > 0 && objekt_ay < 0) // horni
			{
				pole.bloky.at(objekt_y - 1).at(objekt_x)--;
				objekt_ay = -objekt_ay;
				pocet_bloku--;
				pocet_rozbitych_bloku++;
			}
			if (D > 0 && objekt_ay > 0) // spodni
			{
				pole.bloky.at(objekt_y + 1).at(objekt_x)--;
				objekt_ay = -objekt_ay;
				pocet_bloku--;
				pocet_rozbitych_bloku++;
			}
			kolize_s_blokem = 1;
		}
		else if (UL > 0 || UR > 0 || DL > 0 || DR > 0)
		{
			temp = objekt_ax;
			if (DL > 0 && objekt_ax < 0 && objekt_ay  > 0) // levo/spodni
			{
				pole.bloky.at(objekt_y + 1).at(objekt_x - 1)--;
				objekt_ax = objekt_ay;
				objekt_ay = temp;
			}
			else if (DR > 0 && objekt_ax > 0 && objekt_ay > 0) // pravo/spodni
			{
				pole.bloky.at(objekt_y + 1).at(objekt_x + 1)--;
				objekt_ax = -objekt_ay;
				objekt_ay = -temp;
			}
			else if (UL > 0 && objekt_ax < 0 && objekt_ay < 0) // levo/horni
			{
				pole.bloky.at(objekt_y - 1).at(objekt_x - 1)--;
				objekt_ax = -objekt_ay;
				objekt_ay = -temp;
			}
			else if (UR > 0 && objekt_ax > 0 && objekt_ay < 0) // pravo/horni
			{
				pole.bloky.at(objekt_y - 1).at(objekt_x + 1)--;
				objekt_ax = objekt_ay;
				objekt_ay = temp;
			}
			kolize_s_blokem = 1;
			pocet_bloku--;
			pocet_rozbitych_bloku++;
		}
	}
}
void HerniMody::VypocetZrychleni(double& objekt_x_d, double& objekt_y_d, int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay)
{
	objekt_x_d += (1 / static_cast<double>(objekt_ax));
	objekt_y_d += (1 / static_cast<double>(objekt_ay));

	objekt_x = objekt_x_d;
	objekt_y = objekt_y_d;
}
void HerniMody::ZtrataZivotu(Profily& data)
{
	pocet_zivotu--;

	SmazaniPlosina();
	SmazaniObjekt(mic.x, mic.y);
	mic.x = mic.x_d = mic.start_x;
	mic.y = mic.y_d = mic.start_y;
	mic.ax = 0;
	mic.ay = -1;
	plosina.x = plosina.x_start;

	VykresleniObjekt(mic.x, mic.y, mic.skin);
	VykresleniPlosina();
	ZmenaZivotyHUD();

	while (!VstupHra(data, 1));
}
bool HerniMody::Casomira()
{
	if (pocet_snimku % 20 == 0)
	{
		cas++;
		return 1;
	}
	else
		return 0;
}
void HerniMody::SpocitaniBloku()
{
	for (int j = 0; j < pole.bloky.size(); j++)
	{
		for (int i = 0; i < pole.bloky.at(j).size(); i++)
		{
			if (pole.bloky.at(j).at(i) == 1)
				pocet_bloku++;
			if (pole.bloky.at(j).at(i) == 2)
				pocet_bloku += 2;
			if (pole.bloky.at(j).at(i) == 3)
				pocet_bloku += 3;
		}
	}
}

//-----------------------  Ulozeni dat -----------------------//

void HerniMody::UlozeniDat(Profily& data)
{
	data.cas = cas;
	data.pocet_rozbitych_bloku = pocet_rozbitych_bloku;
	data.pocet_bloku = pocet_bloku;
}

//-----------------------  Vybuch -----------------------//

void HerniMody::BlokyVybuch(int objekt_x, int objekt_y, int objekt_ax, int objekt_ay, int vzdalenost)
{
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
