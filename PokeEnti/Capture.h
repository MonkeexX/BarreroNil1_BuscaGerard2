#pragma once
#include "Pokemon.h"

int Combat(int inputPlay, int pokeballs, int life, int x, int y, int** map, int& capturedPoke, int pikachu);
bool EnterCombat(int inputPlay, int posX, int posY, int capturedPoke, int** map, int pokeballs, int life, int pikachu);
void PrintPokemonNum(int captured);