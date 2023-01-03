#pragma once
#include "Profily.h"
#include "Plosina.h"
#include "Mic.h"
#include "Bomba.h"

class HerniMody
{
public:

	HerniMody()
	{}
	HerniMody(Profily& data, int pocet_zivotu_v)
	{
		//data.VybraniProfilu(1);

		plosina.pohyb = 0;
		pocet_zivotu = pocet_zivotu_v;
		cas = 0;

		plosina.FormovaniSkiny(data);
		bomba.spawn_cas = bomba.SpawnCas();

		VykresleniPole();
		VykresleniBloky();
		SpocitaniBloku();
		VykresleniPlosina();
		VykresleniObjekt(mic_e, mic.x, mic.y, mic.skin);
		VykresleniHUD();
	}

	bool VstupHra(Profily data, bool start = 0);
	void Vykresleni();
	void Smazani();
	int Logika(Profily& data);



protected:
	Commands set;
	Profily data;
	Plosina plosina;
	HraciPole pole;
	Mic mic;
	Bomba bomba;

	enum objekt_e
	{
		mic_e,
		bomba_e,
	};

	int pocet_bloku = 0;
	int pocet_rozbitych_bloku = 0;
	int pocet_zivotu = 0;
	int pocet_snimku = 0;
	int cas = 0;

	bool kolize_s_blokem = 0;
	bool kolize_s_blokem_vybuch = 0;
	bool rozdil_rychlosti = 0;

	//-----------------------  Skiny -----------------------//

	const wchar_t* bomba_skin = L"\x263c";
	const wchar_t* bomba_skin_start = L"\x25cc";
	const wchar_t* slow_skin = L"\x25ca";
	const wchar_t* zivoty_skin = L"\x2665";

	//-----------------------  Vykresleni / Smazani -----------------------//

	void VykresleniPole();
	void VykresleniBloky();
	void VykresleniPlosina();
	void VykresleniObjekt(int objekt, int objekt_x, int objekt_y, const wchar_t* skin);
	void VykresleniHUD();
	void VykresleniVybuch(int vzdalenost);

	void SmazaniPlosina();
	void SmazaniObjekt(int objekt, int objekt_x, int objekt_y);

	void ZmenaBlokyHUD();
	void ZmenaZivotyHUD();
	void ZmenaCasomiraHUD();
	
	//-----------------------  Logika -----------------------//

	void KolizeObjekt(int objekt, double objekt_x_d, double objekt_y_d, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay);
	void KolizeObjektPlosina(int objekt, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay);
	void KolizeObjektStena(int objekt, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay);
	void KolizeObjektObjekt(int objekt_1, double& objekt_1_x_d, double& objekt_1_y_d, int& objekt_1_x, int& objekt_1_y, int& objekt_1_ax, int& objekt_1_ay, int objekt_2, double& objekt_2_x_d, double& objekt_2_y_d, int& objekt_2_x, int& objekt_2_y, int& objekt_2_ax, int& objekt_2_ay);
	void BombaZaniknuti();
	void PosunPlosina();
	void VypocetZrychleni(int objekt, double& objekt_x_d, double& objekt_y_d, int& objekt_x, int& objekt_y, int& objekt_ax, int& objekt_ay);
	void ZtrataZivotu(Profily& data);
	bool Casomira();
	void SpocitaniBloku();

	//-----------------------  Ulozeni dat -----------------------//

	void UlozeniDat(Profily& data);

	//-----------------------  Vybuch -----------------------//

	void BlokyJednotlive(int objekt, double objekt_x_d, double objekt_y_d, int objekt_x, int objekt_y, int& objekt_ax, int& objekt_ay);
	bool BlokyVybuch(int objekt, int objekt_x, int objekt_y, int objekt_ax, int objekt_ay, int vzdalenost);
};
