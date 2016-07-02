#pragma once
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	void generateDeck();			//Generate the deck from suits and cards
	void randomiseDeck();			//Randomise the deck
	void displayDeck(int id);				//Writes out all of the cards in the deck

	void addFromDeck(Deck deck, int a);	//Add a card from another deck, how many cards

	std::vector<Card> _deck;		//The deck is a vector of cards, holding 52, one of each suit+value	

	Card _card;

};

