#pragma once
#include<iostream>
#include <conio.h>



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32
int CharacterMovement(int input, int characterX, int characterY, int** mapa)
{

	switch (input)
	{
	case KEY_UP: // up
			return --characterY;
		break;
	case KEY_DOWN: //down
			return ++characterY;

		break;
	case KEY_RIGHT: // right
		return ++characterX;

			return characterX;
		break;
	case KEY_LEFT: //left
			return --characterX;
		break;
	}
}

std::string DetectZone(int mapX, int mapY, int characterX, int characterY)
{
	if (characterY <= (mapY / 2) && characterX <= (mapX/2))
	{
		return "Pueblo Paleta";
	}
	else if (characterY < (mapY / 2) && characterX > (mapX / 2))
	{
		return "Bosque";
	}
	else if (characterY > (mapY / 2) && characterX > (mapX / 2))
	{
		return "Cueva Celeste";
	}
	else if (characterY > (mapY / 2) && characterX <= (mapX / 2))
	{
		return "Liga PokeEnti";
	}
}
