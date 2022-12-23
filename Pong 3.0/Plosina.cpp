#include "Plosina.h"

void Plosina::FormovaniSkiny(Profily& data)
{
	skin.clear();
	for (int i = 0; i < velikost; i++)
	{
		skin.push_back(data.NacteniSkiny().at(data.plosina_skin).at(i));
	}
}