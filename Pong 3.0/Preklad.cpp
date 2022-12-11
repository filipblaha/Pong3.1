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
std::list<std::wstring> Preklad::StringToWStringList(std::list<std::string> s)
{
	std::string sTmp;
	std::list<std::wstring> ws;
	std::list<std::string>::iterator itr;
	for (itr = s.begin(); itr != s.end(); itr++)
	{
		sTmp = *itr;
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

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("profil");
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
std::vector<std::wstring> Preklad::nacteni_textu_hlavni()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("hlavni");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("hlavni");
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
std::vector<std::wstring> Preklad::nacteni_textu_herni_mody()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("herni_mody");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("herni_mody");
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
std::vector<std::wstring> Preklad::nacteni_textu_vzhled_plosiny()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("vzhled_plosiny");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("vzhled_plosiny");
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
std::vector<std::wstring> Preklad::nacteni_textu_nastaveni()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("nastaveni");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("nastaveni");
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
std::vector<std::wstring> Preklad::nacteni_textu_ovladani()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("ovladani");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("ovladani");
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
std::vector<std::wstring> Preklad::nacteni_textu_konec_kola()
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("konec_kola");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("konec_kola");
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