#pragma once
#include "Profily.h"
#include "Plosina.h"
#include "Mic.h"

class HerniMody
{
public:
	Commands set;
	Profily data;
	Plosina plosina;
	HraciPole pole;
	Mic mic;

	HerniMody()
	{}
	HerniMody(Profily& data)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);

		VykresleniPole();
		VykresleniPlosina();
		VykresleniMic();
	}

	const wchar_t* bomba_skin = L"\x263c";
	const wchar_t* bomba_skin_start = L"\x25cc";
	const wchar_t* slow_skin = L"\x25ca";

	//-----------------------  Vykresleni -----------------------//

	void VykresleniPole();
	void VykresleniPlosina();
	void VykresleniMic();

private:
};
