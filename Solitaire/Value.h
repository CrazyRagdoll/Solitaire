#pragma once

#include <string>

using namespace std;

enum class Values {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Value 
{
public:
	Value();
	~Value();

	void setValue(int a);			//Set the value of the card, takes an int and set an enum

	int getValue() { return _value; };
	string getName() { return _name; };

	string _name;
	int _value;

};

