#include<iostream>
#include<list>
#include<vector>
#include<conio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <string>

using namespace std;

void a()
{
	int a = 0;
}
void b()
{

}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);  // nastaveni graficke vizualizace
	
	wcout << L"\x25ba";
}