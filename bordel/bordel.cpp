#include<iostream>
#include<list>
#include<vector>
#include<conio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <string>

using namespace std;

int main()
{
	while (1)
	{
		/*char zmena = _getch();
		if (zmena == 224)
		{
			switch (_getch())
			{
			case 72:
				cout << "up\n";
				break;
			case 75:
				cout << "left\n";
				break;
			case 77:
				cout << "right\n";
				break;
			case 80:
				cout << "down\n";
				break;
			}
		}
		else
			cout << "invalid\n";*/
		if (GetAsyncKeyState(37))
		{
			cout << "left\n";
		}

		else if (GetAsyncKeyState(39))
		{
			cout << "right\n";
		}
		0x28;
		0x26
	}

}