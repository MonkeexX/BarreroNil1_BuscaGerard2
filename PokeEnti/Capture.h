#pragma once
#include "Pokemon.h"

int Combat(int pokeballs, int life, int x, int y, int** map, int capturedPoke, int pikachu)
{
	//Capturar Pokémon:
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

	//Atacar:
	if (life > 0)
	{
		//hacer daño
		life = -pikachu;
		if (life < 1)
		{
			map[x][y] = ' ';
		}
	}

	//Huir:
	//quitae menu pelea
}

int CapturingPokemon(int posX, int posY, int capturedPoke, int** map, int pokeballs, int life, int pikachu)
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
		Combat(pokeballs, life, x, y, map, capturedPoke, pikachu);
	}
	return capturedPoke;
}

void PrintPokemonNum(int captured)
{
	std::cout << "Number of Pokemon captured: " << captured << std::endl;
}