#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <fstream>
#include "HeaderPokeenti.h"

void main()
{
	srand(time(NULL));
	char** mapa;
	mapa = new char* [MAP_SIZE]; 
	for (int i = 0; i < MAP_SIZE; i++)
	{
		mapa[i] = new char[MAP_SIZE];
	}

	int X = 7, Y = 7; // Min position of player is 5, 5
	int limitScreen = 11;
	int* Xpointer = &X;
	int* Ypointer = &Y;
	int number = 10;
	int input = 0;
	int counterI = 0;
	int counterJ = 0;
	int caracterPosition;
	int caracterX = 5;
	int caracterY = 5;
	char caracter = '>';
	int town = 5;
	int forest = 20;
	int cave = 30;
	int league = 40;
	//To know the number of pokemon captured
	int captured = 0;

	bool gameLoop = true;

	//Read from files
	std::ifstream config;
	config.open("config.txt", std::ios::in | std::ios::app);
	if (config.is_open())
	{

		config >> town;
		config >> forest;
		config >> cave;

		std::cout << town << " " << forest << " " << cave << "\n";
	}

	if (captured >= town)
	{
		for (int i = 0; i < 10; i++)
		{
			mapa[i][MAP_SIZE / 2] = ' ';
		}
	}
	if (captured >= forest)
	{
		for (int i = MAP_SIZE / 2 + 1; i < MAP_SIZE + MAP_SIZE / 4; i++)
		{
			mapa[i][MAP_SIZE / 2] = ' ';
		}
	}
	if (captured >= cave)
	{
		for (int i = MAP_SIZE / 2; i < MAP_SIZE + MAP_SIZE / 4; i++)
		{
			mapa[MAP_SIZE / 2][i] = ' ';
		}
	}

	




	//Read from files
	//ifstream config;
	//config.open("config.txt", ios::in | ios::app);
	//if (config.is_open())
	//{

		//config >> town;
		//config >> forest;
		//config >> cave;

		//std::cout << town << " " << forest << " " << cave <<"\n";
	//}

	//function to prevent player to go outside the map
	if (X < 5)
	{
		X = 6;
	}
	if (X > MAP_SIZE)
	{
		X = MAP_SIZE;
	}
	if (Y < 5)
	{
		Y = 6;
	}
	else if (Y > MAP_SIZE)
	{
		Y = MAP_SIZE;
	}

	SettingMapBarrieres(mapa);

	//TODO: We have to make this work!
	if (captured >= town)
	{
		for (int i = 0; i < MAP_SIZE / 4; i++)
		{
			mapa[MAP_SIZE / 2][i] = ' ';
		}
	}
	if (captured >= forest)
	{
		for (int i = MAP_SIZE / 2; i < MAP_SIZE + MAP_SIZE / 4; i++)
		{
			mapa[i][MAP_SIZE / 2] = ' ';
		}
	}
	if (captured >= cave)
	{
		for (int i = MAP_SIZE / 2; i < MAP_SIZE + MAP_SIZE / 4; i++)
		{
			mapa[MAP_SIZE / 2][i] = ' ';
		}
	}
	if (captured >= league)
	{

	}

	// print the pokemons
	PrintPoke(mapa, captured);

	while (gameLoop = true)
	{

		caracterPosition = mapa[caracterX][caracterY];

		PrintMap(mapa, caracterPosition, caracter);

		//AddPokemonToMap(number, pMapa);

		//OJO LAS FUNCIONES NO ESTAN BIEN PUESTAS

		switch (CharacterMovement(input))
		{
		case 1:
			caracterY--;
			caracter = '^';
			break;

		case 2:
			caracterY++;
			caracter = 'v';
			break;

		case 3:
			caracterX++;
			caracter = '>';
			break;

		case 4:
			caracterX--;
			caracter = '<';
			break;

		case 5:
			CapturingPokemon(caracterX,caracterY,captured,mapa);
			break;

		case 6:
			gameLoop = false;
			break;
		}

		for (int i = 0; i <= MAP_SIZE + 5; i++)
		{
			//delete() mapa;
		}
		system("cls");
		Sleep(100);
		if (captured >= league)
		{
			gameLoop = false;
		}
	}
}