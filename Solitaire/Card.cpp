#include "Card.h"
#include <iostream>



Card::Card()
{
}


Card::~Card()
{
}


void Card::generateCard(int a, int b) //Create a Card based on two inputs, suit + value
{
	cout << "Generating Card: " << a << " " << b << "..." << endl;
	_suit.setSuit(a); 
	_value.setValue(b);
	cout << "Card " << _value.getName() << " of " << _suit.getName() << "s has been generated..." << endl;
}
