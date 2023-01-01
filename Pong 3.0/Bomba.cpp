#include "Bomba.h"

void Bomba::Start()
{
	x = x_d = start_x;
	y = y_d = start_y;
	ax = 0;
	ay = 0;
}
void Bomba::SpawnPozice()
{
	start_x = set.Random(2, pole.delka - 3);
}
int Bomba::SpawnCas()
{
	return rychlost * set.Random(10, 20);
}