#include "Commands.h"

void Commands::Prechod()
	{
	SetCursorPosition(0, 0);
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 40; i++)
		{
			std::wcout << " ";
		}
		std::wcout << "\n";
	}
	}