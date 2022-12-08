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
	std::list<std::string> profil_list;
	std::vector<std::string> v;

	std::string a;

	a.push_back('F');
	a.push_back('i');
	a.push_back('l');
	a.push_back('i');
	a.push_back('p');

	std::string b = "Fanda";
	std::string c = "Jirka";
	std::string d = "smazak";
	std::string e = "macek";
	std::string f = "pacek";

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);
	

	add_list(profil_list, v);
	std::list<std::string>::iterator itr;

	for (itr = profil_list.begin(); itr != profil_list.end(); itr++)
	{
		std::cout << *itr << '\n';
	}

	std::cout << '\n';
	itr = profil_list.begin();
	advance(itr, 2);

	profil_list.insert(itr, f);
	profil_list.erase(itr);

	for (itr = profil_list.begin(); itr != profil_list.end(); itr++)
	{
		std::cout << *itr << '\n';
	}
}