#include "Move.h"
#include <iostream>

int CharacterMovement(int input, int characterX, int characterY)
{
	switch (input)
	{
	case 6: // up
		return characterY + 1;

		break;
	case 7: //down
		return characterY - 1;
		break;
	case 8: // right
		return characterX + 1;
		break;
	case 9: //left
		return characterX - 1;
		break;
	}
}
