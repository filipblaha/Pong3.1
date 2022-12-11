#include "Menu_profil.h"
#include "Menu_hlavni.h"


bool menu_hlavni(Menu_profil data)
{
	Menu_hlavni menu;
	std::wcout << data.ulozena_data.at(0);/////
	return 0;
}

bool menu_profil()
{
	Menu_profil menu;
	Profily save;
	while (menu_profil)
	{
		switch (menu.vstup_menu(menu.profil_e))
		{
		case menu.enter:
		{
			{
				if (menu.rozhodovac(menu.profil_e, menu.enter) == 1)
				{
					while (menu_hlavni(menu))
					{
						save.ulozeni_profilu(menu.profil_e);
					}
				}
			}
			break;
		}
		/*case menu.del:
		{
			{
				menu.vykresleni_otazka();

				if (menu.vstup_menu(menu.profil_e) == menu.enter)
				{
					menu.rozhodovac(menu.profil_e, menu.del);

					if (menu.pouzit == 0)
					{
						menu.vykresleni_nazev_profilu();
						menu.nacteni_vyberu_profilu();
						menu.pojmenovani_profilu();
						menu.ulozeni_vyberu_profilu();
					}
				}
				menu.smazani_otazka();
			}
			break;
		}*/
		case menu.exit:
		{
			return 0;
		}
		case menu.posun:
		{
			menu.vykresleni_oznaceni();
		}
		default:
		{
			//profil.vykresleni_profil();
			menu.vykresleni_oznaceni();
		}
		break;
		}
	}
}
int main()
{
	while (menu_profil());
}