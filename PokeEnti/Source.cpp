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
	char mapa[MAPSIZE+5][MAPSIZE+5];
	char* pMapa = &mapa[MAPSIZE][MAPSIZE];
	int X = 8, Y =13; // POsition of player, the map position is 6
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
		int posX = 5+rand() % MAPSIZE;
		int posY = 5+rand() % MAPSIZE;
		if (mapa[posX][posY] != 'X' && mapa[posX][posY] != 'P')
		{
			mapa[posX][posY] = 'P';
			std::cout << "Poke in:" << posX << posY << "\n";
		}
		
		
	}

	for (int i = Y-5; i < Y+5; i++)
	{
		counterI++;
		counterJ = 0;
		for (int j = X-5; j < X+5; j++)
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
			else if (mapa[i][j] != 'X' && mapa[i][j] != 'P' && mapa[i][j] != 'O')
			{
				mapa[j][i] = ' ';
			}
			else if (mapa[j][i] == 'O')
			{ }
			std::cout << mapa[j][i];
		}
		std::cout << "\n";
	}
	//AddPokemonToMap(number, pMapa);
	

	

	
}