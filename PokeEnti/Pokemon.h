#pragma once
#include <iostream>

enum class Nature {
	TRANQUILA, //Horizontal
	PICARA, //Diagonal
	FUERTE, //Vertical
	INVALID
};

class Pokemon
{
private:
	Nature nature = Nature::INVALID;
	int posX;
	int posY;

public:
	//Contructor

	void PokemonNature(Nature nature);

	void MovePoke(Nature nature);

};