#include<iostream>
#include<list>
#include<vector>
using namespace std;

void erase_list(list<string> &list, int x)
{
	list<string>::iterator itr;
	itr = list.begin();

	advance(itr, x);
	list.erase(itr);
}
void add_list(list<string>& list, vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		list.push_back(v.at(i));
	}
}

int main()
{
	char s;
	cin >> s;
	
}