#pragma once
#include<iostream>
#include "Pokemon.h"
#define MAXPOKE 100
void MapInitiation(int** map, int  mapY, int mapX)
{

	//Firts we create a map in blank
	for (int i = 0; i < mapX; ++i)
	{
		for (int j = 0; j < mapY; ++j)
		{
			map[i][j] = 0;
		}

		for (int i = 0; i < mapY; ++i)
		{
			map[mapX / 2][i] = 1;
		}

		for (int i = 0; i < mapX; ++i)
		{
			map[i][mapY / 2] = 1;
		}
	}
	map[0][0] = 6;
}

void UnlockZones(int captured, int paleta, int forest, int cave, int** map, int mapX, int mapY)
{
	if (captured >= paleta)
	{
		for (int j = 0; j < (mapY / 2) - 10; j++)
		{
			map[j][mapY / 2] = 0;
		}
	}

	if (captured >= forest)
	{
		for (int j = (mapX / 2) + 11; j < mapX + 21; j++)
		{
			map[mapX / 2][j] = 0;
		}
	}



}

void AddPokemonToMap(int** map, int  mapY, int mapX)
{
	//Pokemon = 2
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKE ; pokemonGenerated++)
	{
		Pokemon::PokemonNature();
		int posX = rand() % mapX;
		int posY = rand() % mapY;
		if (map[posX][posY] != 1 && map[posX][posY] != 2)
		{
			map[posX][posY] = 2;
		}
	}
}

void AddPokeballsToMap(int** map, int mapX, int mapY)
{
	bool hasGeneratedWell = false;
	int posX = rand() % mapX;
	int posY = rand() % mapY;
	while (!hasGeneratedWell)
	{
		if (map[posX][posY] != 1 && map[posX][posY] != 2)
		{
			hasGeneratedWell = true;
			map[posX][posY] = 3;
		}
	}
}

void PrintMap(int** map, int  mapY, int mapX, int posX, int posY, int posXMin, int posYMin)
{
	if (posXMin < 0)
	{
		posXMin = 0;
	}
	if (posYMin < 0)
	{
		posYMin = 0;
	}
	if (posX > mapX)
	{
		posX = mapX;
	}
	if (posY > mapY)
	{
		posY = mapY;
	}
	for (int i = posXMin; i < mapX; ++i)
	{
		for (int j = posYMin; j < mapY; ++j)
		{
			if (map[i][j] == 1)
			{
				std::cout << "X";
			}
			else if (map[i][j] == 2)
			{
				std::cout << "P";
			}
			else if (map[i][j] == 3)
			{
				std::cout << "O";
			}
			//Now for the character movement
			else if (map[i][j] == 5)
			{
				std::cout << "^";
			}
			else if (map[i][j] == 6)
			{
				std::cout << "v";
			}
			else if (map[i][j] == 7)
			{
				std::cout << ">";
			}
			else if (map[i][j] == 8)
			{
				std::cout << "<";
			}
			else if (map[i][j] == 0)
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}