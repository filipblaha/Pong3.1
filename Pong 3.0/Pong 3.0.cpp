#include "Menu_profil.h"


bool menu_hlavni()
{
	return 0;
}

bool menu_profil()
{
	Menu_profil profil;
	Profily save;
	while (menu_profil)
	{
		switch (profil.vstup_menu(profil.profil_e))
		{
		case profil.enter:
		{
			{
				if (profil.rozhodovac(profil.profil_e, profil.enter) == 1)
				{
					while (menu_hlavni())
					{
						save.ulozeni_profilu(profil.profil_e);
					}
				}
			}
			break;
		}
		/*case profil.del:
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
		}*/
		case profil.exit:
		{
			return 0;
		}
		default:
		{
			//profil.vykresleni_profil();
			profil.vykresleni_oznaceni();
		}
		break;
		}
	}
}
int main()
{
	while (menu_profil());
}