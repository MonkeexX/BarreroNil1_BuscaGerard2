#pragma once
#include<iostream>
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32
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
	map[0][0] =6;
}

void UnlockZones(int captured, int paleta, int forest, int cave, int** map, int mapX, int mapY)
{
	if (captured >= paleta)
	{
		for (int j =0; j < (mapY / 2)-10; j++)
		{
			map[j][mapY/2]= 0;
		}
	}

	if (captured >= forest)
	{
		for (int j = (mapX / 2) +11; j < mapX+21; j++)
		{
			map[mapX/2][j] = 0;
		}
	}

	for (int j =0; j < (mapY); ++j)
	{
		map[j][mapX / 2] = 0;
	}
}

void AddPokemonToMap(int** map, int  mapY, int mapX)
{
	//Pokemon = 2
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKE; pokemonGenerated++)
	{
		int posX = rand() % mapX;
		int posY = rand() % mapY;
		if (map[posX][posY] != 1 && map[posX][posY] != 2)
		{
			map[posX][posY] = 2;
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
		map[x][y] = ' ';
		capturedPoke++;
	}
	return capturedPoke;
}

int CharacterMovement(int input)
{
	if (input == KEY_UP)
	{
		return 5;
	}
	else if (input == KEY_DOWN)
	{
		return 6;
	}
	else if (input == KEY_RIGHT)
	{
		return 7;
	}
	else if (input == KEY_LEFT)
	{
		return 8;
	}
	else if (input == KEY_SPACE)
	{
		return 9;
	}
}

void PrintCaracter(int caracter, char c)
{
	std::cout << c, caracter;
}
