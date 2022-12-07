#include "Preklad.h"

std::vector<std::wstring> Preklad::StringToWString(std::vector<std::string> s)
{
	std::string sTmp;
	std::vector<std::wstring> ws;
	for (int i = 0; i < s.size(); i++)
	{
		sTmp = s.at(i);
		std::wstring wsTmp(sTmp.begin(), sTmp.end());
		ws.push_back(wsTmp);
	}
	return ws;
}
std::vector<std::wstring> Preklad::nacteni_textu_profil()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("profil");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("profil");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
std::vector<std::string> Preklad::nacteni_textu_hlavni()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("hlavni");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("hlavni");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_herni_mody()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("herni_mody");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("herni_mody");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_vzhled_plosiny()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("vzhled_plosiny");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("vzhled_plosiny");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_nastaveni()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("nastaveni");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("nastaveni");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_ovladani()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("ovladani");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("ovladani");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_konec_kola()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("konec_kola");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement("CZ");
	if (menu.jazyk == menu.EN)
		jazyk = root->FirstChildElement("EN");

	XMLElement* menu = jazyk->FirstChildElement("konec_kola");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return vektor_stringu;
}