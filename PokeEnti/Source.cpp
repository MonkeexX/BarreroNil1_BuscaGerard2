#include <iostream>
#include <conio.h>
#include "HeaderPokeenti.h"
#define MAPSIZE 100
#define MAXPOKEMON 200
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32


void main()
{
	char mapa[MAPSIZE][MAPSIZE];
	char* pMapa = &mapa[MAPSIZE][MAPSIZE];
	int X, Y;
	int* Xpointer = &X;
	int* Ypointer = &Y;
	int number = 10;
	int input = 0;
	
	
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			mapa[i][j] = ' ';
		}
		//return map;
	}

	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			mapa[i][MAPSIZE / 2] = 'X';
			mapa[MAPSIZE / 2][i] = 'X';
		}
		//return map;
	}
	

	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; i++)
		{
			std::cout << mapa[i][j] << "0";
			if (j == MAPSIZE)
			{
				std::cout << "\n";
			}
		}
	}

	
}