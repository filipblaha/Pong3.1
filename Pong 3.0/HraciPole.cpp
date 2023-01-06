#include "HraciPole.h"

void HraciPole::VytvoreniBloku()
{
	vector<int> temp;

	for (int j = 0; j < vyska; j++)
	{
		temp.clear();
		for (int i = 0; i < delka; i++)
		{
			if (i != 0 && i != delka - 1 && j > 0 && j < 7 && ((i % 3 == 0 && i < 10) || (i % 3 == 1 && i >= 10)))
			{
				if (j < 4)
				{
					if (j < 2)
						temp.push_back(3);
					else
						temp.push_back(2);
				}
				else
					temp.push_back(1);
			}
			else
				temp.push_back(-1);

		}
		bloky.push_back(temp);
	}
}