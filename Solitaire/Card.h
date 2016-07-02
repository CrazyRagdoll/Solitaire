#pragma once
#include "Value.h"
#include "Suit.h"

#include <vector>

class Card
{
public:
	Card();
	~Card();

	void generateCard(int a, int b);	//Create a Card based on two inputs, suit + value

	string getCardSuitName()   { return _suit.getName(); }
	string getCardValueName()  { return _value.getName(); }
	int	   getCardSuitValue()  { return _suit.getValue(); }
	int    getCardValueValue() { return _value.getValue(); }

	Suit _suit;
	Value _value;

};

