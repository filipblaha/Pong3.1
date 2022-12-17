#include "Preklad.h"

//-----------------------  Premena string na wstring  -----------------------//

vector<wstring> Preklad::StringToWString(vector<string> s)
{
	string sTmp;
	vector<wstring> ws;
	for (int i = 0; i < s.size(); i++)
	{
		sTmp = s.at(i);
		wstring wsTmp(sTmp.begin(), sTmp.end());
		ws.push_back(wsTmp);
	}
	return ws;
}
list<wstring> Preklad::StringToWStringList(list<string> s)
{
	string sTmp;
	list<wstring> ws;
	list<string>::iterator itr;
	for (itr = s.begin(); itr != s.end(); itr++)
	{
		sTmp = *itr;
		wstring wsTmp(sTmp.begin(), sTmp.end());
		ws.push_back(wsTmp);
	}
	return ws;
}

//-----------------------  Nacteni textu  -----------------------//

vector<wstring> Preklad::NacteniTextProfil(Profily data)
{
	XMLDocument xmlDoc;


	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("profil");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("profil");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextHlavni(Profily data)
{
	XMLDocument xmlDoc;

	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("hlavni");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("hlavni");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextHerniMody(Profily data)
{
	XMLDocument xmlDoc;

	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("herni_mody");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("herni_mody");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextVzhledPlosiny(Profily data)
{
	XMLDocument xmlDoc;

	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("vzhled_plosiny");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("vzhled_plosiny");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextNastaveni(Profily data)
{
	XMLDocument xmlDoc;

	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("nastaveni");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("nastaveni");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextOvladani(Profily data)
{
	XMLDocument xmlDoc;

	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("ovladani");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("ovladani");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}
vector<wstring> Preklad::NacteniTextKonecKola(Profily data)
{
	XMLDocument xmlDoc;

	vector<int> vektor_poctu_stringu;
	vektor_stringu.clear();

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("konec_kola");
	profil->QueryIntText(&profil_stringu);

	XMLElement*jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == CZ)
		jazyk_p = root->FirstChildElement("CZ");
	if (data.jazyk == EN)
		jazyk_p = root->FirstChildElement("EN");

	XMLElement* menu =jazyk_p->FirstChildElement("konec_kola");
	XMLElement* text = menu->FirstChildElement("string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = text->GetText();
		string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("string");
	}
	return StringToWString(vektor_stringu);
}