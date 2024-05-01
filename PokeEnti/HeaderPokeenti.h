#pragma once
#pragma once
#include<iostream>
#include <conio.h>
#define MAPSIZE 100
#define MAXPOKEMON 200
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32

int pokeCapture;
char map[MAPSIZE][MAPSIZE];
char* mapSice;

//void mapCopy(char map[MAPSIZE][MAPSIZE])
//{
//for (int i = 0; i < MAPSIZE; i++)
//{
//for (int j = 0; j < MAPSIZE; j++)
//{
//*mapSice[i][j] = &map[i][j];
//}
//}
//}

void MapInitiation(char* map [MAPSIZE][MAPSIZE])
{



	//Now we are going to dive in four zones las paredes se representan con (X)

	for (int i = 0; i < MAPSIZE; i++)
	{
		*map[i][MAPSIZE / 2] = 'X';
		*map[MAPSIZE / 2][i] = 'X';

		//return map;
	}
}

void AddPokemonToMap(int num)
{
	//P represents a pokemon in a position
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKEMON; pokemonGenerated++)
	{
		int posX = rand() % MAPSIZE;
		int posY = rand() % MAPSIZE;
		if (map[posX][posY] != 'X' && map[posX][posY] != 'P')
		{
			map[posX][posY] = 'P';
		}
	}
}

int CapturingPokemon(int posX, int posY, int capturedPoke, char map[MAPSIZE][MAPSIZE])
{
	bool isTherePokemon = false;

	//we will check every square next to the player
	int x;
	int y;
	if (map[posX][posY++] == 'P')
	{
		x = posX;
		y = posY++;
		isTherePokemon = true;
	}
	else if (map[posX++][posY++] == 'P')
	{
		x = posX++;
		y = posY++;
		isTherePokemon = true;
	}
	if (map[posX++][posY] == 'P')
	{
		x = posX++;
		y = posY;
		isTherePokemon = true;
	}
	if (map[posX++][posY--] == 'P')
	{
		x = posX++;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX][posY--] == 'P')
	{
		x = posX;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX--][posY--] == 'P')
	{
		x = posX--;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX--][posY] == 'P')
	{
		x = posX--;
		y = posY;
		isTherePokemon = true;
	}
	if (map[posX--][posY++] == 'P')
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
		return 1;
	}
	else if (input == KEY_DOWN)
	{
		return 2;
	}
	else if (input == KEY_RIGHT)
	{
		return 3;
	}
	else if (input == KEY_LEFT)
	{
		return 4;
	}
	else if (input == KEY_SPACE)
	{
		return 5;
	}

	//falta el exit
}

void PrintMap(char map[MAPSIZE][MAPSIZE])
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; i++)
		{
			std::cout << map[i][j] << "0";
			if (j == MAPSIZE)
			{
				std::cout << "\n";
			}
		}
	}
}


//{

//for (int i = 0; i <= MAPSIZE; i++)
//{
//for (int j = 0; j <= MAPSIZE; j++)
//{

//}
//}

//}

