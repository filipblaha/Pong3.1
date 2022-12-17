#include<iostream>
#include<list>
#include<vector>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
using namespace std;

class c
{
public:
	int hodnota = 0;
	void b()
	{
		hodnota = 3;
		cout << hodnota << " class\n";
	}

};
class d
{
public:
	c navod;
	void a(c &navod)
	{
		navod.b();
	}
};
void f(c navod)
{
	cout << navod.hodnota << " fce\n";
}

int main()
{
	c navod;
	d plan;
	plan.a(navod);
	cout << navod.hodnota << " main\n";
	f(navod);
}