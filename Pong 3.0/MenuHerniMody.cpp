#include "MenuHerniMody.h"

//-----------------------  Input  -----------------------//

int MenuHerniMody::Rozhodovac(int prikaz)
{
	if (oznaceni.at(y) == 10)
	{
		return klasik_e;
	}
	if (oznaceni.at(y) == 12)
	{
		return bloky_padaji_e;
	}
	if (oznaceni.at(y) == 14)
	{
		return rogue_like_e;
	}
}

//-----------------------  Vykresleni -----------------------//

void MenuHerniMody::MenuHerniModyVykresleni(int jazyk)
{
	OznaceniVykresleni();
	TextHerniModyVykresleni(jazyk);
}
void MenuHerniMody::TextHerniModyVykresleni(int jazyk) 
{
	transl.jazyk = jazyk;
	text = transl.NacteniTextHerniMody();

	///-------  Text  -------//

	set.SetCursorPosition(14, 4);
	wcout << text.at(0);
	set.SetCursorPosition(6, 10);
	wcout << text.at(1);
	set.SetCursorPosition(6, 12);
	wcout << text.at(2);
	set.SetCursorPosition(6, 14);
	wcout << text.at(3);
}