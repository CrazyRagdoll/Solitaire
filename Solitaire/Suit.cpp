#include "Suit.h"
#include <iostream>



Suit::Suit()
{
}


Suit::~Suit()
{
}

void Suit::setSuit(int a) //Set the suit of the card, takes an int and set an enum
{
	switch (a)
	{
	case 1:
		_name = "Ace";
		_value = 4;
		break;
	case 2:
		_name = "Diamond";
		_value = 3;
		break;
	case 3:
		_name = "Heart";
		_value = 2;
		break;
	case 4:
		_name = "Spade";
		_value = 1;
		break;
	default:
		std::cout << "Counldn't find valid suit! SHUT IT DOWN!!" << std::endl;
		break;
	}
}