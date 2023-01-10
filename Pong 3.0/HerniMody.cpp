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
	else if (GetAsyncKeyState(39))
	{
		if (plosina.x != pole.delka - plosina.velikost - 1) //zed vpravo
			plosina.pohyb = 1;
		else
			plosina.pohyb = 0;
	}
	else if (GetAsyncKeyState(37))
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

	if (kolize_s_blokem)
		VykresleniBloky();
	if (pocet_snimku % mic.rychlost == 0)
		VykresleniObjekt(mic_e, mic.x, mic.y, mic.skin);

	if (pocet_snimku % bomba.rychlost == 0 && bomba.existence)
		VykresleniObjekt(bomba_e, bomba.x, bomba.y, bomba.skin);
	if (kolize_s_blokem_vybuch && bomba.pocitadlo <= 5)
		VykresleniVybuch(1, bomba.pocitadlo);
	if (kolize_s_blokem_vybuch && bomba.pocitadlo >= 6)
		VykresleniVybuch(0, bomba.pocitadlo - 6);/*
	if (bomba.pocitadlo == 4)
		VykresleniBloky();*/
}
void HerniMody::Smazani()
{
	if (Casomira())
		ZmenaCasomiraHUD();
	if (plosina.pohyb)
		SmazaniPlosina();

	if (kolize_s_blokem || kolize_s_blokem_vybuch)
		ZmenaBlokyHUD();

	if (pocet_snimku % mic.rychlost == mic.rychlost - 1)
		SmazaniObjekt(mic_e, mic.x, mic.y);

	if (pocet_snimku % bomba.rychlost == bomba.rychlost - 1 && bomba.existence)
		SmazaniObjekt(bomba_e, bomba.x, bomba.y);
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
	for (int j = 1; j < pole.bloky.size() - 1; j++)
	{
		for (int i = 1; i < pole.bloky.at(j).size() - 1; i++)
		{
			if (pole.bloky.at(j).at(i) == 1)
			{
				set.SetCursorPosition(i, j);
				wcout << pole.blok1_skin;
			}
			else if (pole.bloky.at(j).at(i) == 2)
			{
				set.SetCursorPosition(i, j);
				wcout << pole.blok2_skin;
			}
			else if (pole.bloky.at(j).at(i) == 3)
			{
				set.SetCursorPosition(i, j);
				wcout << pole.blok3_skin;
			}
			else if (pole.bloky.at(j).at(i) == 0)
			{
				set.SetCursorPosition(i, j);
				wcout << " ";
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
void HerniMody::VykresleniObjekt(int objekt, int objekt_x, int objekt_y, const wchar_t* skin)
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
void HerniMody::VykresleniVybuch(bool vybuch, int vzdalenost)
{
	if (vzdalenost > 3)
		vzdalenost = 3;

	for (int j = 0; j < pole.vybuch.at(0).size(); j++)
	{
		for (int i = 0; i < pole.vybuch.at(0).at(j).size(); i++)
		{
			set.SetCursorPosition(pole.vybuch.at(0).at(j).at(i), pole.vybuch.at(1).at(j).at(i));
			if (vybuch && pole.vybuch.at(2).at(j).at(i) <= vzdalenost || !vybuch && pole.vybuch.at(2).at(j).at(i) > vzdalenost)
			{
				if (pole.vybuch.at(2).at(j).at(i) <= 1)
					wcout << L"\x2593";
				else if (pole.vybuch.at(2).at(j).at(i) > 1)
					wcout << L"\x2592";
			}
			else if (!vybuch && pole.vybuch.at(2).at(j).at(i) <= vzdalenost)
			{
				if (pole.bloky.at(pole.vybuch.at(1).at(j).at(i)).at(pole.vybuch.at(0).at(j).at(i)) == 1)
				{
					wcout << pole.blok1_skin;
				}
				if (pole.bloky.at(pole.vybuch.at(1).at(j).at(i)).at(pole.vybuch.at(0).at(j).at(i)) == 2)
				{
					wcout << pole.blok2_skin;
				}
				if (pole.bloky.at(pole.vybuch.at(1).at(j).at(i)).at(pole.vybuch.at(0).at(j).at(i)) == 3)
				{
					wcout << pole.blok3_skin;
				}
				if (pole.bloky.at(pole.vybuch.at(1).at(j).at(i)).at(pole.vybuch.at(0).at(j).at(i)) == 0 ||
					pole.bloky.at(pole.vybuch.at(1).at(j).at(i)).at(pole.vybuch.at(0).at(j).at(i)) == -1)
				{
					wcout << " ";
				}
			}
		}
	}
}
void HerniMody::SmazaniPlosina()
{
	set.SetCursorPosition(plosina.x, plosina.y);
	for (int i = 0; i < plosina.velikost; i++)
	{
		std::wcout << " ";
	}
}
void HerniMody::SmazaniObjekt(int objekt, int objekt_x, int objekt_y)
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

	//--------  Prohra / Vyhra  --------//
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

	//--------  Plosina  --------//
	PosunPlosina();

	//--------  Mic  --------//
	if (pocet_snimku % mic.rychlost == 0)
	{
		KolizeObjekt(mic_e, mic.x_d, mic.y_d, mic.x, mic.y, mic.ax, mic.ay);
		VypocetZrychleni(mic_e, mic.x_d, mic.y_d, mic.x, mic.y, mic.ax, mic.ay);
	}

	//--------  Bomba  --------//
	if (pocet_snimku % bomba.rychlost == 0)
	{
		if (pocet_snimku == bomba.spawn_cas - 15)
		{
			bomba.existence_start = 1;
			bomba.SpawnPozice();
			bomba.Start();

			VykresleniObjekt(bomba_e, bomba.x, bomba.y, bomba.skin_start);
		}
		if (pocet_snimku == bomba.spawn_cas)
		{
			bomba.existence_start = 0;
			bomba.existence = 1;
			bomba.ay = 1;

			SmazaniObjekt(bomba_e, bomba.x, bomba.y);
		}

		if (bomba.existence)
		{
			if (pocet_snimku == bomba.spawn_cas + 210)
			{
				BlokyVybuch(bomba_e, bomba.x, bomba.y, 3);
				BombaZaniknuti();
			}

			KolizeObjekt(bomba_e, bomba.x_d, bomba.y_d, bomba.x, bomba.y, bomba.ax, bomba.ay);
			VypocetZrychleni(bomba_e, bomba.x_d, bomba.y_d, bomba.x, bomba.y, bomba.ax, bomba.ay);
		}
		if (bomba.y == plosina.y_start + 1 && bomba.existence)
			BombaZaniknuti();
	}

	//--------  Objekt x Objekt  --------//
	if (bomba.existence)
		KolizeObjektObjekt(mic_e, mic.x_d, mic.y_d, mic.x, mic.y, mic.ax, mic.ay, bomba_e, bomba.x_d, bomba.y_d, bomba.x, bomba.y, bomba.ax, bomba.ay);

	//--------  Vybuch  --------//
	if (kolize_s_blokem_vybuch && pocet_snimku % 4 == 1)
	{
		bomba.pocitadlo++;
	}
	if (bomba.pocitadlo == 10)
	{
		kolize_s_blokem_vybuch = 0;
		bomba.pocitadlo = 0;
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
void HerniMody::KolizeObjekt(int objekt, double objekt_x_d, double objekt_y_d, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay)
{
	KolizeObjektPlosina(0, objekt_x, objekt_y, objekt_ax, objekt_ay);
	KolizeObjektStena(0, objekt_x, objekt_y, objekt_ax, objekt_ay);

	if (objekt == mic_e)
	{
		BlokyJednotlive(mic_e, objekt_x_d, objekt_y_d, objekt_x, objekt_y, objekt_ax, objekt_ay);
	}

	else if (objekt == bomba_e)
	{
		int U = pole.bloky.at(objekt_y - 1).at(objekt_x);
		int D = pole.bloky.at(objekt_y + 1).at(objekt_x);
		int L = pole.bloky.at(objekt_y).at(objekt_x - 1);
		int R = pole.bloky.at(objekt_y).at(objekt_x + 1);

		int DR = pole.bloky.at(objekt_y + 1).at(objekt_x + 1);
		int UL = pole.bloky.at(objekt_y - 1).at(objekt_x - 1);
		int UR = pole.bloky.at(objekt_y - 1).at(objekt_x + 1);
		int DL = pole.bloky.at(objekt_y + 1).at(objekt_x - 1);

		if (L > 0 || R > 0 || U > 0 || D > 0 || UL > 0 && objekt_ax < 0 && objekt_ay < 0 || UR > 0 && objekt_ax > 0 && objekt_ay < 0 
			|| DL > 0 && objekt_ax < 0 && objekt_ay > 0 || DR > 0 && objekt_ax > 0 && objekt_ay > 0)
		{
			BlokyVybuch(bomba_e, objekt_x, objekt_y, 3);
			BombaZaniknuti();
		}
	}
}
void HerniMody::KolizeObjektPlosina(int objekt, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay)
{
	bool platform = (objekt_y == plosina.y - 1);

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
}
void HerniMody::KolizeObjektStena(int objekt, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay)
{
	bool wallU = (objekt_y == 1);
	bool wallL = (objekt_x == 1);
	bool wallR = (objekt_x == pole.delka - 2);

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
}
void HerniMody::KolizeObjektObjekt(int objekt_1, double& objekt_1_x_d, double& objekt_1_y_d, int& objekt_1_x, int& objekt_1_y, int& objekt_1_ax, int& objekt_1_ay, int objekt_2, double& objekt_2_x_d, double& objekt_2_y_d, int& objekt_2_x, int& objekt_2_y, int& objekt_2_ax, int& objekt_2_ay)
{
	if (objekt_1_x == objekt_2_x && objekt_1_y == objekt_2_y)
	{
		SmazaniObjekt(mic_e, objekt_1_x, objekt_1_y);

		VypocetZrychleni(objekt_1, objekt_1_x_d, objekt_1_y_d, objekt_1_x, objekt_1_y, objekt_1_ax, objekt_1_ay);
		VypocetZrychleni(objekt_2, objekt_2_x_d, objekt_2_y_d, objekt_2_x, objekt_2_y, objekt_2_ax, objekt_2_ay);

		int temp;

		temp = objekt_1_x_d;
		objekt_1_x_d = objekt_2_x_d;
		objekt_2_x_d = temp;

		temp = objekt_1_y_d;
		objekt_1_y_d = objekt_2_y_d;
		objekt_2_y_d = temp;

		temp = objekt_1_x;
		objekt_1_x = objekt_2_x;
		objekt_2_x = temp;

		temp = objekt_1_y;
		objekt_1_y = objekt_2_y;
		objekt_2_y = temp;

		temp = objekt_1_ax;
		objekt_1_ax = objekt_2_ax;
		objekt_2_ax = temp;

		temp = objekt_1_ay;
		objekt_1_ay = objekt_2_ay;
		objekt_2_ay = temp;
	}
}
void HerniMody::BombaZaniknuti()
{
	bomba.existence = 0;
	bomba.spawn_cas = bomba.SpawnCas() + pocet_snimku;
	SmazaniObjekt(bomba_e, bomba.x, bomba.y);
}
void HerniMody::VypocetZrychleni(int objekt, double& objekt_x_d, double& objekt_y_d, int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay)
{
	if (objekt_ax != 0)
		objekt_x_d += (1 / static_cast<double>(objekt_ax));
	if (objekt_ay != 0)
		objekt_y_d += (1 / static_cast<double>(objekt_ay));

	objekt_x = objekt_x_d;
	objekt_y = objekt_y_d;
}
void HerniMody::ZtrataZivotu(Profily& data)
{
	pocet_zivotu--;

	SmazaniPlosina();
	SmazaniObjekt(mic_e, mic.x, mic.y);
	mic.x = mic.x_d = mic.start_x;
	mic.y = mic.y_d = mic.start_y;
	mic.ax = 0;
	mic.ay = -1;
	plosina.x = plosina.x_start;

	if (bomba.existence)
	{
		BombaZaniknuti();
		bomba.spawn_cas++;
	}

	VykresleniObjekt(mic_e, mic.x, mic.y, mic.skin);
	VykresleniPlosina();
	ZmenaZivotyHUD();

	Sleep(800);
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

//-----------------------  Bloky Kolize -----------------------//

void HerniMody::BlokyJednotlive(int objekt, double objekt_x_d, double objekt_y_d, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay)
{
	kolize_s_blokem = 0;

	int temp = 0;

	int U = pole.bloky.at(objekt_y - 1).at(objekt_x);
	int D = pole.bloky.at(objekt_y + 1).at(objekt_x);
	int L = pole.bloky.at(objekt_y).at(objekt_x - 1);
	int R = pole.bloky.at(objekt_y).at(objekt_x + 1);

	int DR = pole.bloky.at(objekt_y + 1).at(objekt_x + 1);
	int UL = pole.bloky.at(objekt_y - 1).at(objekt_x - 1);
	int UR = pole.bloky.at(objekt_y - 1).at(objekt_x + 1);
	int DL = pole.bloky.at(objekt_y + 1).at(objekt_x - 1);

	while (pole.bloky.at(objekt_y_d + (1 / static_cast<double>(objekt_ay))).at(objekt_x_d + (1 / static_cast<double>(objekt_ax))) > 0 || 
		pole.bloky.at(objekt_y_d).at(objekt_x_d + (1 / static_cast<double>(objekt_ax))) > 0 ||
		pole.bloky.at(objekt_y_d + (1 / static_cast<double>(objekt_ay))).at(objekt_x_d) > 0 || (objekt_x_d + (1 / static_cast<double>(objekt_ax)) >= pole.delka - 1) || 
		(objekt_x_d + (1 / static_cast<double>(objekt_ax)) < 1) || (objekt_y_d + (1 / static_cast<double>(objekt_ay)) < 1))
	{
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
		if (pole.bloky.at(objekt_y_d + (1 / static_cast<double>(objekt_ay))).at(objekt_x_d) > 0 || (objekt_x_d + (1 / static_cast<double>(objekt_ax)) >= pole.delka - 1) ||
			(objekt_x_d + (1 / static_cast<double>(objekt_ax)) < 1) || (objekt_y_d + (1 / static_cast<double>(objekt_ay)) < 1))
		{
			KolizeObjektStena(mic_e, objekt_x, objekt_y, objekt_ax, objekt_ay);
		}
	}
}
void HerniMody::BlokyVybuch(int objekt, int objekt_x, int objekt_y, int vzdalenost)
{
	kolize_s_blokem_vybuch = 0;
	pole.vybuch.clear();
	pole.vybuch.resize(3);

	int leva_hranice, prava_hranice, dolni_hranice, horni_hranice;

	if (pole.vyska - 1 - objekt_y <= vzdalenost)
		dolni_hranice = pole.vyska - 2 - objekt_y;
	else
		dolni_hranice = vzdalenost;

	if (objekt_y <= vzdalenost)
		horni_hranice = objekt_y - 1;
	else
		horni_hranice = vzdalenost;

	if (objekt_x <= vzdalenost)
		leva_hranice = objekt_x - 1;
	else
		leva_hranice = vzdalenost;

	if (pole.delka - 1 - objekt_x <= vzdalenost)
		prava_hranice = pole.delka - 2 - objekt_x;
	else
		prava_hranice = vzdalenost;

	for (int j = -dolni_hranice; j <= horni_hranice; j++)
	{
		vector<int> temp0;
		vector<int> temp1;
		vector<int> temp2;
		for (int i = -prava_hranice; i <= leva_hranice; i++)
		{
			if (abs(i) + abs(j) <= vzdalenost && abs(i) != vzdalenost && abs(j) != vzdalenost)
			{
				if (pole.bloky.at(objekt_y - j).at(objekt_x - i) > 0)
				{
					if ((abs(i) + abs(j) == 1) && pole.bloky.at(objekt_y - j).at(objekt_x - i) == 3)
					{
						pole.bloky.at(objekt_y - j).at(objekt_x - i) -= 3;
						pocet_bloku -= 3;
						pocet_rozbitych_bloku += 3;
					}
					if ((abs(i) + abs(j) == 1) && pole.bloky.at(objekt_y - j).at(objekt_x - i) == 2)
					{
						pole.bloky.at(objekt_y - j).at(objekt_x - i) -= 2;
						pocet_bloku -= 2;
						pocet_rozbitych_bloku += 2;
					}
					else if (abs(i) + abs(j) == 2 && pole.bloky.at(objekt_y - j).at(objekt_x - i) >=  2)
					{
						pole.bloky.at(objekt_y - j).at(objekt_x - i) -= 2;
						pocet_bloku -= 2;
						pocet_rozbitych_bloku += 2;
					}
					else
					{
						pole.bloky.at(objekt_y - j).at(objekt_x - i)--;
						pocet_bloku--;
						pocet_rozbitych_bloku++;
					}
				}
				temp0.push_back(objekt_x - i);
				temp1.push_back(objekt_y - j);
				temp2.push_back(abs(i) + abs(j));
			}
		}
		pole.vybuch.at(0).push_back(temp0);
		pole.vybuch.at(1).push_back(temp1);
		pole.vybuch.at(2).push_back(temp2);
	}
	kolize_s_blokem_vybuch = 1;
}
