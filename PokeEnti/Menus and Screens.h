#pragma once
#include <windows.h>
void InitScreen()
{
	std::cout << "POKEENTI\n MADE BY NIL BARRERO && GERARD BUSCA" << std::endl;
	Sleep(3000);
}

bool MainMenu(int inputPlayerMenu, bool play)
{
	bool isInMenu = true;
	std::cout << "PRESS 1 TO PLAY\n PRESS 0 TO EXIT" << std::endl;
	while (isInMenu == true)
	{
		std::cin >> inputPlayerMenu;
		if (inputPlayerMenu == 1)
		{
			play = true;
			return true;
		}
		else if (inputPlayerMenu == 0)
		{
			play = false;
			return false;
		}
	}
}

void GameOver(bool mewtue)
{
	if (mewtue = true)
	{
		std::cout << "Alongside Mewtwo, Manish managed to easily defeat the champions Richard and Radef. -That Mewtwo is broken- they said while crying. And so, Manish became the champion of Enti. (Good Ending)";
	}
	else
	{
		std::cout << "Without Mewtwo, Manish lost disastrously. (Bad Ending)";
	}
	
}

void UI(int capturedPokemons, int pokeballs, int characterX, int characterY, int mapX, int mapY)
{
	std::cout << "Pokemons Capturados: " << capturedPokemons << "      Pokeballs: " << pokeballs << std::endl;
	std::string currentZone = DetectZone(mapX, mapY,characterX, characterY);
	std::cout << currentZone << std::endl;
}
