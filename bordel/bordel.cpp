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
	int a = 1;
	int b = -2;
	double c;

	c = 5;
	c += 1 / static_cast<double>(b);
	cout << c;

}