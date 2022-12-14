#include "MenuProfil.h"
#include "MenuHlavni.h"
#include "MenuHerniMody.h"
#include "MenuNastaveni.h"

bool Klasik(MenuProfil data)
{
	return 0;
}

bool OvladaniMenu(MenuProfil data)
{
	return 0;
}
bool NastaveniMenu(MenuProfil data)
{
	MenuNastaveni menu;
	while (HerniModyMenu)
	{
		switch (menu.VstupMenu(menu.herni_mody_e))
		{
		case menu.enter:
		{
			{
				switch (menu.Rozhodovac(menu.enter))
				{
				case menu.ovladani_e:
				{
					while (OvladaniMenu(data));
					break;
				}
				case menu.balic_e:
				{
					menu.SpodniZavoraSet();
					menu.TextNastaveniVykresleni(menu.JazykSet());
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
bool VzhledPlosinyMenu(MenuProfil data)
{
	return 0;
}
bool HerniModyMenu(MenuProfil data)
{
	MenuHerniMody menu;
	while (HerniModyMenu)
	{
		switch (menu.VstupMenu(menu.herni_mody_e))
		{
		case menu.enter:
		{
			{
				switch (menu.Rozhodovac(menu.enter))
				{
				case menu.klasik_e:
				{
					while (Klasik(data));
					break;
				}
				/*case menu.bloky_padaji_e:
				{
					while (BlokyPadaji(data));
					break;
				}
				case menu.rogue_like_e:
				{
					while (RogueLike(data));
					break;
				}*/
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

bool HlavniMenu(MenuProfil data)
{
	MenuHlavni menu;
	while (HlavniMenu)
	{
		switch (menu.VstupMenu(menu.hlavni_e))
		{
		case menu.enter:
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
			menu.MenuSTARTVykresleni();
			menu.HlavniVykresleni(menu.JazykSet());
			menu.OznaceniVykresleni();
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
			menu.Rozhodovac(menu.enter);
			while (HlavniMenu(menu))
			{
				save.ulozeni_profilu(menu.profil_e);
			}
			return 0;
		}
		case menu.del:
		{
			menu.OtazkaVykresleni();
			if (menu.VstupMenu(menu.profil_e) == menu.enter)
			{
				menu.Rozhodovac(menu.del);
			}
			menu.OtazkaSmazani();
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
	while (ProfilMenu());
}