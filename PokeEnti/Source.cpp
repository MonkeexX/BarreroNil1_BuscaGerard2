#include <iostream>
#include <conio.h>
#include <ctime>
#include "HeaderPokeenti.h"
#define MAPSIZE 20
#define MAXPOKEMON 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32


void main()
{
	srand(time(NULL));
	char mapa[MAPSIZE][MAPSIZE];
	char* pMapa = &mapa[MAPSIZE][MAPSIZE];
	int X, Y;
	int limitScreen = 10;
	int* Xpointer = &X;
	int* Ypointer = &Y;
	int number = 10;
	int input = 0;
	int counterI = 0;
	int counterJ = 0;
	

	
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (i == MAPSIZE / 2)
			{
				mapa[j][i] = 'X';
			}

			else if (j == MAPSIZE / 2)
			{
				mapa[j][i] = 'X';
			}
		}
		//return map;
	}

	//TODO: print the pokemons
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKEMON; pokemonGenerated++)
	{
		int posX = rand() % 5;
		int posY = rand() % 5;
		if (mapa[posX][posY] != 'X' && mapa[posX][posY] != 'P')
		{
			mapa[posX][posY] = 'P';
			std::cout << "Poke in:" << posX << posY << "\n";
		}
		if (mapa[posX][posY] == 'P')
		{
			pokemonGenerated--;
		}
		
	}

	int counterI = 0;
	int counterJ = 0;
	for (int i = 0; i < MAPSIZE; i++)
	{
		counterI++;
		counterJ = 0;
		for (int j = 0; j < MAPSIZE; j++)
		{
			counterJ++;
			if (i == MAPSIZE / 2)
			{
				mapa[j][i] = 'X';
				counterI = 0;

			}
			else if (mapa[i][j] == 'P')
			{
				mapa[j][i] = 'P';
			}
			else if (j == MAPSIZE / 2)
			{
				mapa[j][i] = 'X';
				counterJ = 0;
			}
			else if (mapa[i][j] != 'X' && mapa[i][j] != 'P')
			{
				mapa[j][i] = ' ';
			}
			std::cout << mapa[j][i];
		}
		std::cout << "\n";
	}
	//AddPokemonToMap(number, pMapa);
	

	

	
}