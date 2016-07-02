#include "Deck.h"
#include <iostream>



Deck::Deck()
{
}


Deck::~Deck()
{
}

void Deck::generateDeck() //Generate the deck from suits and cards
{
	cout << "Generating Deck..." << endl;
	for (int i = 1; i <= 4; i++)		//loop through the suits
	{
		for (int j = 1; j <= 13; j++)	//loop through the values
		{
			_card.generateCard(i, j);
			_deck.emplace_back(_card);
		}
	}
}

void Deck::randomiseDeck() //Randomise the deck
{
	cout << "Randomising Deck..." << endl;

	//52 cards in the deck x 4 so I thought 208 would be a good amount of shuffling.
	for (int i = 0; i < 208; i++)
	{
		//Swap the position of two random cards
		int randy = rand() % 52;
		int randyJr = rand() % 52;
		if (randyJr == randy && randyJr <= 0) { randyJr++; }	//Just incase they random
		if (randyJr == randy && randyJr >= 51) { randyJr--; }	//the same number
		std::swap(_deck[randy], _deck[randyJr]);
	}

}

//Debugging tool to display each card in the deck
void Deck::displayDeck(int id)
{
	cout << "Displaying Deck" << id << "..." << endl;
	for (int i = 0; i < _deck.size(); i++)
	{
		std::cout << "Card " << i+1 << ": The " << _deck[i].getCardValueName() << " of " << _deck[i].getCardSuitName() << "s." << std::endl;
	}
}

void Deck::addFromDeck(Deck deck, int a)	//Add a card from another deck
{
	//For however many cards need to be moved (from the end of the deck)
	for (int i = 0; i < a; i++)
	{
		_card = deck._deck.back();	//Add them to the current deck
		_deck.emplace_back(_card);
		deck._deck.pop_back();		//This does not remove from the secondary deck
	}
}