#include "MenuHerniMody.h"

//-----------------------  Input  -----------------------//

int MenuHerniMody::Rozhodovac(Profily& data)
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

void MenuHerniMody::MenuHerniModyVykresleni(Profily& data)
{
	OznaceniVykresleni(0);
	VykresleniUroven(data);
	TextHerniModyVykresleni(data);
}
void MenuHerniMody::TextHerniModyVykresleni(Profily& data)
{
	text = transl.NacteniTextHerniMody(data);

	///-------  Text  -------//

	set.SetCursorPosition(14, 4);
	wcout << text.at(0);
	set.SetCursorPosition(6, 10);
	wcout << text.at(1);
	//set.SetCursorPosition(6, 12);
	//wcout << text.at(2);
}