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
		_setmode(_fileno(stdout), _O_U16TEXT); //SSSSSSSSSSSSSSSSSSSSSSS//

		pocet_bloku = 0; //SSSSSSSSSSSSSSSSSSSSSSS//
		pocet_zivotu = 2;
		cas = 0;

		VykresleniPole();
		VykresleniPlosina();
		VykresleniMic();
		VykresleniHUD();
	}

protected:
	Commands set;
	Profily data;
	Plosina plosina;
	HraciPole pole;
	Mic mic;

	int pocet_bloku;
	int pocet_zivotu;
	int cas;

	const wchar_t* bomba_skin = L"\x263c";
	const wchar_t* bomba_skin_start = L"\x25cc";
	const wchar_t* slow_skin = L"\x25ca";
	const wchar_t* zivoty_skin = L"\x2665";

	//-----------------------  Vykresleni -----------------------//

	void VykresleniPole();
	void VykresleniPlosina();
	void VykresleniMic();
	void VykresleniHUD();
};
