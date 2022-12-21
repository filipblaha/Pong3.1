#pragma once
#include "HerniMody.h"
class HerniModyKlasik : public HerniMody
{
public:
	HerniModyKlasik(Profily& data,int pocet_zivotu_v) : HerniMody(data)
	{
		pocet_zivotu = pocet_zivotu_v;
	}


};

