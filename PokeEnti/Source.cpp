#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <fstream>
#include "HeaderPokeenti.h"

#define MAXPOKEMON 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32
using namespace std;
#define limitScreen = 11;
#define number = 10;

int main()
{
	int mapX = 0;
	int mapY = 0;
	//srand(time(NULL));



	int X = 10, Y = 10; // Min position of player is 5, 5

	int input = 0;
	int counterI = 0;
	int counterJ = 0;
	int caracterPosition = 0;
	int caracterX = 20;
	int caracterY = 20;
	int caracterXMin = caracterX - 20;
	int caracterYMin = caracterY - 20;
	char caracter = '>';
	int league = 6;
	int town = 4;
	int forest = 7;
	int cave = 8;
	int leave = 0;
	bool gameLoop = true;
	//To know the number of pokemon captured
	int captured = 0;
	char inputChar;

	int pikachu;
	int pokeHealth;
	int mewtwoHealth;
	int minTime;
	int maxTime;
	//Read from files
	ifstream config;
	config.open("config.txt", ios::in | ios::app);
	if (config.is_open())
	{
		config >> mapX;
		config >> mapY;
		config >> town;
		config >> forest;
		config >> cave;
		config >> pikachu;
		config >> pokeHealth;
		config >> mewtwoHealth;
		config >> minTime;
		config >> maxTime;
	}
	int** mapa = new int* [mapX + 40];
	for (int i = 0; i < mapX; ++i)
	{
		mapa[i] = new int[mapY];
	}
	
	MapInitiation(mapa, mapY, mapX);
	AddPokemonToMap(mapa, mapY, mapX);
	PrintMap(mapa, mapY, mapX, caracterX, caracterY, caracterXMin, caracterYMin);
	while (gameLoop)
	{
		UnlockZones(captured, town, forest, cave, mapa, mapX, mapY);
		PrintPokemonNum(captured);
		std::cin >> inputChar;
		CharacterMovement(inputChar);
		PrintMap(mapa, mapY, mapX, caracterX, caracterY, caracterXMin, caracterYMin);
		std::cout << "You want to leave? 1 -> Yes      0 -> No" << std::endl;
		std::cin >> input;

		if (input == 1)
		{
			gameLoop = false;
		}
	}
}