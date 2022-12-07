#include "Menu.h"
#include "Menu_profil.h"
#include "Profily.h"
#include "Preklad.h"

#include <iostream>
#include <vector>

bool menu_profil()
{
	Menu_profil profil;
	switch (profil.vstup_menu(profil.profil_e))
	{
	case profil.enter:
	{
		{
			if (profil.rozhodovac(profil.profil_e, profil.enter) == 1)
			{
				while (menu_hlavni())
				{
					profil.ukladani_profilu();
				}
			}
		}
		break;
	}
	case profil.del:
	{
		{
			profil.vykresleni_otazka();

			if (profil.vstup_menu(profil.profil_e) == profil.enter)
			{
				profil.rozhodovac(profil.profil_e, profil.del);

				if (profil.pouzit == 0)
				{
					profil.vykresleni_nazev_profilu();
					profil.nacteni_vyberu_profilu();
					profil.pojmenovani_profilu();
					profil.ulozeni_vyberu_profilu();
				}
			}
			profil.smazani_otazka();
		}
		break;
	}
	case profil.exit:
	{
		return 0;
	}
	default:
	{
		profil.vykresleni_oznaceni();
	}
	break;
	}
}
int main()
{
	while (menu_profil);
	/*std::vector<int> testint1 = { 1, 5, 3, 66, 5 };
	std::vector<int> testint2 = { 8, 4, 6, 11, 4 , 18 };
	std::vector<int> testint3 = { 8, 2, 6, 11, 5 , 11 };
	std::vector<std::vector<int>> testint = {testint1, testint2, testint3};

	std::vector<char> a;
	a.push_back('f');
	a.push_back('s');
	a.push_back('a');

	std::vector<char> b;
	b.push_back('a');
	b.push_back('g');
	b.push_back('h');
	b.push_back('j');

	std::vector<char> c;
	c.push_back('s');
	c.push_back('l');
	c.push_back('j');

	std::vector< std::vector<char>> testchar;
	testchar.push_back(a);
	testchar.push_back(b);
	testchar.push_back(c);
	Profily save;
	save.ulozeni_profilu(testint, testchar);

	std::vector<std::vector<int>> prosim = save.nacteni_dat_profilu();
	for (size_t j = 0; j < prosim.size(); j++)
	{
		for (size_t i = 0; i < prosim.at(j).size(); i++)
		{
			std::cout << prosim.at(j).at(i);
		}
		std::cout << '\n';
	}
	std::vector<std::vector<char>>prosim2 = save.nacteni_jmen_profilu();
	for (size_t j = 0; j < prosim2.size(); j++)
	{
		for (size_t i = 0; i < prosim2.at(j).size(); i++)
		{
			std::cout << prosim2.at(j).at(i);
		}
		std::cout << '\n';
	}*/
}