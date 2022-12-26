#include "Menuprofil.h"
#include "MenuHlavni.h"
#include "MenuHerniMody.h"
#include "MenuNastaveni.h"
#include "MenuOvladani.h"
#include "MenuVzhledPlosiny.h"
#include "MenuKonecKola.h"
#include "Skiny.h"

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
	konec.TextVykresleniProhra(data);

 	if (konec.VstupKonecKola())
		return 1;
	else
		return 0;
}

bool Klasik(Profily &data)
{
	HerniMody hra(data, 1);

	while (!_kbhit());
	hra.VstupHra(data, 1);

	while (Klasik)
	{
		hra.Smazani();
		switch (hra.Logika(data))
		{
		case 1:
		{
			if (KonecKola(data, 1))
				return 1;
			else
				return 0;
		}
		case 2:
		{
			if (KonecKola(data, 0))
				return 1;
			else
				return 0;
		}
		default:
			hra.Vykresleni();
			Sleep(100);
			hra.VstupHra(data);
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
bool VzhledPlosinyMenu(Profily &data)
{
	MenuVzhledPlosiny menu(data);

	while (VzhledPlosinyMenu)
	{
		switch (menu.VstupMenu(data))
		{
		case enter:
		{
			if (menu.Rozhodovac(data))
				break;
			else
				return 0;
		}
		case ex:
		{
			return 0;
		}
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
				VzhledPlosinyMenu(data);
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
		}
	}
	return 0;
}

int main()
{
	Profily data;
	//Klasik(data);
	//while (ProfilMenu());
	Skiny s;
	s.PridaniSkinMic(L'■');
	vector<wchar_t> Skiny = s.NacteniSkinyMic();
	for (size_t i = 0; i < Skiny.size(); i++)
	{
		wcout << Skiny.at(i) << '\n';
	}
}