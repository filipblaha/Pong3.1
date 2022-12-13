#include "Profily.h"

//-----------------------  Ukladani profilu  -----------------------//

void Profily::ulozeni_profilu(int profil, std::vector<int> d, bool zmena_jmena)
{
	std::list<int> uroven_profil = nacteni_urovni_profilu();
	std::list<std::vector<int>> data_profil;
	std::list<std::string> nazev_profil;

	std::list<int>::iterator itr = uroven_profil.begin();
	advance(itr, profil);
	*itr = level;

	for (int i = 0; i < pocet_profilu_s; i++)
	{
		if (i == profil)
			data_profil.push_back(vlozeni_dat_do_vektoru(profil, d));
		else
			data_profil.push_back(nacteni_dat_profilu(i));
	}

	if (!zmena_jmena)
		nazev_profil = nacteni_jmen_profilu();

	zapsani_profilu(uroven_profil, data_profil, nazev_profil);
}
std::vector<int> Profily::vlozeni_dat_do_vektoru(int profil, std::vector<int> d)
{
	std::vector<int> data_profil = nacteni_dat_profilu(profil);

	if (d.at(0) == 0)
		data_profil.at(0) = d.at(1);
	if (d.at(0) == 1)
		data_profil.at(1) = d.at(1);
	if (d.at(0) == 2)
		data_profil.at(2) = d.at(1);
	if (d.at(0) == 3)
		data_profil.at(3) = d.at(1);
	if (d.at(0) == 4)
		data_profil.at(4) = d.at(1);
	if (d.at(0) == 5)
		data_profil.at(5) = d.at(1);

	jazyk = data_profil.at(0);
	level = data_profil.at(1);

	return data_profil;
}

void Profily::vytvoreni_noveho_profilu(std::string nazev_noveho_profilu)
{
	std::list<int> uroven_profil;
	std::vector<int> data_noveho_profilu;
	std::list<std::vector<int>> data_profil;

	uroven_profil = nacteni_urovni_profilu();
	uroven_profil.push_front(0);

	for (int i = 0; i < 6; i++)
	{
		data_noveho_profilu.push_back(0);
	}
	for (int i = 0; i < pocet_profilu_s; i++)
	{
			data_profil.push_back(nacteni_dat_profilu(i));
	}
	std::list<std::string> nazev_profil = nacteni_jmen_profilu();

	itri = data_profil.begin();
	itri++;
	data_profil.insert(itri, data_noveho_profilu);

	itr = nazev_profil.begin();
	itr++;
	nazev_profil.insert(itr, nazev_noveho_profilu);

	pocet_profilu_s++;

	zapsani_profilu(uroven_profil, data_profil, nazev_profil);
}
void Profily::odstraneni_profilu(int profil)
{
	std::list<int> uroven_profil = nacteni_urovni_profilu();
	std::list<std::vector<int>> data_profil;
	std::list<std::string> nazev_profil;

	std::list<int>::iterator itrl = uroven_profil.begin();
	advance(itrl, profil);
	uroven_profil.erase(itrl);
	

	for (int i = 0; i < pocet_profilu_s; i++)
	{
		data_profil.push_back(nacteni_dat_profilu(i));
	}
	nazev_profil = nacteni_jmen_profilu();

	itri = data_profil.begin();
	advance(itri, profil);
	data_profil.erase(itri);

	itr = nazev_profil.begin();
	advance(itr, profil);
	nazev_profil.erase(itr);

	pocet_profilu_s--;

	zapsani_profilu(uroven_profil, data_profil, nazev_profil);
}

int Profily::zapsani_profilu(std::list<int> uroven_profil, std::list<std::vector<int>> data, std::list<std::string> nazev)
{
	XMLDocument xmlDoc;
	XMLNode* root = xmlDoc.NewElement("root");
	xmlDoc.InsertFirstChild(root);

	XMLElement* base = xmlDoc.NewElement("Zakladni");
	root->InsertEndChild(base);

	XMLElement* pocet_profilu = xmlDoc.NewElement("Pocet_profilu");
	pocet_profilu->SetText(pocet_profilu_s);
	base->InsertEndChild(pocet_profilu);

	std::list<int>::iterator itrl;
	XMLElement* uroven_profilu = xmlDoc.NewElement("Uroven_profilu");
	base->InsertEndChild(uroven_profilu);
	for (itrl = uroven_profil.begin(); itrl != uroven_profil.end(); itrl++)
	{
		XMLElement* hodnota = xmlDoc.NewElement("Hodnota");
		hodnota->SetText(*itrl);
		uroven_profilu->InsertEndChild(hodnota);
	}

	std::string temp;
	XMLElement* profily_nazev;
	for (itr = nazev.begin(); itr != nazev.end(); itr++)
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

	std::vector<int> tempi;
	XMLElement* profily_data;
	for (itri = data.begin(); itri != data.end(); itri++)
	{
		profily_data = xmlDoc.NewElement("Profil");
		tempi = *itri;
		for (int i = 0; i < tempi.size(); i++)
		{
			XMLElement* hodnoty = xmlDoc.NewElement("Hodnota");
			hodnoty->SetText(tempi.at(i));
			profily_data->InsertEndChild(hodnoty);
		}
		root->InsertEndChild(profily_data);
	}

	XMLError eResult = xmlDoc.SaveFile("profily.xml");
	XMLCheckResult(eResult);
}

//-----------------------  Nacteni profilu  -----------------------//

void  Profily::nacteni_poctu_profilu()
{
	XMLDocument xmlDoc;
	xmlDoc.LoadFile("profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
	XMLElement* pocet_profilu = base->FirstChildElement("Pocet_profilu");
	pocet_profilu->QueryIntText(&pocet_profilu_s);
}
std::list<int> Profily::nacteni_urovni_profilu()
{
	XMLDocument xmlDoc;
	int data = 0;
	std::list<int> list_dat;


	xmlDoc.LoadFile("profily.xml");

	nacteni_poctu_profilu();

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
	XMLElement* profily_urovne = base->FirstChildElement("Uroven_profilu");
	XMLElement* hodnoty = profily_urovne->FirstChildElement("Hodnota");
	for (int i = 0; i < pocet_profilu_s; i++)
	{
		hodnoty->QueryIntText(&data);
		list_dat.push_back(data);
		hodnoty = hodnoty->NextSiblingElement("Hodnota");
	}
	return list_dat;
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

//-----------------------  Zmena jmena ?  -----------------------//

//void Profily::zmena_jmeno_profilu(int profil)
//{
//	nazev_profil = nacteni_jmen_profilu();
//	Commands set;
//	set.setCursorPosition(10, 10);
//	std::string jmeno_profilu;
//	std::cin >> jmeno_profilu;
//
//	itr = nazev_profil.begin();
//	advance(itr, profil);
//
//	nazev_profil.insert(itr, jmeno_profilu);
//	nazev_profil.erase(itr);
//
//	ulozeni_profilu(profil, 1);
//}
