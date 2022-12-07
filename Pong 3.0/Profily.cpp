#include "Profily.h"

TiXMLDocument xmlDoc;
//int Profily::ulozeni_profilu(std::vector<std::vector<int>> data_profil, std::vector< std::vector<char>> nazev_profil)
//{
//	XMLNode* root = xmlDoc.NewElement(L"root");
//	xmlDoc.InsertFirstChild(root);
//
//	XMLElement* base = xmlDoc.NewElement(L"Zakladni");
//	root->InsertEndChild(base);
//
//	XMLElement* pocet_profilu = xmlDoc.NewElement(L"Pocet_profilu");
//	pocet_profilu->SetText(data_profil.size());
//	base->InsertEndChild(pocet_profilu);
//
//
//	XMLElement* profily_nazev;
//	for (int j = 0; j < nazev_profil.size(); j++)
//	{
//		profily_nazev = xmlDoc.NewElement(L"Nazev_profilu");
//		for (int i = 0; i < nazev_profil.at(j).size(); i++)
//		{
//			XMLElement* pismeno = xmlDoc.NewElement(L"Pismeno");
//			pismeno->SetValue(nazev_profil.at(j).at(i));
//			profily_nazev->InsertEndChild(pismeno);
//		}
//		base->InsertEndChild(profily_nazev);
//	}
//
//	XMLElement* profily_data;
//	for (int j = 0; j < data_profil.size(); j++)
//	{
//		profily_data = xmlDoc.NewElement("Profil");
//		for (int i = 0; i < data_profil.at(j).size(); i++)
//		{
//			XMLElement* hodnoty = xmlDoc.NewElement("Hodnota");
//			hodnoty->SetText(data_profil.at(j).at(i));
//
//			profily_data->InsertEndChild(hodnoty);
//		}
//		root->InsertEndChild(profily_data);
//	}
//	XMLError eResult = xmlDoc.SaveFile("profily.xml");
//	XMLCheckResult(eResult);
//}

std::vector<std::vector<int>> Profily::nacteni_dat_profilu()
{
	int data = 0;
	std::vector<int> vektor_dat;
	std::vector<std::vector<int>> v_v_dat;

	int pocet_profilu_s = 0;

	xmlDoc.LoadFile(L"profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"Zakladni");
	XMLElement* pocet_profilu = base->FirstChildElement(L"Pocet_profilu");
	pocet_profilu->QueryIntText(&pocet_profilu_s);

	XMLElement* profily_data = root->FirstChildElement(L"Profil");
	for (int i = 0; i < pocet_profilu_s; i++)
	{
		XMLElement* hodnoty = profily_data->FirstChildElement(L"Hodnota");
		while (hodnoty != nullptr)
		{
			hodnoty->QueryIntText(&data);
			vektor_dat.push_back(data);
			hodnoty = hodnoty->NextSiblingElement(L"Hodnota");
		}
		v_v_dat.push_back(vektor_dat);
		vektor_dat.clear();
		profily_data = profily_data->NextSiblingElement(L"Profil");
	}
	return v_v_dat;
}
std::vector<std::vector<char>> Profily::nacteni_jmen_profilu()
{
	int data = 0;
	std::vector<char> vektor_pismen;
	std::vector<std::vector<char>> v_v_pismen;

	int pocet_profilu_s = 0;

	xmlDoc.LoadFile(L"profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"Zakladni");
	XMLElement* pocet_profilu = base->FirstChildElement(L"Pocet_profilu");
	pocet_profilu->QueryIntText(&pocet_profilu_s);

	XMLElement* profily_jmena = base->FirstChildElement(L"Nazev_profilu");
	for (int i = 0; i < pocet_profilu_s; i++)
	{
		XMLElement* hodnoty = profily_jmena->FirstChildElement(L"Pismeno");
		while (hodnoty != nullptr)
		{
			hodnoty->QueryIntText(&data);
			vektor_pismen.push_back(data);
			hodnoty = hodnoty->NextSiblingElement(L"Pismeno");
		}
		v_v_pismen.push_back(vektor_pismen);
		vektor_pismen.clear();
		profily_jmena = profily_jmena->NextSiblingElement(L"Nazev_profilu");
	}
	return v_v_pismen;
}