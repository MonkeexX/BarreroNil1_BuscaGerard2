#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include "HeaderPokeenti.h"
using namespace std;
#define MAPSIZE 20
#define MAXPOKEMON 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32


int demomentoaqui()
{
	char** map;
	map = new char* [MAPSIZE];
	int X, Y;
	int playerX = 0, playerY = 0;
	int* Xpointer = &X;
	int* Ypointer = &Y;
	int number = 10;
	int input = 0;
	int counterI = 0;
	int counterJ = 0;
	bool isGAmeRunning = true;
	while (isGAmeRunning)
	{
		//TODO hace falta hacer que el movimiento en si


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
					map[j][i] = 'X';
					counterI = 0;

				}
				else if (j == MAPSIZE / 2)
				{
					map[j][i] = 'X';
					counterJ = 0;
				}
				else
				{
					map[j][i] = ' ';
				}
				std::cout << map[j][i];
			}
			std::cout << "\n";
			//return map;

		}

		//PrintMap(map);
		//AddPokemonToMap(number, pMapa);
		system("cls");


	}
}

void main()
{
	int sizeX = 0;
	int sizeY = 0;
	int numPokePaleta = 0;
	int numMustPokePaleta = 0;
	int numPokeForest = 0;
	int numMustPokeForest = 0;
	ifstream config;
	config.open("config.txt", ios::in);
	if (config.is_open())
	{
		config >> sizeX;
		config >> sizeY;
		config >> numPokePaleta;
		config >> numMustPokePaleta;
		config >> numPokeForest;
		config >> numMustPokeForest;
		config.close();
	}


	std::cout << sizeX << " " << sizeY;
	char** map;
	map = new char* [MAPSIZE];
	int X, Y;
	int playerX = 0, playerY = 0;
	int* Xpointer = &X;
	int* Ypointer = &Y;
	int number = 10;
	int input = 0;
	int counterI = 0;
	int counterJ = 0;
	bool isGAmeRunning = true;
	//TODO: print the pokemons


	
	
}