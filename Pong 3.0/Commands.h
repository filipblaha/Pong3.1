#pragma once
#include <iostream>
#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

class Commands
{
public:

	void Prechod();
	void SetCursorPosition(int x, int y);
	void Font(int f1, int f2);
	void SetWindow(int delka, int vyska);
};