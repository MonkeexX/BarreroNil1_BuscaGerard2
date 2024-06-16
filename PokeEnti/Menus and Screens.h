#pragma once
#include <windows.h>
void InitScreen()
{
	std::cout << "POKEENTI\n MADE BY NIL BARRERO && GERARD BUSCA" << std::endl;
	Sleep(3000);
}

void MainMenu(int inputPlayerMenu, bool play)
{
	bool isInMenu = true;
	std::cout << "PRESS 1 TO PLAY\n PRESS 0 TO EXIT" << std::endl;
	while (isInMenu == true)
	{
		std::cin >> inputPlayerMenu;
		if (inputPlayerMenu == 1)
		{
			play = true;
			isInMenu = false;
		}
		else if (inputPlayerMenu == 0)
		{
			play = false;
			isInMenu = false;
		}
	}
}

void GameOver()
{
	std::cout << "Game Over";
}

void UI(int capturedPokemons, int pokeballs, int mapX, int mapY)
{
	std::cout << "Pokemons Capturados: " << capturedPokemons << "      Pokeballs: " << pokeballs << std::endl;
	std::string currentZone = DetectZone(mapX, mapY);
	std::cout << currentZone << std::endl;
}
