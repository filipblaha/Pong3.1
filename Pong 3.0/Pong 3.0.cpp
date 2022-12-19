#include "Menuprofil.h"
#include "MenuHlavni.h"
#include "MenuHerniMody.h"
#include "MenuNastaveni.h"
#include "MenuOvladani.h"
#include "MenuVzhledPlosiny.h"



bool Klasik(Profily &data)
{
	return 0;
}

bool HerniModyMenu(Profily &data)
{
	MenuHerniMody menu(data);

	while (HerniModyMenu)
	{
		switch (menu.VstupMenu())
		{
		case menu.enter:
		{
			switch (menu.Rozhodovac(data))
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
	return 0;
}
bool VzhledPlosinyMenu(Profily &data)
{
	MenuVzhledPlosiny menu(data);

	while (VzhledPlosinyMenu)
	{
		switch (menu.VstupMenu(data))
		{
		case menu.enter:
		{
			menu.Rozhodovac(data);
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
	return 0;
}
bool OvladaniMenu(Profily& data)
{
	MenuOvladani menu(data);

	while (OvladaniMenu)
	{
		switch (menu.VstupMenu())
		{
		case menu.enter:
		{
			(menu.Rozhodovac(data));
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
	return 1;
}
bool NastaveniMenu(Profily& data)
{
	MenuNastaveni menu(data);

	while (NastaveniMenu)
	{
		switch (menu.VstupMenu())
		{
		case menu.enter:
		{
			switch (menu.Rozhodovac(data))
			{
			case menu.ovladani_e:
			{
				while (OvladaniMenu(data));
				menu.MenuSTARTVykresleni();
				menu.NastaveniVykresleni(data);
				break;
			}
			case menu.balic_e:
			{
				menu.SpodniZavoraSet();
				menu.NastaveniVykresleni(data);
				break;
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
	return 0;
}
bool HlavniMenu(Profily &data)
{
	MenuHlavni menu(data);

	while (HlavniMenu)
	{
		switch (menu.VstupMenu())
		{
		case menu.enter:
		{
			switch (menu.Rozhodovac(data))
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
			menu.HlavniVykresleni(data);
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
			data.UlozeniProfilu(data.jsem_v_profilu);
			return 0;
		}
		default:
		{
			menu.OznaceniVykresleni();
		}
		break;
		}
	}
	return 0;
}

bool ProfilMenu()
{
	Profily data;
	MenuProfil menu(data);

	while (ProfilMenu)
	{
		switch (menu.VstupMenu(data))
		{
		case menu.enter:
		{
			menu.Rozhodovac(data, menu.enter);
			while (HlavniMenu(data));
			return 0;
		}
		case menu.del:
		{
			menu.OtazkaVykresleni();
			if (menu.VstupMenu(data) == menu.enter)
			{
				menu.Rozhodovac(data, menu.del);
			}
			menu.OtazkaSmazani();
			break;
		}
		case menu.zmena_jazyka:
		{
			menu.Rozhodovac(data, menu.zmena_jazyka);
		}
		case menu.posun:
		{
			menu.OznaceniVykresleni();

			break;
		}
		case menu.exit:
		{
			data.UlozeniProfilu(data.jsem_v_profilu);
			return 0;
		}
		default:
		{
			menu.OznaceniVykresleni();
		}
		break;
		}
	}
	return 0;
}

int main()
{
	while (ProfilMenu());
}