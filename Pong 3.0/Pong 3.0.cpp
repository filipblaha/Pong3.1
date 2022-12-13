#include "Menu_profil.h"
#include "Menu_hlavni.h"


bool HlavniMenu(Menu_profil data)
{
	MenuHlavni menu;
	return 0;
}
bool ProfilMenu()
{
	Menu_profil menu;
	Profily save;
	while (ProfilMenu)
	{
		switch (menu.VstupMenu(menu.profil_e))
		{
		case menu.enter:
		{
			{
				menu.Rozhodovac(menu.enter);
				while (HlavniMenu(menu))
				{
					save.ulozeni_profilu(menu.profil_e);
				}
			}
			break;
		}
		case menu.del:
		{
			{
				menu.OtazkaVykresleni();
				if (menu.VstupMenu(menu.profil_e) == menu.enter)
				{
					menu.Rozhodovac(menu.del);
				}
				menu.OtazkaSmazani();
			}
			break;
		}
		case menu.exit:
		{
			return 0;
		}
		case menu.posun:
		{
			menu.OznaceniVykresleni();
		}
		default:
		{
			menu.OznaceniVykresleni();
		}
		break;
		}
	}
}

int main()
{
	while (ProfilMenu());
}