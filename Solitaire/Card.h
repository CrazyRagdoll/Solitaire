#pragma once
#include "Value.h"
#include "Suit.h"

#include <vector>

enum class CardState { FACE_UP, FACE_DOWN };

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

	void setCardState(string state);	//Set the state of the card (face up or down)
	CardState getCardState() { return _cardState; };

	Suit _suit;
	Value _value;

	CardState _cardState;
};

