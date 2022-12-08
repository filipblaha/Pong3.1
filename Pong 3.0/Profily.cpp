#include "Profily.h"


int Profily::ulozeni_profilu(int profil, std::vector<std::string> nazev_profil)
{
	XMLDocument xmlDoc;
	std::vector<std::vector<int>> data_profil;
	vlozeni_dat_do_vektoru(profil, data_profil);

	XMLNode* root = xmlDoc.NewElement("root");
	xmlDoc.InsertFirstChild(root);

	XMLElement* base = xmlDoc.NewElement("Zakladni");
	root->InsertEndChild(base);

	XMLElement* pocet_profilu = xmlDoc.NewElement("Pocet_profilu");
	pocet_profilu->SetText(data_profil.size());
	base->InsertEndChild(pocet_profilu);

	
	XMLElement* profily_nazev;
	for (int j = 0; j < nazev_profil.size(); j++)
	{
		profily_nazev = xmlDoc.NewElement("Nazev_profilu");
		for (int i = 0; i < nazev_profil.at(j).size(); i++)
		{
			XMLElement* pismeno = xmlDoc.NewElement("Pismeno");
			pismeno->SetText(nazev_profil.at(j).at(i));
			profily_nazev->InsertEndChild(pismeno);
		}
		base->InsertEndChild(profily_nazev);
	}

	XMLElement* profily_data;
	for (int j = 0; j < data_profil.size(); j++)
	{
		profily_data = xmlDoc.NewElement("Profil");
		for (int i = 0; i < data_profil.at(j).size(); i++)
		{
			XMLElement* hodnoty = xmlDoc.NewElement("Hodnota");
			hodnoty->SetText(data_profil.at(j).at(i));

			profily_data->InsertEndChild(hodnoty);
		}
		root->InsertEndChild(profily_data);
	}
	XMLError eResult = xmlDoc.SaveFile("profily.xml");
	XMLCheckResult(eResult);
}
void Profily::vlozeni_dat_do_vektoru(int profil, std::vector<std::vector<int>>& data_profil)
{
	data_profil = nacteni_dat_profilu();

	pouzit = data_profil.at(profil).at(0);
	jazyk = data_profil.at(profil).at(1);
	plosina_skin = data_profil.at(profil).at(2);
	highscore_cas = data_profil.at(profil).at(3);
	highscore_znicenych_bloku = data_profil.at(profil).at(4);
	level = data_profil.at(profil).at(5);
	exp = data_profil.at(profil).at(6);
}
std::vector<std::vector<int>> Profily::nacteni_dat_profilu()
{
	XMLDocument xmlDoc;
	int data = 0;
	int pocet_profilu_s = 0;
	std::vector<int> vektor_dat;
	std::vector<std::vector<int>> v_v_dat;


	xmlDoc.LoadFile("profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
	XMLElement* pocet_profilu = base->FirstChildElement("Pocet_profilu");
	pocet_profilu->QueryIntText(&pocet_profilu_s);

	XMLElement* profily_data = root->FirstChildElement("Profil");
	for (int i = 0; i < pocet_profilu_s; i++)
	{
		XMLElement* hodnoty = profily_data->FirstChildElement("Hodnota");
		while (hodnoty != nullptr)
		{
			hodnoty->QueryIntText(&data);
			vektor_dat.push_back(data);
			hodnoty = hodnoty->NextSiblingElement("Hodnota");
		}
		v_v_dat.push_back(vektor_dat);
		vektor_dat.clear();
		profily_data = profily_data->NextSiblingElement("Profil");
	}
	return v_v_dat;
}
std::vector<std::string> Profily::nacteni_jmen_profilu()
{
	XMLDocument xmlDoc;
	int data = 0;
	std::string vektor_pismen;
	std::vector<std::string> v_v_pismen;

	int pocet_profilu_s = 0;

	xmlDoc.LoadFile("profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
	XMLElement* pocet_profilu = base->FirstChildElement("Pocet_profilu");
	pocet_profilu->QueryIntText(&pocet_profilu_s);

	XMLElement* profily_jmena = base->FirstChildElement("Nazev_profilu");
	for (int i = 0; i < pocet_profilu_s; i++)
	{
		XMLElement* hodnoty = profily_jmena->FirstChildElement("Pismeno");
		while (hodnoty != nullptr)
		{
			hodnoty->QueryIntText(&data);
			vektor_pismen.push_back(data);
			hodnoty = hodnoty->NextSiblingElement("Pismeno");
		}
		v_v_pismen.push_back(vektor_pismen);
		vektor_pismen.clear();
		profily_jmena = profily_jmena->NextSiblingElement("Nazev_profilu");
	}
	return v_v_pismen;
}

void Profily::zmena_jmeno_profilu(int profil)
{
	jmena_profilu = nacteni_jmen_profilu();
	Commands set;
	set.setCursorPosition(10, 10);
	std::string jmeno_profilu;
	std::cin >> jmeno_profilu;


	//jmena_profilu.at(profil);

	ulozeni_profilu(profil, jmena_profilu);
}