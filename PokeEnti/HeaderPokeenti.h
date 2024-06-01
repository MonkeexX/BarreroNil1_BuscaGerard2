#pragma once
#include<iostream>
#include <conio.h>
#include <fstream>
#define MAPSIZE 20
#define MAXPOKE 200
#include "HeaderPokeenti.h"
#include <fstream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32


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

void MapInitiation(int** map, int  mapY, int mapX)
{
	//Firts we create a map in blank
	for (int i = 0; i < mapX; ++i)
	{
		for (int j = 0; j < mapY; ++j)
		{
			if (i == mapX / 2)
			{
				map[i][j] = 1;
			}
			if (j == mapY / 2)
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}

	//Then we will create a map with the walls



}

void AddPokemonToMap(int num, char map, char* maping [MAPSIZE][MAPSIZE])
{
	//Pokemon = 1
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKE; pokemonGenerated++)
	{
		int posX = rand() % MAPSIZE;
		int posY = rand() % MAPSIZE;
		if (*maping[posX][posY] != 0 && *maping[posX][posY] != 1)
		{
			*maping[posX][posY] = 2;
		}
	}
}

void PrintMap(int** map, int  mapY, int mapX)
{

	for (int i = 0; i < mapX; ++i)
	{
		for (int j = 0; j < mapY; ++j)
		{
			if (i == mapX/2 || j == mapY/2)
			{
				std::cout << "X";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}


int CapturingPokemon(int posX, int posY, int capturedPoke, char map[MAPSIZE][MAPSIZE])
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

void PrintCaracter(int caracter, char c)
{
	std::cout << c, caracter;
}

void PrintMapold(char map[MAPSIZE][MAPSIZE], int caracter, char c)
{
	int counterI = 0;
	int counterJ = 0;
	for (int i = 0; i < MAPSIZE; i++)
	{
		counterI++;
		counterJ = 0;
		for (int j = 0; j < MAPSIZE; j++)
		{
			counterJ++;
			if (map[counterI][counterJ] == 1)
			{
				std::cout << "X";
			}
			else if (map[counterI][counterJ] == 2)
			{
				std::cout << "P";
			}
			else
			{
				std::cout << " ";
			}

		}
		std::cout <<  "\n";
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

