#include "Preklad.h"

std::vector<std::wstring> Preklad::nacteni_textu_profil()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"profil");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"profil");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}
std::vector<std::wstring> Preklad::nacteni_textu_hlavni()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"hlavni");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"hlavni");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}
std::vector<std::wstring> Preklad::nacteni_textu_herni_mody()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"herni_mody");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"herni_mody");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}
std::vector<std::wstring> Preklad::nacteni_textu_vzhled_plosiny()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"vzhled_plosiny");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"vzhled_plosiny");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}
std::vector<std::wstring> Preklad::nacteni_textu_nastaveni()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"nastaveni");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"nastaveni");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}
std::vector<std::wstring> Preklad::nacteni_textu_ovladani()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"ovladani");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"ovladani");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}
std::vector<std::wstring> Preklad::nacteni_textu_konec_kola()
{
	TiXMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile(L"Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement(L"zaklad");

	XMLElement* profil = base->FirstChildElement(L"konec_kola");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"CZ");
	if (menu.jazyk == menu.CZ)
		jazyk = root->FirstChildElement(L"EN");

	XMLElement* menu = jazyk->FirstChildElement(L"konec_kola");
	XMLElement* text = menu->FirstChildElement(L"string");
	for (int i = 0; i < profil_stringu; i++)
	{
		const wchar_t* data = text->GetText();
		std::wstring sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement(L"string");
	}
	return vektor_stringu;
}