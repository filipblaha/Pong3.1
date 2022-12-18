#include "Profily.h"

//-----------------------  Ukladani profilu  -----------------------//

void Profily::UlozeniProfilu(int profil)
{
	list<vector<int>> data_profil;
	list<string> nazev_profil;

	for (int i = 0; i < pocet_profilu; i++)
	{
		if (i == profil)
			data_profil.push_back(VlozeniDatDoVektoru());
		else
			data_profil.push_back(NacteniDatProfilu(i));
	}

	nazev_profil = NacteniJmenProfilu();

	ZapsaniProfilu(data_profil, nazev_profil);
}
vector<int> Profily::VlozeniDatDoVektoru()
{
	vector<int> data_profil;

	data_profil.push_back(jazyk);
	data_profil.push_back(level);
	data_profil.push_back(exp);
	data_profil.push_back(plosina_skin);
	data_profil.push_back(highscore_cas);
	data_profil.push_back(highscore_znicenych_bloku);

	return data_profil;
}

void Profily::VytvoreniNovehoProfilu(string nazev_noveho_profilu)
{
	list<int> uroven_profil;
	vector<int> data_noveho_profilu;
	list<vector<int>> data_profil;

	uroven_profil = NacteniUrovniProfilu();
	uroven_profil.push_front(0);

	for (int i = 0; i < 6; i++)
	{
		data_noveho_profilu.push_back(0);
	}
	for (int i = 0; i < pocet_profilu; i++)
	{
			data_profil.push_back(NacteniDatProfilu(i));
	}
	list<string> nazev_profil = NacteniJmenProfilu();

	itri = data_profil.begin();
	itri++;
	data_profil.insert(itri, data_noveho_profilu);

	itr = nazev_profil.begin();
	itr++;
	nazev_profil.insert(itr, nazev_noveho_profilu);

	pocet_profilu++;

	ZapsaniProfilu(data_profil, nazev_profil);
}
void Profily::OdstraneniProfilu(int profil)
{
	list<int> uroven_profil = NacteniUrovniProfilu();
	list<vector<int>> data_profil;
	list<string> nazev_profil;

	list<int>::iterator itrl = uroven_profil.begin();
	advance(itrl, profil);
	uroven_profil.erase(itrl);
	

	for (int i = 0; i < pocet_profilu; i++)
	{
		data_profil.push_back(NacteniDatProfilu(i));
	}
	nazev_profil = NacteniJmenProfilu();

	itri = data_profil.begin();
	advance(itri, profil);
	data_profil.erase(itri);

	itr = nazev_profil.begin();
	advance(itr, profil);
	nazev_profil.erase(itr);

	pocet_profilu--;

	ZapsaniProfilu(data_profil, nazev_profil);
}

int Profily::ZapsaniProfilu(list<vector<int>> data, list<string> nazev)
{
	XMLDocument xmlDoc;
	XMLNode* root = xmlDoc.NewElement("root");
	xmlDoc.InsertFirstChild(root);

	XMLElement* base = xmlDoc.NewElement("Zakladni");
	root->InsertEndChild(base);

	string temp;
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

	vector<int> tempi;
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

vector<vector<int>> Profily::NacteniDat()
{
	XMLDocument xmlDoc;
	int data = 0;
	vector<int> vektor_dat;
	vector<vector<int>> v_v_dat;


	xmlDoc.LoadFile("profily.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* profily_data = root->FirstChildElement("Profil");
	while (profily_data != nullptr)
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
int  Profily::NacteniPoctuProfilu()
{
	vector<vector<int>> v_v_dat = NacteniDat();
	return v_v_dat.size();
}
list<int> Profily::NacteniUrovniProfilu()
{
	vector<vector<int>> v_v_dat = NacteniDat();
	list<int> list_dat;

	for (int i = 0; i < v_v_dat.size(); i++)
	{
		list_dat.push_back(v_v_dat.at(i).at(1));
	}
	return list_dat;
}
vector<int> Profily::NacteniDatProfilu(int profil)
{
	vector<vector<int>> v_v_dat = NacteniDat();
	return v_v_dat.at(profil);
}
list<string> Profily::NacteniJmenProfilu()
{
	XMLDocument xmlDoc;
	int data = 0;
	string vektor_pismen;
	list<string> v_v_pismen;

	xmlDoc.LoadFile("profily.xml");

	NacteniPoctuProfilu();

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("Zakladni");
	XMLElement* profily_jmena = base->FirstChildElement("Nazev_profilu");
	while (profily_jmena != nullptr)
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

void Profily::VybraniProfilu(int profil)
{
	vector<int> vektor_dat = NacteniDatProfilu(profil);

	jsem_v_profilu = profil;

	jazyk = vektor_dat.at(0);
	level = vektor_dat.at(1);
	exp = vektor_dat.at(2);
	plosina_skin = vektor_dat.at(3);
	highscore_cas = vektor_dat.at(4);
	highscore_znicenych_bloku = vektor_dat.at(5);
}

//-----------------------  Zmena jmena  -----------------------//

void Profily::ZmenaJmena(string jmeno, int profil)
{
	list<string> nazev_profil = NacteniJmenProfilu();
	itr = nazev_profil.begin();

	advance(itr, profil);
	*itr = jmeno;

	list<vector<int>> data_profil;
	for (int i = 0; i < pocet_profilu; i++)
	{
		data_profil.push_back(NacteniDatProfilu(i));
	}

	ZapsaniProfilu(data_profil, nazev_profil);
}