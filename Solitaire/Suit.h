#pragma once

#include <string>

using namespace std;

enum class Suits {SPADES, HEARTS, DIAMONDS, CLUBS};

class Suit
{
public:
	Suit();
	~Suit();

	void setSuit(int a);			//Set the suit of the card, takes an int and set an enum

	string getName() { return _name; };
	int getValue() { return _value; };

	string _name;
	int _value;

};

