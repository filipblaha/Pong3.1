#pragma once
#include <iostream>
#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

class Commands
{
public:

	void Prechod();
	void SetCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hOut, coord);
	}
	void Font(int f1, int f2)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.dwFontSize.X = f1;
		cfi.dwFontSize.Y = f2;
		cfi.FontFamily = FF_DONTCARE;
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}
	void SetWindow(int delka, int vyska)
	{
		_COORD coord;
		coord.X = delka;
		coord.Y = vyska;
		_SMALL_RECT Rect;
		Rect.Top = 0;
		Rect.Left = 0;
		Rect.Bottom = vyska + 1;
		Rect.Right = delka - 1;
		HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleScreenBufferSize(Handle, coord);
		SetConsoleWindowInfo(Handle, TRUE, &Rect);
	}

private:
};