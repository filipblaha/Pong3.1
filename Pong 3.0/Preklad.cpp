#include "Preklad.h"

//-----------------------  Nacteni textu  -----------------------//

vector<wstring> Preklad::NacteniTextProfil(Profily data)
{
	XMLDocument xmlDoc;
	
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("profil");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextHlavni(Profily data)
{
	XMLDocument xmlDoc;

	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("hlavni");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextHerniMody(Profily data)
{
	XMLDocument xmlDoc;

	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("herni_mody");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextVzhledPlosiny(Profily data)
{
	XMLDocument xmlDoc;

	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("vzhled_plosiny");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextNastaveni(Profily data)
{
	XMLDocument xmlDoc;
	
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("nastaveni");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextOvladani(Profily data)
{
	XMLDocument xmlDoc;

	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("ovladani");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextKonecKola(Profily data)
{
	XMLDocument xmlDoc;
	
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("konec_kola");
	XMLElement* text = menu->FirstChildElement("string");
	while (text != nullptr)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return set.StringToWString(vektor_stringu);
}