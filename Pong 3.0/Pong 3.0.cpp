#include "Menu_profil.h"
#include "Menu_hlavni.h"

bool HerniModyMenu(MenuProfil data)
{
	return 0;
}
bool VzhledPlosinyMenu(MenuProfil data)
{
	return 0;
}
bool NastaveniMenu(MenuProfil data)
{
	return 0;
}
bool OvladaniMenu(MenuProfil data)
{
	return 0;
}

bool HlavniMenu(MenuProfil data)
{
	MenuHlavni menu;
	while (HlavniMenu)
	{
		switch (menu.VstupMenu(menu.hlavni_e))
		{
		case menu.enter:
		{
			{
				switch (menu.Rozhodovac(menu.enter))
				{
				case menu.herni_mody_e:
				{
					while (HerniModyMenu(data));
					break;
				}
				case menu.vzhled_plosiny_e:
				{
					while (VzhledPlosinyMenu(data));
					break;
				}
				case menu.nastaveni_e:
				{
					while (NastaveniMenu(data));
					break;
				}
				}
			}
			break;
		}
		case menu.posun:
		{
			menu.OznaceniVykresleni();
			break;
		}
		case menu.exit:
		{
			return 0;
		}
		default:
		{
			menu.OznaceniVykresleni();
		}
		break;
		}
	}
}
bool ProfilMenu()
{
	MenuProfil menu;
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
		case menu.posun:
		{
			menu.OznaceniVykresleni();
			break;
		}
		case menu.exit:
		{
			return 0;
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
	//while (ProfilMenu());
	MenuProfil menu;
	while (HlavniMenu(menu));
}