#pragma once
#include<iostream>
#include <conio.h>



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPACE 32



int CharacterMovement(int input)
{
	switch (input)
	{
	case 7:
		return 5;
	case KEY_DOWN:
		return 8;
	case KEY_RIGHT:
		return 9;
	case KEY_LEFT:
		return 5;
	default:
		return -1; // Retorno por defecto en caso de entrada no reconocida
	}
}