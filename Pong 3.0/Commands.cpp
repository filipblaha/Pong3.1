#include "Commands.h"

void Commands::Prechod(int delka, int vyska)
	{
	SetCursorPosition(0, 0);
	for (int j = 0; j < vyska; j++)
	{
		for (int i = 0; i < delka; i++)
		{
			wcout << " ";
		}
		wcout << "\n";
	}
	}
void Commands::SetCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
void Commands::SetFont(int f1, int f2)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = f1;
	cfi.dwFontSize.Y = f2;
	cfi.FontFamily = FF_DONTCARE;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void Commands::SetWindow(int delka, int vyska)
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
int Commands::Random(int min, int max)
{
	random_device random_cislo;
	mt19937 seed(random_cislo());
	uniform_int_distribution<> rozmezi(min, max);
	return rozmezi(seed);
}