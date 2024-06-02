#pragma once
#include<iostream>
#include <conio.h>
#include <fstream>
#define MAXPOKE 200
#include "HeaderPokeenti.h"
#include <fstream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32

void MapInitiation(int** map, int  mapY, int mapX)
{
	map[10][10] = 6;
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
	map[10][10] = 6;
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

void PrintMap(int** map, int  mapY, int mapX, int posX, int posY)
{

	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (i == mapX / 2 || j == mapY / 2)
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
	switch (input)
	{
	case KEY_UP:
		return 5;
	case KEY_DOWN:
		return 6;
	case KEY_RIGHT:
		return 7;
	case KEY_LEFT:
		return 8;
	case KEY_SPACE:
		return 9;
	default:
		return -1; // Retorno por defecto en caso de entrada no reconocida
	}
}

void PrintCaracter(int caracter, char c)
{
	std::cout << c, caracter;
}