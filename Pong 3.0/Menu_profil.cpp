#include "Menu_profil.h"

void Menu_profil::vykresleni_profil(std::wstring prvni_profil_v)
{

	///////    Ramecek   ///////
	set.setCursorPosition(8, 7);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 23)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	for (int j = 8; j < 13; j++)
	{
		set.setCursorPosition(8, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2502";
		}
	}
	for (int j = 8; j < 13; j++)
	{
		set.setCursorPosition(31, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2502";
		}
	}
	set.setCursorPosition(8, 13);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			std::wcout << L"\x2514";
		else if (i == 23)
			std::wcout << L"\x2518";
		else
			std::wcout << L"\x2500";
	}
	set.setCursorPosition(32, 16);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::wcout << L"\x250c";
		else if (i == 6)
			std::wcout << L"\x2510";
		else
			std::wcout << L"\x2500";
	}
	set.setCursorPosition(32, 17);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || i == 6)
			std::wcout << L"\x2502";
		else if (i == 3)
			std::wcout << char(17);
		else if (i == 4 || i == 5)
			std::wcout << L"\x2500";
		else
			std::wcout << ' ';
	}
	set.setCursorPosition(32, 18);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::wcout << L"\x2514";
		else if (i == 6)
			std::wcout << L"\x2518";
		else
			std::wcout << L"\x2500";
	}

	///////    Text   ///////

	std::vector<std::wstring> v = transl.nacteni_textu_profil();
	std::list<std::string> l = profil.nacteni_jmen_profilu();
	std::list<std::wstring> wl = transl.StringToWStringList(l);
	std::list<std::wstring>::iterator itr;

	set.setCursorPosition(10, 5);
	std::wcout << v.at(0);


	for (itr = wl.begin(); itr != wl.end(); itr++)
	{
		if(*itr == prvni_profil_v)
		{
			set.setCursorPosition(12, 8);
			std::wcout << *itr;
			itr++;
			set.setCursorPosition(12, 10);
			std::wcout << *itr;
			itr++;
			set.setCursorPosition(12, 12);
			std::wcout << *itr;
		}
	}



	set.setCursorPosition(4, 16);
	std::wcout << v.at(1);
	set.setCursorPosition(4, 17);
	std::wcout << v.at(2);
	if (!jazyk)
		set.setCursorPosition(18, 17);
	if (jazyk)
		set.setCursorPosition(17, 17);
	std::wcout << v.at(3);
}

std::wstring Menu_profil::urceni_prvniho_profilu()
{
	std::list<std::string> list_prof = profil.nacteni_jmen_profilu();
	std::list<std::wstring> list_prof_wstring = transl.StringToWStringList(list_prof);
	return *list_prof_wstring.begin();
}