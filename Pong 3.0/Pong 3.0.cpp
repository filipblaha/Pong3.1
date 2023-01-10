#include "Intro.h"
#include "Menuprofil.h"
#include "MenuHlavni.h"
#include "MenuHerniMody.h"
#include "MenuNastaveni.h"
#include "MenuOvladani.h"
#include "MenuSkiny.h"
#include "MenuKonecKola.h"
#include "SkinyManipulace.h"

enum menu_strana
{
	profil_e = 3,
	hlavni_e,
	herni_mody_e,
	vzhled_plosiny_e,
	nastaveni_e,
	ovladani_e,
	konec_kola_e,
};
enum herni_mody
{
	klasik_e = 10,
	bloky_padaji_e,
	rogue_like_e,
};
enum vstup
{
	ex = 13,
	enter,
	del,
	zmena_nazvu,
};

bool KonecKola(Profily& data, bool vyhra)
{
	MenuKonecKola konec(data);

	konec.VykresleniKonecKola(data);
	konec.Logika(data, vyhra);
	konec.VykresleniLevelBar();
	if (vyhra)
		konec.TextVykresleniVyhra(data);
	else
		konec.TextVykresleniProhra(data);

 	if (konec.VstupKonecKola())
		return 1;
	else
		return 0;
}

bool Klasik(Profily& data)
{
	HerniMody hra(data, 2);

	while (!hra.VstupHra(data, 1));
	hra.Smazani();
	while (Klasik)
	{
		switch (hra.Logika(data))
		{
		case 0:
		{
			if (KonecKola(data, 0))
				return 1;
			else
				return 0;
		}
		case 1:
		{
			if (KonecKola(data, 1))
				return 1;
			else
				return 0;
		}
		default:
			hra.Vykresleni();
			Sleep(50);
			hra.VstupHra(data);
			hra.Smazani();
		}
	}
}

bool HerniModyMenu(Profily &data)
{
	MenuHerniMody menu(data);

	while (HerniModyMenu)
	{
		switch (menu.VstupMenu())
		{
		case enter:
		{
			switch (menu.Rozhodovac(data))
			{
			case klasik_e:
			{
				while (Klasik(data));
				return 0;
			}
			/*case bloky_padaji_e:
			{
				BlokyPadaji(data);
				break;
			}
			case rogue_like_e:
			{
				RogueLike(data);
				break;
			}*/
			}
			break;
		}
		case ex:
		{
			return 0;
		}
		}
	}
	return 0;
}
bool SkinyMenu(Profily &data)
{
	MenuSkiny menu(data);

	while (SkinyMenu)
	{
		if (!menu.VstupMenu(data))
			return 0;
		menu.Rozhodovac(data);
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
		case enter:
		{
			(menu.Rozhodovac(data));
			break;
		}
		case ex:
		{
			return 0;
		}
		}
	}
	return 0;
}
bool NastaveniMenu(Profily& data)
{
	MenuNastaveni menu(data);

	while (NastaveniMenu)
	{
		switch (menu.VstupMenu())
		{
		case enter:
		{
			if (menu.Rozhodovac(data) == ovladani_e)
			{
				OvladaniMenu(data);
				menu.MenuSTARTVykresleni();
				menu.NastaveniVykresleni(data, 0);
			}
			break;
		}
		case ex:
		{
			return 0;
		}
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
		case enter:
		{
			switch (menu.Rozhodovac(data))
			{
			case herni_mody_e:
			{
				HerniModyMenu(data);
				break;
			}
			case vzhled_plosiny_e:
			{
				SkinyMenu(data);
				break;
			}
			case nastaveni_e:
			{
				NastaveniMenu(data);
				break;
			}
			case profil_e:
			{
				data.UlozeniProfilu(data.jsem_v_profilu);
				return 1;
			}
			}
			menu.MenuSTARTVykresleni();
			menu.HlavniVykresleni(data);
			break;
		}
		case ex:
		{
			data.UlozeniProfilu(data.jsem_v_profilu);
			return 0;
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
		case enter:
		{
			menu.Rozhodovac(data, enter);
			if (HlavniMenu(data))
				return 1;
			else
				return 0;
		}
		case del:
		{
			menu.OtazkaVykresleni();
			if (menu.VstupMenu(data) == enter)
			{
				menu.Rozhodovac(data, del);
			}
			menu.OtazkaSmazani();
			break;
		}
		case ex:
		{
			data.UlozeniProfilu(data.jsem_v_profilu);
			return 0;
		}
		default:
			Sleep(50);
			menu.OznaceniVykresleni(menu.Blikani());
		}
	}
	return 0;
}
int main()
{
	Intro intro;
	Profily data;

	while (ProfilMenu());

	/*Profily data;
	Commands set;
	set.SetFont(0, 20);
	set.SetWindow(40, 20 - 2);
	SkinyMenu(data);*/
}