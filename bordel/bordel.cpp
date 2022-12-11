#include<iostream>
#include<list>
#include<vector>

void erase_list(std::list<std::string> &list, int x)
{
	std::list<std::string>::iterator itr;
	itr = list.begin();

	advance(itr, x);
	list.erase(itr);
}
void add_list(std::list<std::string>& list, std::vector<std::string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		list.push_back(v.at(i));
	}
}

int main()
{
	char s;
	std::cin >> s;
	
}