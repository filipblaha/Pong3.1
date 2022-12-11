#include "Profily.h"

int Profily::ulozeni_profilu(int profil, bool zmena_jmena)
{
	XMLDocument xmlDoc;
	std::vector<std::vector<int>> data_profil;
	for (int i = 0; i < pocet_profilu_s - 1; i++)
	{
		if (i = profil)
			data_profil.push_back(vlozeni_dat_do_vektoru(profil));
		else
			data_profil.push_back(nacteni_dat_profilu(i));
	}


	if (!zmena_jmena)
		nazev_profil = nacteni_jmen_profilu();

	XMLNode* root = xmlDoc.NewElement("root");
	xmlDoc.InsertFirstChild(root);

	XMLElement* base = xmlDoc.NewElement("Zakladni");
	root->InsertEndChild(base);

	XMLElement* pocet_profilu = xmlDoc.NewElement("Pocet_profilu");
	pocet_profilu->SetText(data_profil.size());
	base->InsertEndChild(pocet_profilu);


	std::string temp;
	XMLElement* profily_nazev;
	for (itr = nazev_profil.begin(); itr != nazev_profil.end(); itr++)
	{
		profily_nazev = xmlDoc.NewElement("Nazev_profilu");
		temp = *itr;
		for (int i = 0; i < temp.size(); i++)
		{
			XMLElement* pismeno = xmlDoc.NewElement("Pismeno");
			pismeno->SetText(temp.at(i));
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

std::vector<int> Profily::nacteni_dat_profilu(int profil)
{
	XMLDocument xmlDoc;
	int data = 0;
	std::vector<int> vektor_dat;
	std::vector<std::vector<int>> v_v_dat;


	xmlDoc.LoadFile("profily.xml");

	nacteni_poctu_profilu();

	XMLNode* root = xmlDoc.FirstChild();
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
	return v_v_dat.at(profil);
}
std::list<std::string> Profily::nacteni_jmen_profilu()
{
	XMLDocument xmlDoc;
	int data = 0;
	std::string vektor_pismen;
	std::list<std::string> v_v_pismen;

	xmlDoc.LoadFile("profily.xml");

	nacteni_poctu_profilu();

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
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
void  Profily::nacteni_poctu_profilu()
{
	XMLDocument xmlDoc;
	xmlDoc.LoadFile("profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
	XMLElement* pocet_profilu = base->FirstChildElement("Pocet_profilu");
	pocet_profilu->QueryIntText(&pocet_profilu_s);
}

std::vector<int> Profily::vlozeni_dat_do_vektoru(int profil)
{
	std::vector<int> data_profil = nacteni_dat_profilu(profil);

	pouzit = data_profil.at(0);
	jazyk = data_profil.at(1);
	plosina_skin = data_profil.at(2);
	highscore_cas = data_profil.at(3);
	highscore_znicenych_bloku = data_profil.at(4);
	level = data_profil.at(5);
	exp = data_profil.at(6);
	return data_profil;
}
void Profily::zmena_jmeno_profilu(int profil)
{
	nazev_profil = nacteni_jmen_profilu();
	Commands set;
	set.setCursorPosition(10, 10);
	std::string jmeno_profilu;
	std::cin >> jmeno_profilu;

	itr = nazev_profil.begin();
	advance(itr, profil);

	nazev_profil.insert(itr, jmeno_profilu);
	nazev_profil.erase(itr);

	ulozeni_profilu(profil, 1);
}
