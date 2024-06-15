#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <fstream>
#include <windows.h>
#include "Capture.h"
#include "Map.h"
#include "Move.h"
#include "Pokemon.h"
#include "Menus and Screens.h"
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
	int move;
	int counterI = 0;
	int counterJ = 0;
	int characterPosition = 0;
	int characterX = 1;
	int characterY = 1;
	char caracter = '>';
	int league = 6;
	int town = 4;
	int forest = 7;
	int cave = 8;
	bool gameLoop = true;
	bool inputPlayer = true;
	bool playerWillPlay = true;
	//To know the number of pokemon captured
	int captured = 0;
	int pokeCach = 0;
	int pikachu;
	int pokeHealth;
	int mewtwoHealth;
	int minTime;
	int maxTime;
	int minX = 0;
	int minY = 0;
	int pokeballs = 1;
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
	InitScreen();
	MainMenu(inputPlayer, playerWillPlay);
	if (playerWillPlay)
	{
		MapInitiation(mapa, mapY, mapX, characterX, characterY);
		AddPokemonToMap(mapa, mapY, mapX);
		AddPokeballsToMap(mapa, mapY, mapX);

		while (gameLoop)
		{
			UnlockZones(captured, town, forest, cave, mapa, mapX, mapY);
			PrintPokemonNum(captured);
			PrintMap(mapa, mapY, mapX, characterX, characterY, minX, minY);

			std::cin >> input;
			if (input == 10)
			{

				if (EnterCombat(inputPlayer, characterX, characterY, pokeCach, mapa, pokeCach, pokeHealth, pikachu))
				{
					Combat(inputPlayer, pokeballs, pokeHealth, characterX, characterY, mapa, captured, pikachu);
					if (captured == ++captured)
					{
						--pokeballs;
					}
					std::cout << captured;
				}
			}
			else if (input == 7 || input == 6 || input == 8 || input == 9)
			{
				switch (input)
				{
				case 6:
					characterY = CharacterMovement(input, characterX, characterY);
					break;
				case 7:
					std::cout << characterY;
					characterY = CharacterMovement(input, characterX, characterY);
					std::cout << characterY;

					break;
				case 8:
					characterX = CharacterMovement(input, characterX, characterY);
					break;
				case 9:
					characterX = CharacterMovement(input, characterX, characterY);
					break;
				}
			}
			Sleep(1000);
			system("cls");
		}
	}
	if (!playerWillPlay)
	{

		for (int i = 0; i < mapX; ++i)
		{
			delete mapa[i];
		}
		delete mapa;
		mapa = nullptr;

	}
}