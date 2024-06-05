#pragma once
#include "Pokemon.h"

int CapturingPokemon(int posX, int posY, int capturedPoke, int** map)
{
	bool isTherePokemon = false;

	//we will check every square next to the player
	int x;
	int y;
	if (map[posX][posY++] == 1)
	{
		x = posX;
		y = posY++;
		isTherePokemon = true;
	}
	else if (map[posX++][posY++] == 1)
	{
		x = posX++;
		y = posY++;
		isTherePokemon = true;
	}
	if (map[posX++][posY] == 1)
	{
		x = posX++;
		y = posY;
		isTherePokemon = true;
	}
	if (map[posX++][posY--] == 1)
	{
		x = posX++;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX][posY--] == 1)
	{
		x = posX;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX--][posY--] == 1)
	{
		x = posX--;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX--][posY] == 1)
	{
		x = posX--;
		y = posY;
		isTherePokemon = true;
	}
	if (map[posX--][posY++] == 1)
	{
		x = posX--;
		y = posY++;
		isTherePokemon = true;
	}
	if (isTherePokemon)
	{
		//Combat();
	}
	return capturedPoke;
}

/*
void Combat()
{
	//Capturar Pokémon:
	if ( < 0)
	{
		int capture = rand() %  //vida poquemon;
			if (capture <= 20)
			{
				map[x][y] = ' ';
				capturedPoke++;
			}
	}
	else
	{
		std::cout << "You don't have pokeballs";
	}

	//Atacar:
	if (life > 0)
	{
		//hacer daño
		if (life < 1)
		{
			map[x][y] = ' ';
		}
	}

	//Huir:
	//quitae menu pelea
}
*/

void PrintPokemonNum(int captured)
{
	std::cout << "Number of Pokemon captured: " << captured << std::endl;
}