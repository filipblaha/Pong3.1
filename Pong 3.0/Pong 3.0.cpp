#include "Menuprofil.h"
#include "MenuHlavni.h"
#include "MenuHerniMody.h"
#include "MenuNastaveni.h"
#include "MenuOvladani.h"
#include "MenuVzhledPlosiny.h"
#include "HerniMody.h"



bool Klasik(Profily &data)
{
	//while (true)
	{
		HerniMody Klasik(data);
	}
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
				Klasik(data);
				break;
			}
			/*case menu.bloky_padaji_e:
			{
				BlokyPadaji(data);
				break;
			}
			case menu.rogue_like_e:
			{
				RogueLike(data);
				break;
			}*/
			}
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
				OvladaniMenu(data);
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
				HerniModyMenu(data);
				break;
			}
			case menu.vzhled_plosiny_e:
			{
				VzhledPlosinyMenu(data);
				break;
			}
			case menu.nastaveni_e:
			{
				NastaveniMenu(data);
				break;
			}
			case menu.profil_e:
			{
				data.UlozeniProfilu(data.jsem_v_profilu);
				return 1;
				break;
			}
			}
			menu.MenuSTARTVykresleni();
			menu.HlavniVykresleni(data);
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
			if (!HlavniMenu(data))
				return 0;
			else
				return 1;
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
	Profily data;
	Klasik(data);
	//while (ProfilMenu());
}