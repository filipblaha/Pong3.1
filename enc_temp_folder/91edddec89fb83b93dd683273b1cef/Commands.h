#pragma once
#include <iostream>
#include <list>
#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <random>

using namespace std;

class Commands
{
public:

	Commands()
	{
		_setmode(_fileno(stdout), _O_U16TEXT);  // nastaveni graficke vizualizace
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ci;
		ci.dwSize = 25;
		ci.bVisible = FALSE;
		SetConsoleCursorInfo(output, &ci);
	}
	//-----------------------  Visual  -----------------------//

	void Prechod(int delka, int vyska);
	void SetCursorPosition(int x, int y);
	void SetFont(int f1, int f2);
	void SetWindow(int delka, int vyska);

	//-----------------------  Game function  -----------------------//

	int Random(int min, int max);

	//-----------------------  Premena string na wstring  -----------------------//

	vector<wstring> StringToWString(vector<string> s);
	list<wstring> StringToWStringList(list<string> s);
};