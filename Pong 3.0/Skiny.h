#pragma once
#include "Profily.h"

class Skiny
{
public:
	Profily data;
	Commands set;
	XMLDocument xmlDoc;

	//-----------------------  Plosina  -----------------------//

	vector<wstring> NacteniSkinyPlosina();
	void PridaniSkinPlosina(wstring skin);
	void ZapsaniSkinyPlosina(vector<wstring> vektor);

	//-----------------------  Mic  -----------------------//

	vector<wchar_t> NacteniSkinyMic();
	void PridaniSkinMic(wchar_t skin);
	void ZapsaniSkinyMic(vector<wchar_t> vektor);
};
