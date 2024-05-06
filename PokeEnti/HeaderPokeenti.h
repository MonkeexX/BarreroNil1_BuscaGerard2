#pragma once
#pragma once
#include<iostream>
#include <windows.h>
const int MAP_SIZE = 20;
const int MAX_POKEMON = 200;

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

void MapInitiation(char* map[MAP_SIZE][MAP_SIZE])
{



	//Now we are going to dive in four zones las paredes se representan con (X)

	for (int i = 0; i < MAP_SIZE; i++)
	{
		*map[i][MAP_SIZE / 2] = 'X';
		*map[MAP_SIZE / 2][i] = 'X';

		//return map;
	}
}

void AddPokemonToMap(int num, char map)
{
	//P represents a pokemon in a position
	for (int pokemonGenerated = 0; pokemonGenerated < MAX_POKEMON; pokemonGenerated++)
	{
		int posX = rand() % MAP_SIZE;
		int posY = rand() % MAP_SIZE;
		//if (map[posX][posY] != 'X' && map[posX][posY] != 'P')
		{
			//map[posX][posY] = 'P';
		}
	}
}

int CapturingPokemon(int posX, int posY, int capturedPoke, char map[MAP_SIZE][MAP_SIZE])
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
	if (input == VK_UP)
	{
		return 1;
	}
	else if (input == VK_DOWN)
	{
		return 2;
	}
	else if (input == VK_LEFT)
	{
		return 3;
	}
	else if (input == VK_RIGHT)
	{
		return 4;
	}
	else if (input == VK_SPACE)
	{
		return 5;
	}
	else if (input == VK_ESCAPE)
	{
		return 6;
	}

	//falta el exit
}

void PrintCaracter(int caracter, char c)
{
	std::cout << c, caracter;
}

void PrintMap(char** map, int caracter, char c)
{
	int counterI = 0;
	int counterJ = 0;
	for (int i = 0; i < MAP_SIZE; i++)
	{
		counterI++;
		counterJ = 0;
		for (int j = 0; j < MAP_SIZE; j++)
		{
			counterJ++;
			if (i == MAP_SIZE / 2)
			{
				map[j][i] = 'X';
				counterI = 0;

			}
			else if (map[i][j] == 'P')
			{
				map[j][i] = 'P';
			}
			else if (j == MAP_SIZE / 2)
			{
				map[j][i] = 'X';
				counterJ = 0;
			}
			else
			{
				map[j][i] = ' ';
			}
			std::cout << map[j][i];

			if (map[j][i] == caracter)
			{
				PrintCaracter(caracter, c);
			}
		}
		std::cout << "\n";
	}

}

void PrintPoke(char** mapa, int captured)
{
	for (int pokemonGenerated = 0; pokemonGenerated < MAX_POKEMON; pokemonGenerated++)
	{
		int posX = 5 + rand() % MAP_SIZE;
		int posY = 5 + rand() % MAP_SIZE;
		if (mapa[posX][posY] != 'X' && mapa[posX][posY] != 'P')
		{
			mapa[posX][posY] = 'P';
			std::cout << "Poke in:" << posX << posY << "\n";
		}
		std::cout << "Number of Pokemon captured: " << captured;


	}
}
void SettingMapBarrieres(char** mapa)
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (i == MAP_SIZE / 2)
			{
				mapa[j][i] = 'X';
			}

			else if (j == MAP_SIZE / 2)
			{
				mapa[j][i] = 'X';
			}
		}
		//return map;
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