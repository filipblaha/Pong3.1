#include "Skiny.h"

void Skiny::ZapsaniSkinyPlosina(vector<wstring> vektor)
{
	xmlDoc.LoadFile("Skiny.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* plosina = root->FirstChildElement("Plosina");
	XMLElement* skin = plosina->FirstChildElement("Skin");
	skin->Parent()->DeleteChildren();

	for (int i = 0; i < vektor.size(); i++)
	{
		wstring temp = vektor.at(i);
		skin = xmlDoc.NewElement("Skin");
		for (int i = 0; i < temp.size(); i++)
		{
			XMLElement* znak = xmlDoc.NewElement("znak");
			znak->SetText(temp.at(i));
			skin->InsertEndChild(znak);
		}
		plosina->InsertEndChild(skin);
	}
	xmlDoc.SaveFile("Skiny.xml");
}

//-----------------------  Plosina  -----------------------//

vector<wstring> Skiny::NacteniSkinyPlosina()
{
	vector<wstring> vektor_stringu;
	wstring temp;
	int data = 0;

	xmlDoc.LoadFile("Skiny.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* plosina = root->FirstChildElement("Plosina");
	XMLElement* skin = plosina->FirstChildElement("Skin");

	while (skin != nullptr)
	{	
		XMLElement* znak = skin->FirstChildElement("znak");
		while (znak != nullptr)
		{
			znak->QueryIntText(&data);
			temp.push_back(data);
			znak = znak->NextSiblingElement("znak");
		}
		vektor_stringu.push_back(temp);
		temp.clear();
		skin = skin->NextSiblingElement("Skin");
	}
	return vektor_stringu;
}
void Skiny::PridaniSkinPlosina(wstring skin)
{
	vector<wstring> vektor = NacteniSkinyPlosina();
	vektor.push_back(skin);
	ZapsaniSkinyPlosina(vektor);
}

//-----------------------  Mic  -----------------------//

vector<wchar_t> Skiny::NacteniSkinyMic()
{
	vector<wchar_t> vektor_stringu;
	int data = 0;

	xmlDoc.LoadFile("Skiny.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* mic = root->FirstChildElement("Mic");
	XMLElement* skin = mic->FirstChildElement("Skin");

	while (skin != nullptr)
	{
		skin->QueryIntText(&data);
		vektor_stringu.push_back(data);
		skin = skin->NextSiblingElement("Skin");
	}
	return vektor_stringu;
}
void Skiny::PridaniSkinMic(wchar_t skin)
{
	vector<wchar_t> vektor = NacteniSkinyMic();
	vektor.push_back(skin);
	ZapsaniSkinyMic(vektor);
}
void Skiny::ZapsaniSkinyMic(vector<wchar_t> vektor)
{
	xmlDoc.LoadFile("Skiny.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* mic = root->FirstChildElement("Mic");
	XMLElement* skin = mic->FirstChildElement("Skin");
	skin->Parent()->DeleteChildren();

	for (int i = 0; i < vektor.size(); i++)
	{
		skin = xmlDoc.NewElement("Skin");
		skin->SetText(vektor.at(i));
		mic->InsertEndChild(skin);
	}
	xmlDoc.SaveFile("Skiny.xml");
}