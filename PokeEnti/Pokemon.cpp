#include "Pokemon.h"
#include <iostream>

void Pokemon::PokemonNature(Nature nature)
{
	int random = rand() % 3;

	switch (random)
	{
	case 0:
		nature = Nature::TRANQUILA;
		break;
	case 1:
		nature = Nature::PICARA;
		break;
	case 3:
		nature = Nature::FUERTE;
		break;
	}
}

void Pokemon::MovePoke(Nature nature)
{
	bool directionX = rand() % 1;
	bool directionY = rand() % 1;
	if (nature == Nature::TRANQUILA)
	{
		if (directionX == true)
		{
			posX++;
		}
		else
			posX--;
	}
	else if (nature == Nature::PICARA)
	{
		if (directionX == true)
		{
			posX++;
		}
		else
			posX--;
		if (directionY == true)
		{
			posY++;
		}
		else
			posY--;
	}
	else if (nature == Nature::FUERTE)
	{
		if (directionY == true)
		{
			posY++;
		}
		else
			posY--;
	}