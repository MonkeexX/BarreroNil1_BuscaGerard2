#include <iostream>
#include <conio.h>
#include "HeaderPokeenti.h"
#define MAPSIZE 20
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
	int counterI = 0;
	int counterJ = 0;
	




	//TODO: print the pokemons
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKEMON; pokemonGenerated++)
	{
		int posX = 1;
		int posY = 1;
		if (mapa[posX][posY] == ' ')
		{
			mapa[posX][posY] = 'P';
		}
	}
	PrintMap(mapa);
	//AddPokemonToMap(number, pMapa);
	

	

	
}