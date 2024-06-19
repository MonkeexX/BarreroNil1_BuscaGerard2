#pragma once
#include <iostream>

enum class Nature {
	TRANQUILA, //Horizontal
	PICARA, //Diagonal
	FUERTE, //Vertical
	INVALID //invalid
};

class Pokemon
{
private:
	Nature nature = Nature::INVALID;
	int posX;
	int posY;

public:
	//Contructor

	void PokemonNature(Nature nature)
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

	void MovePoke(Nature nature)
	{
		bool directionX = rand() % 1;
		bool directionY = rand() % 1;
		if (nature == Nature::TRANQUILA)
		{
			//It only can move horizontal
			if (directionX == true)
			{
				posX++;
			}
			else
				posX--;
		}
		else if (nature == Nature::PICARA)
		{ //Moves in diagonal
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
			//Moves vertical
			if (directionY == true)
			{
				posY++;
			}
			else
				posY--;
		}

	}
};