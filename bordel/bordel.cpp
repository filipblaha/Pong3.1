#include<iostream>
#include<list>
#include<vector>
#include<conio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
using namespace std;

bool b()
{
	cout << "Funkce b\n";
	return 0;
}

bool a()
{
	while (1)
	{
		switch (_getch())
		{
		case ' ':
		{
			cout << "mezernik";
			return 1;
		}
		case 'q':
		{
			cout << 'q';
			return 0;
		}
		default:
			break;
		}
	}
}

int main()
{
	a();
}