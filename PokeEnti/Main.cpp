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
<<<<<<< HEAD
	int pokeballs = 200;
=======
	int pokeballs = 1;
	int oldX = 0;
	int oldY = 0; 
>>>>>>> origin/PlayerMovement
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
		config.close();
	}
	int** mapa = new int* [mapX + 40];
	for (int i = 0; i < mapX; ++i)
	{
		mapa[i] = new int[mapY];
	}
	InitScreen();
	playerWillPlay = MainMenu(inputPlayer, playerWillPlay);
	if (playerWillPlay)
	{
		MapInitiation(mapa, mapY, mapX, characterX, characterY);
		AddPokemonToMap(mapa, mapY, mapX, captured, town, forest);
		AddPokeballsToMap(mapa, mapY, mapX);

		while (gameLoop)
		{
			UI(captured, pokeballs, characterX, characterY, mapX, mapY);
			UnlockZones(captured, town, forest, cave, mapa, mapX, mapY);
			PrintPokemonNum(captured);
			PrintMap(mapa, mapY, mapX, characterX, characterY, minX, minY, oldX, oldY);

			input = _getch();
			if (input == 32)
			{
				if (GetPokeball(characterX, characterY, mapa))
				{
<<<<<<< HEAD
					bool combat = true;
					while (combat == true)
					{
						int comand = Combat(inputPlayer, pokeballs, pokeHealth, characterX, characterY, mapa, captured, pikachu);
						switch (comand)
						{
						case 1:
							++captured;
							--pokeballs;
							mapa[X++][Y] = 0;
							mapa[X--][Y] = 0;
							mapa[X][Y++] = 0;
							mapa[X][Y--] = 0;
							std::cout << "You captured pokemon"<< endl;
							combat = false;
						    break;
						
						case 2:
							std::cout << "You don't captured pokemon"<<endl;
							--pokeballs;
						    break;

						case 3:
							std::cout << "You don't have pokeballs"<<endl;
							break;

						case 4:
							pokeHealth = -pikachu;
							std::cout << "pokemon life = " << pokeHealth << endl;
							if (pokeHealth < 1)
							{
								mapa[X++][Y] = 0;
								mapa[X--][Y] = 0;
								mapa[X][Y++] = 0;
								mapa[X][Y--] = 0;
								combat = false;
							}
							break;

						case 5:
							std::cout << "You run";
							combat = false;
							break;
						}

					}
=======
					TakePokeball(mapa, characterX, characterY, pokeballs);
>>>>>>> origin/PlayerMovement
				}
				else if (EnterCombat(inputPlayer, characterX, characterY, pokeCach, mapa, pokeCach, pokeHealth, pikachu))
				{
					bool combat = true;
					while (combat == true)
					{
						int comand = Combat(inputPlayer, pokeballs, pokeHealth, characterX, characterY, mapa, captured, pikachu);
						switch (comand)
						{
						case 1:
							++captured;
							--pokeballs;
							std::cout << "You captured pokemon" << endl;
							combat = false;
							break;

						case 2:
							std::cout << "You don't captured pokemon" << endl;
							--pokeballs;
							break;

						case 3:
							std::cout << "You don't have any pokeballs" << endl;
							break;

						case 4:
							pokeHealth = -pikachu;
							std::cout << "pokemon life = " << pokeHealth << endl;
							if (pokeHealth < 1)
							{
								mapa[X++][Y] = 0;
								mapa[X--][Y] = 0;
								mapa[X][Y++] = 0;
								mapa[X][Y--] = 0;
								combat = false;
							}
							break;

						case 5:
							std::cout << "You run";
							combat = false;
							break;
						}

					}
				}
				
			}
			else if (input == KEY_UP || input == KEY_DOWN || input == KEY_RIGHT || input == KEY_LEFT)
			{
				oldX = characterX;
				oldY = characterY;
				switch (input)
				{
				case KEY_UP:
					characterY = CharacterMovement(input, characterX, characterY);
					break;
				case KEY_DOWN:
					characterY = CharacterMovement(input, characterX, characterY);
					break;
				case KEY_RIGHT:
					characterX = CharacterMovement(input, characterX, characterY);
					break;
				case KEY_LEFT:
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