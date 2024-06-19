#pragma once
#include<iostream>
#define MAXPOKE 100
void MapInitiation(int** map, int  mapY, int mapX, int characterX, int characterY)
{

	//Firts we create a map in blank
	for (int i = 0; i < mapX; ++i)
	{
		for (int j = 0; j < mapY; ++j)
		{
			map[i][j] = 0;
		}

		for (int j = 0; j < mapY; ++j)
		{
			map[mapX / 2][j] = 1;
		}

		for (int j = 0; j < mapX; ++j)
		{
			map[j][mapY / 2] = 1;
		}
	}
	map[characterX][characterY] = 6;

	map[mapX - 5][mapY - 5] = 9; //Mewtwo appears
}

void UnlockZones(int captured, int paleta, int forest, int cave, int** map, int mapX, int mapY)
{

	if (captured >= paleta)
	{
		for (int j = 0; j < (mapY / 2)-10; j++)
		{
			map[j][mapY / 2] = 0;
		}
	}

	if (captured >= forest)
	{
		for (int j = (mapX / 2); j < mapX + 21; j++)
		{
			map[mapX / 2][j] = 0;
		}
	}

	if (captured >= paleta)
	{
		for (int i = 0; i < mapX; i++)
		{
			for (int j = (mapY / 2); j < mapY; j++)
			{
				map[i][mapY / 2] = 0;
			}
		}
	}

}

void AddPokemonToMap(int** map, int  mapY, int mapX, int captured, int paleta, int forest)
{
	int posX = 0;
	int posY = 0;



	//Pokemon = 2
	for (int pokemonGenerated = 0; pokemonGenerated < MAXPOKE; pokemonGenerated++)
	{
		bool hasGeneratedWell = false;


		while (!hasGeneratedWell)
		{
			if (captured <= paleta)
			{
				posX = rand() % (1 - (mapX / 2));
				posY = rand() % (1 - (mapY / 2) - 10);

				if (captured <= forest)
				{
					posX = rand() % mapX;
					posY = rand() % (1 - (mapY / 2));
				}
			}
			if (map[posX][posY] != 1 && map[posX][posY] != 3)
			{
				hasGeneratedWell = true;
				map[posX][posY] = 2;
			}
		}
	}
}

int Random(int a, int top)
{
	a = rand() % top;
	return a;
}
void AddPokeballsToMap(int** map, int characterX, int characterY)
{
	bool hasGeneratedWell = false;

	int posX = rand() % characterX;
	int posY = rand() % characterY;
	while (!hasGeneratedWell)
	{
		if (map[posX][posY] != 1 && map[posX][posY] != 2)
		{
			hasGeneratedWell = true;
			map[posX][posY] = 3;
		}
	}

}

void PrintMap(int** map, int  mapY, int mapX, int posY, int posX, int posXMin, int posYMin, int posXMax, int posYMax, int oldX, int oldY)
{

	map[posX][posY] = 6;
	if (posXMin < 0)
	{
		posXMin = 0;
	}
	if (posYMin < 0)
	{
		posYMin = 0;
	}
	if (posXMin < 0)
	{
		posXMin = 0;
	}
	if (posYMin < 0)
	{
		posYMin = 0;
	}
	if (posX >= mapX)
	{
		posXMax = mapX;
	}
	if (posY >= mapY)
	{
		posYMax = mapY;
	}
	if(posX != oldX and posY != oldY)
	map[oldX][oldY] = 0;

	for (int i = posXMin; i < posXMax -30 ; ++i)
	{
		for (int j = posYMin; j < posYMax -30; ++j)
		{
			if (posX + 20 >= mapX)
			{
				posX = mapX;
			}
			if (posY + 20 >= mapY)
			{
				posY = mapY;
			}
			if (map[i][j] == 1)
			{
				std::cout << "X";
			}
			else if (map[i][j] == 2)
			{
				std::cout << "P";
			}
			else if (map[i][j] == 3)
			{
				std::cout << "O";
			}
			//Now for the character movement
			else if (map[i][j] == 5)
			{
				std::cout << "^";
			}
			else if (map[i][j] == 6)
			{
				std::cout << "v";
			}
			else if (map[i][j] == 7)
			{
				std::cout << ">";
			}
			else if (map[i][j] == 8)
			{
				std::cout << "<";
			}
			else if (map[i][j] == 9)
			{
				std::cout << "M";
			}
			else if (map[i][j] == 0)
			{
				std::cout << "-";
			}
		}

		std::cout << "\n";
	}
}