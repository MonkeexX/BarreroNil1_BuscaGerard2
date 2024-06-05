#pragma once
#include "Pokemon.h"

int Combat(int inputPlay, int pokeballs, int life, int x, int y, int** map, int capturedPoke, int pikachu)
{
	std::cin >> inputPlay;
	std::cout << "Capturar: 5 \n Atacar: 6 \n Huir: 7 \n";
	//Capturar Pokémon:
	if (inputPlay == 5)
	{
		if (pokeballs < 0)
		{
			int capture = rand() % life;
			if (capture <= 20)
			{
				map[x][y] = ' ';
				capturedPoke++;
				return capturedPoke;
			}
		}
		else
		{
			std::cout << "You don't have pokeballs";
		}
	}

	//Atacar:
	if (inputPlay == 6)
	{
		if (life > 0)
		{
			//hacer daño
			life = -pikachu;
			if (life < 1)
			{
				map[x][y] = ' ';
				return -1;
			}
		}
	}

	//Huir:
	if (inputPlay == 7)
	{
		std::cout << "You run";
		return -1;
	}

}

int CapturingPokemon(int inputPlay, int posX, int posY, int capturedPoke, int** map, int pokeballs, int life, int pikachu)
{
	bool isTherePokemon = false;

	//we will check every square next to the player
	int x;
	int y;
	if (map[posX][posY++] == 1)
	{
		x = posX;
		y = posY++;
		isTherePokemon = true;
	}
	else if (map[posX++][posY++] == 1)
	{
		x = posX++;
		y = posY++;
		isTherePokemon = true;
	}
	if (map[posX++][posY] == 1)
	{
		x = posX++;
		y = posY;
		isTherePokemon = true;
	}
	if (map[posX++][posY--] == 1)
	{
		x = posX++;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX][posY--] == 1)
	{
		x = posX;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX--][posY--] == 1)
	{
		x = posX--;
		y = posY--;
		isTherePokemon = true;
	}
	if (map[posX--][posY] == 1)
	{
		x = posX--;
		y = posY;
		isTherePokemon = true;
	}
	if (map[posX--][posY++] == 1)
	{
		x = posX--;
		y = posY++;
		isTherePokemon = true;
	}
	if (isTherePokemon)
	{
		Combat(inputPlay, pokeballs, life, x, y, map, capturedPoke, pikachu);
	}
	return capturedPoke;
}

void PrintPokemonNum(int captured)
{
	std::cout << "Number of Pokemon captured: " << captured << std::endl;
}