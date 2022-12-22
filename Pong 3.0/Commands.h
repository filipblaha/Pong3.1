#pragma once
#include <iostream>
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

	void Prechod(int delka, int vyska);
	void SetCursorPosition(int x, int y);
	void SetFont(int f1, int f2);
	void SetWindow(int delka, int vyska);
	int Random(int min, int max);
};