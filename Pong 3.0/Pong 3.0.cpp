#include "Menu.h"
#include "Menu_profil.h"
#include "Profily.h"
#include "Preklad.h"

#include <iostream>
#include <vector>

//bool menu_profil()
//{
//	Menu_profil profil;
//	switch (profil.vstup_menu(profil.profil_e))
//	{
//	case profil.enter:
//	{
//		{
//			if (profil.rozhodovac(profil.profil_e, profil.enter) == 1)
//			{
//				while (menu_hlavni())
//				{
//					profil.ukladani_profilu();
//				}
//			}
//		}
//		break;
//	}
//	/*case profil.del:
//	{
//		{
//			profil.vykresleni_otazka();
//
//			if (profil.vstup_menu(profil.profil_e) == profil.enter)
//			{
//				profil.rozhodovac(profil.profil_e, profil.del);
//
//				if (profil.pouzit == 0)
//				{
//					profil.vykresleni_nazev_profilu();
//					profil.nacteni_vyberu_profilu();
//					profil.pojmenovani_profilu();
//					profil.ulozeni_vyberu_profilu();
//				}
//			}
//			profil.smazani_otazka();
//		}
//		break;
//	}*/
//	case profil.exit:
//	{
//		return 0;
//	}
//	default:
//	{
//		profil.vykresleni_oznaceni();
//	}
//	break;
//	}
//}
int main()
{
	Profily save;
	save.zmena_jmeno_profilu(1);

	/*std::vector<std::vector<int>> prosim = save.nacteni_dat_profilu();
	for (size_t j = 0; j < prosim.size(); j++)
	{
		for (size_t i = 0; i < prosim.at(j).size(); i++)
		{
			std::cout << prosim.at(j).at(i);
		}
		std::cout << '\n';
	}
	std::vector<std::string>prosim2 = save.nacteni_jmen_profilu();
	for (size_t i = 0; i < prosim2.size(); i++)
	{
		std::cout << prosim2.at(i) << '\n';
	}*/
}