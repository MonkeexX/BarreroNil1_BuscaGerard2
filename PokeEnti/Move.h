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
	case KEY_UP:
		return 5;
	case KEY_DOWN:
		return 6;
	case KEY_RIGHT:
		return 7;
	case KEY_LEFT:
		return 8;
	default:
		return -1; // Retorno por defecto en caso de entrada no reconocida
	}
}