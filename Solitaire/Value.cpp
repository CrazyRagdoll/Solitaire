#include "Value.h"
#include <iostream>



Value::Value()
{
}


Value::~Value()
{
}

void Value::setValue(int a) //Set the value of the card, takes an int and set an enum
{
	switch (a)
	{
	case 1:
		_name = "Ace";
		_value = 1;
		break;
	case 2:
		_name = "Two";
		_value = 2;
		break;
	case 3:
		_name = "Three";
		_value = 3;
		break;
	case 4:
		_name = "Four";
		_value = 4;
		break;
	case 5:
		_name = "Five";
		_value = 5;
		break;
	case 6:
		_name = "Six";
		_value = 6;
		break;
	case 7:
		_name = "Seven";
		_value = 7;
		break;
	case 8:
		_name = "Eight";
		_value = 8;
		break;
	case 9:
		_name = "Nine";
		_value = 9;
		break;
	case 10:
		_name = "Ten";
		_value = 10;
		break;
	case 11:
		_name = "Jack";
		_value = 11;
		break;
	case 12:
		_name = "Queen";
		_value = 12;
		break;
	case 13:
		_name = "King";
		_value = 13;
		break;
	default:
		std::cout << "Counldn't find valid value! SHUT IT DOWN!!" << std::endl;
		break;
	}
}

