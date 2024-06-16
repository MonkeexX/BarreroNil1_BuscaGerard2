#pragma once
#include<iostream>
#include <conio.h>



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32



int CharacterMovement(int input, int characterX, int characterY)
{

	switch (input)
	{
	case KEY_UP: // up
		return characterY - 1;

		break;
	case KEY_DOWN: //down
		return characterY + 1;
		break;
	case KEY_RIGHT: // right
		return characterX + 1;
		break;
	case KEY_LEFT: //left
		return characterX - 1;
		break;
	}
}

std::string DetectZone(int mapX, int mapY)
{
	if (mapY <= (mapY / 2) && mapX <= (mapX/2))
	{
		return "Pueblo Paleta";
	}
	else if (mapY < (mapY / 2) && mapX > (mapX / 2))
	{
		return "Bosque";
	}
	else if (mapY > (mapY / 2) && mapX > (mapX / 2))
	{
		return "Cueva celeste";
	}
	else if (mapY > (mapY / 2) && mapX <= (mapX / 2))
	{
		return "Liga PokEnti";
	}
}
