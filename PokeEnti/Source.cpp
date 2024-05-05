#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <fstream>
#include "HeaderPokeenti.h"
#define MAPSIZE 20
#define MAXPOKEMON 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32
using namespace std;

void main()
{
	srand(time(NULL));
	char mapa[MAPSIZE + 5][MAPSIZE + 5];
	char* pMapa = &mapa[MAPSIZE][MAPSIZE];
	int X = 10, Y = 10; // Min position of player is 5, 5
	int limitScreen = 11;
	int* Xpointer = &X;
	int* Ypointer = &Y;
	int number = 10;
	int input = 0;
	int counterI = 0;
	int counterJ = 0;
	int town = 10;
	int forest = 0;
	int cave = 0;
	int league = 0;
	//To know the number of pokemon captured
	int captured = 10;

	//TODO: We have to make this work!
	if (captured >= town)
	{
		for (int i = 0; i < MAPSIZE / 4; i++)
		{
			mapa[MAPSIZE / 2][i] = ' ';
		}
	}
	if (captured >= forest)
	{
		for (int i = MAPSIZE/2; i <MAPSIZE + MAPSIZE / 4; i++)
		{
			mapa[i][MAPSIZE/2] = ' ';
		}
	}
	if (captured >= cave)
	{
		for (int i = MAPSIZE/2; i < MAPSIZE + MAPSIZE / 4; i++)
		{
			mapa[MAPSIZE / 2][i] = ' ';
		}
	}
	if (captured >= league)
	{

	}

	//Read from files
	ifstream config;
	config.open("config.txt", ios::in | ios::app);
	if (config.is_open())
	{
		
		config >> town;
		config >> forest;
		config >> cave;

		std::cout << town << " " << forest << " " << cave <<"\n";
	}

	



	//function to prevent player to go outside the map
	if (X < 5)
	{
		X = 6;
	}
	if (X > MAPSIZE)
	{
		X = MAPSIZE;
	}
	if (Y < 5)
	{
		Y = 6;
	}
	else if (Y > MAPSIZE)
	{
		Y = MAPSIZE;
	}


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
		int posX = 5 + rand() % MAPSIZE;
		int posY = 5 + rand() % MAPSIZE;
		if (mapa[posX][posY] != 'X' && mapa[posX][posY] != 'P')
		{
			mapa[posX][posY] = 'P';
			std::cout << "Poke in:" << posX << posY << "\n";
		}
		std::cout << "Number of Pokémon captured: " << captured;


	}

	for (int i = Y - 5; i < Y + 5; i++)
	{
		counterI++;
		counterJ = 0;
		for (int j = X - 5; j < X + 5; j++)
		{
			counterJ++;
			if (mapa[i][j] == 'X')
			{
				mapa[j][i] = 'X';
				counterI = 0;

			}
			else if (mapa[i][j] == 'P')
			{
				mapa[j][i] = 'P';
			}
			else if (mapa[i][j] == 'X')
			{
				mapa[j][i] = 'X';
				counterJ = 0;
			}
			else if (mapa[i][j] != 'X' && mapa[i][j] != 'P' && mapa[i][j] != 'O')
			{
				mapa[j][i] = ' ';
			}
			else if (mapa[j][i] == 'O')
			{
			}
			std::cout << mapa[j][i];
		}
		std::cout << "\n";
	}
	//AddPokemonToMap(number, pMapa);





}