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
	//while (menu_profil);
	std::vector<int> testint1 = { 1, 5, 3, 66, 5 };
	std::vector<int> testint2 = { 8, 4, 6, 11, 4 , 18 };
	std::vector<int> testint3 = { 8, 2, 6, 11, 5 , 11 };
	std::vector<std::vector<int>> testint = {testint1, testint2, testint3};

	std::string a;
	std::cin >> a;

	std::string b;
	b.push_back('p');
	b.push_back('e');
	b.push_back('t');
	b.push_back('a');

	std::string c;
	c.push_back('k');
	c.push_back('u');
	c.push_back('k');

	std::vector<std::string> testchar;
	testchar.push_back(a);
	testchar.push_back(b);
	testchar.push_back(c);
	Profily save;
	save.ulozeni_profilu(0, testchar);

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