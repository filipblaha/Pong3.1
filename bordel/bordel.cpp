#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h> // graficke knihovny
#include "xml.h"

using namespace tinyxml2;
int vstup()
{
    switch (_getch())
    {
    case 'h':
            return 0;
    case 'g':
        return 1;
    case 'j':
        return 2;
    default:
        break;
    }
}
int main()
{
	/////////  Profil  //////
	/*std::wstring vyber_profiluCZ = L"Vyber si svuj profil";
	std::wstring profil1CZ = L"Profil 1";
	std::wstring profil2CZ = L"Profil 2";
	std::wstring profil3CZ = L"Profil 3";
	std::wstring smazani_pokrokCZ = L"Smazat pokrok";
	std::wstring smazani_pokrok_otazka1CZ = L"Opravdu chcete smazat pokrok?";
	std::wstring smazani_pokrok_otazka2CZ = L"[ENTER]";
	std::wstring profil_nazevCZ = L"Zadej nazev profilu";

	/////////  Hlavni menu  //////
	std::wstring herni_modyCZ = L"Herni mody";
	std::wstring vzhled_plosinyCZ = L"Vzhled plosiny";
	std::wstring nastaveniCZ = L"Nastaveni";
	std::wstring verzeCZ = L"verze ";

	/////////  Herni mody  //////
	std::wstring HERNI_MODYCZ = L"HERNI MODY";
	std::wstring klasikCZ = L"Klasik";
	std::wstring rogue_likeCZ = L"Rogue like - zatim nefunkcni";
	std::wstring stejne_tvaryCZ = L"Stejne tvary - zatim nefunkcni";
	std::wstring bloky_padajiCZ = L"Bloky padaji";

	/////////  Vzhled plosiny  //////
	std::wstring VZHLED_PLOSINYCZ = L"VZHLED PLOSINY";
	std::wstring neodemcenoCZ = L"Odemkne se na urovni  ";

	/////////  Nastaveni  //////
	std::wstring NASTAVENICZ = L"NASTAVENI";
	std::wstring ovladaniCZ = L"Ovladani";
	std::wstring jazykCZ = L"Jazyk";
	std::wstring ceskyCZ = L"Cesky";
	std::wstring anglickyCZ = L"Anglicky";

	/////////  Ovladani  //////
	std::wstring OVLADANICZ = L"OVLADANI";
	std::wstring ovladani_menuCZ = L"Ovladani v menu";
	std::wstring ovladani_hraCZ = L"Ovladani ve hre";
	std::wstring ovladani_enterCZ = L"Enter";
	std::wstring ovladani_mezernikCZ = L"Mezernik";
	std::wstring ovladani_schopnostCZ = L"Pouzit schopnost";
	std::wstring ovladani_pohyb_vlevoCZ = L"Pohyb - vlevo";
	std::wstring ovladani_pohyb_vpravoCZ = L"Pohyb - vpravo";
	std::wstring ovladani_pauzaCZ = L"Pauza";

	/////////  Konec kola  //////
	std::wstring odchodP1CZ = L"Zkus to znovu.";
	std::wstring odchodV1CZ = L"VYHRAL JSI!";
	std::wstring odchod2CZ = L"Restart[MEZERNIK]";
	std::wstring odchod3CZ = L"Menu[Q]";
	std::wstring odchod4CZ = L"NEJLEPSI CAS: ";
	std::wstring odchodV5CZ = L"Dosazeny cas: ";
	std::wstring odchodP5CZ = L"Bloku zbylo: ";
	std::wstring odchod6CZ = L"Uroven ";
	std::wstring odchod7CZ = L"Bloku zniceno: ";
	std::wstring odchod8CZ = L"NEJVICE ZNICENYCH BLOKU: ";*/
	
	///////  Profile  //////
	//std::wstring vyber_profiluEN = L"Choose your profile";
	//std::wstring profil1EN = L"Profile 1";
	//std::wstring profil2EN = L"Profile 2";
	//std::wstring profil3EN = L"Profile 3";
	//std::wstring smazani_pokrokEN = L"Delete progress";
	//std::wstring smazani_pokrok_otazka1EN = L"Do you want to delete progress?";
	//std::wstring smazani_pokrok_otazka2EN = L"[ENTER]";
	//std::wstring profil_nazevEN = L"Enter a profile name";

	///////////  Main menu  //////
	//std::wstring herni_modyEN = L"Game modes";
	//std::wstring vzhled_plosinyEN = L"Skins";
	//std::wstring nastaveniEN = L"Settings";
	//std::wstring verzeEN = L"version ";

	///////////  Game modes  //////
	//std::wstring HERNI_MODYEN = L"GAME MODES";
	//std::wstring klasikEN = L"Classic";
	//std::wstring rogue_likeEN = L"Rogue like - zatim nefunkcni";
	//std::wstring stejne_tvaryEN = L"Hit the same color - zatim nefunkcni";
	//std::wstring bloky_padajiEN = L"Falling blocks";

	///////////  Skins  //////
	//std::wstring VZHLED_PLOSINYEN = L"SKINS";
	//std::wstring neodemcenoEN = L"Unlocks after level ";

	///////////  Settings  //////
	//std::wstring NASTAVENIEN = L"SETTINGS";
	//std::wstring jazykEN = L"Language";
	//std::wstring ceskyEN = L"Czech";
	//std::wstring anglickyEN = L"English";
	//std::wstring ovladaniEN = L"Controls";

	///////////  Controls  //////
	//std::wstring OVLADANIEN = L"CONTROLS";
	//std::wstring ovladani_menuEN = L"Menu controls";
	//std::wstring ovladani_hraEN = L"In-game controls";
	//std::wstring ovladani_enterEN = L"Enter";
	//std::wstring ovladani_mezernikEN = L"Spacebar";
	//std::wstring ovladani_schopnostEN = L"Use ability";
	//std::wstring ovladani_pohyb_vlevoEN = L"Movement - left";
	//std::wstring ovladani_pohyb_vpravoEN = L"Movement - right";
	//std::wstring ovladani_pauzaEN = L"Pause";

	///////////  End of a round  //////
	//std::wstring odchodP1EN = L"Try again.";
	//std::wstring odchodV1EN = L"YOU'VE WON!";
	//std::wstring odchod2EN = L"Restart [SPACEBAR]";
	//std::wstring odchod3EN = L"Menu [Q]";
	//std::wstring odchod4EN = L"BEST TIME: ";
	//std::wstring odchodV5EN = L"Your time: ";
	//std::wstring odchodP5EN = L"Blocks left: ";
	//std::wstring odchod6EN = L"Level ";
	//std::wstring odchod7EN = L"Blocks destroyed: ";
	//std::wstring odchod8EN = L"HIGHSCORE: ";

	//std::vector<std::wstring> v;
	//v.push_back(vyber_profiluEN);
	//v.push_back(profil1EN);
	//v.push_back(profil2EN);
	//v.push_back(profil3EN);
	//v.push_back(smazani_pokrokEN);
	//v.push_back(smazani_pokrok_otazka1EN);
	//v.push_back(smazani_pokrok_otazka2EN);
	//v.push_back(profil_nazevEN);

	/////////  Hlavni menu  //////
	//v.push_back(herni_modyEN);
	//v.push_back(vzhled_plosinyEN);
	//v.push_back(nastaveniEN);
	//v.push_back(verzeEN);

	/////////  Herni mody  //////
	//v.push_back(HERNI_MODYEN);
	//v.push_back(klasikEN);
	//v.push_back(rogue_likeEN);
	//v.push_back(stejne_tvaryEN);
	//v.push_back(bloky_padajiEN);

	/////////  Vzhled plosiny  //////
	//v.push_back(VZHLED_PLOSINYEN);
	//v.push_back(neodemcenoEN);

	/////////  Nastaveni  //////
	//v.push_back(NASTAVENIEN);
	//v.push_back(ovladaniEN);
	//v.push_back(jazykEN);
	//v.push_back(ceskyEN);
	//v.push_back(anglickyEN);

	/////////  Ovladani  //////
	//v.push_back(OVLADANIEN);
	//v.push_back(ovladani_menuEN);
	//v.push_back(ovladani_hraEN);
	//v.push_back(ovladani_enterEN);
	//v.push_back(ovladani_mezernikEN); 
	//v.push_back(ovladani_schopnostEN);
	//v.push_back(ovladani_pohyb_vlevoEN); 
	//v.push_back(ovladani_pohyb_vpravoEN); 
	//v.push_back(ovladani_pauzaEN); 

	/////////  Konec kola  //////
	//v.push_back(odchodP1EN); 
	//v.push_back(odchodV1EN); 
	//v.push_back(odchod2EN);
	//v.push_back(odchod3EN); 
	//v.push_back(odchod4EN);
	//v.push_back(odchodV5EN); 
	//v.push_back(odchodP5EN); 
	//v.push_back(odchod6EN);
	//v.push_back(odchod7EN);
	//v.push_back(odchod8EN);
 //   for (size_t i = 0; i < 43; i++)
 //   {
	//	std::wstring k = L"profil";
	//	if (i > 7)
	//		k = L"hlavni";
	//	if (i > 11)
	//		k = L"herni_mody";
	//	if (i > 16)
	//		k = L"vzhled_plosiny";
	//	if (i > 18)
	//		k = L"nastaveni";
	//	if (i > 23)
	//		k = L"ovladani";
	//	if (i > 34)
	//		k = L"konec";
 //       std::wcout <<"<string>" << v.at(i) << "</string>\n";
 //   }

TiXMLDocument xmlDoc;
XMLNode* root = xmlDoc.NewElement(L"root");
	xmlDoc.InsertFirstChild(root);

	XMLElement* base = xmlDoc.NewElement(L"Zakladni");
	root->InsertEndChild(base);

	XMLElement* pocet_profilu = xmlDoc.NewElement(L"Pocet_profilu");
	pocet_profilu->SetAttribute(L"dateFormat", L"26/04/2014");
	base->InsertEndChild(pocet_profilu);

	xmlDoc.SaveFile(L"XMLF.xml");


	


int profil_stringu = 0;
_setmode(_fileno(stdout), _O_U16TEXT);

std::vector<int> vektor_poctu_stringu;

xmlDoc.LoadFile(L"XMLF.xml");

XMLNode* root2 = xmlDoc.FirstChild();
XMLElement* base2 = root2->FirstChildElement(L"Zakladni");

XMLElement* profil2 = base2->FirstChildElement(L"Pocet_profilu");
profil2->QueryIntText(&profil_stringu);

XMLElement* jazyk2 = root2->FirstChildElement(L"CZ");


}