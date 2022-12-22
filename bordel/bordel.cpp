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
	int vzdalenost = 4;
	int plocha = 10;
	int a = 4, b = 5;



	vector<int> temp;
	vector<vector<int>> ULDR;
	for (size_t i = 0; i < plocha; i++)
	{
		temp.clear();
		for (size_t j = 0; j < plocha; j++)
		{
			temp.push_back(0);
		}
		ULDR.push_back(temp);
	}
	for (size_t i = 0; i < plocha; i++)
	{
		for (size_t j = 0; j < plocha; j++)
		{
			std::cout << ULDR.at(j).at(i) << ' ';
		}
		std::cout << '\n';
	}

	std::cout << "\n\n\n";

	int levah, pravah, dolnih, hornih;

	if (plocha - b < vzdalenost)
		dolnih = plocha - b;
	else
		dolnih = vzdalenost;

	if (b < vzdalenost)
		hornih = b;
	else
		hornih = vzdalenost;

	if (plocha - a < vzdalenost)
		levah = plocha - a;
	else
		levah = vzdalenost;

	if (a < vzdalenost)
		pravah = a;
	else
		pravah = vzdalenost;

	for (int j = -levah; j <= pravah; j++)
	{
		for (int i = -dolnih; i <= hornih; i++)
		{
			if ((abs(i) + abs(j)) <= vzdalenost)
			{
				ULDR.at(a - j).at(b - i) = 1;
			}
		}
	}
	for (size_t i = 0; i < plocha; i++)
	{
		for (size_t j = 0; j < plocha; j++)
		{
			std::cout << ULDR.at(j).at(i) << ' ';
		}
		std::cout << '\n';
	}
}