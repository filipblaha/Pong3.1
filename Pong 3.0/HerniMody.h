#pragma once
#include "Profily.h"
#include "Plosina.h"
#include "Mic.h"

class HerniMody
{
public:

	HerniMody()
	{}
	HerniMody(Profily& data)
	{
		data.VybraniProfilu(1);

		pocet_zivotu = 2;
		cas = 0;

		VykresleniPole();
		VykresleniBloky();
		VykresleniPlosina();
		VykresleniObjekt(mic.x, mic.y, mic.skin);
		VykresleniHUD();
	}

	void VstupHra(Profily data, bool start = 0);
	void Vykresleni();
	void Smazani();
	void Logika();


protected:
	Commands set;
	Profily data;
	Plosina plosina;
	HraciPole pole;
	Mic mic;

	enum objekt_e
	{
		mic_e,
		bomba_e,
	};

	int pocet_bloku = 0;
	int pocet_rozbitych_bloku = 0;
	int pocet_zivotu = 0;
	int cas = 0;
	bool kolize_s_blokem = 0;

	//-----------------------  Skiny -----------------------//

	const wchar_t* bomba_skin = L"\x263c";
	const wchar_t* bomba_skin_start = L"\x25cc";
	const wchar_t* slow_skin = L"\x25ca";
	const wchar_t* zivoty_skin = L"\x2665";

	//-----------------------  Bloky  -----------------------//
	
	


	//-----------------------  Vykresleni / Smazani -----------------------//

	void VykresleniPole();
	void VykresleniBloky();
	void VykresleniPlosina();
	void VykresleniObjekt(int objekt_x, int objekt_y, const wchar_t* skin);
	void VykresleniHUD();

	void SmazaniBloky();	
	void SmazaniPlosina();
	void SmazaniObjekt(int objekt_x, int objekt_y);
	
	//-----------------------  Logika -----------------------//

	void KolizeObjekt(int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay);
	void PosunPlosina();
	void VypocetZrychleni(int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay);

	//-----------------------  Vybuch -----------------------//

	void BlokyVybuch(int objekt_x, int objekt_y, int objekt_ax, int objekt_ay, int vzdalenost);

};
