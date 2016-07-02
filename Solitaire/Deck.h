#pragma once
#include "Card.h"

enum class DeckType { UP, DOWN };

class Deck
{
public:
	Deck(int id, string name);
	~Deck();

	void generateDeck();			//Generate the deck from suits and cards
	void randomiseDeck();			//Randomise the deck
	void displayDeck();				//Writes out all of the cards in the deck
	void displayLastXCards(int x);		//Display the last X amount of cards in the deck

	void addFromDeck(Deck deck, int a);	//Add a card from another deck, how many cards

	std::vector<Card> _deck;		//The deck is a vector of cards, holding 52, one of each suit+value	

	DeckType _deckType;				//enum class to seperate the differet types of decks

	int _deckId;					//The Deck ID (for that group of decks)
	string _deckName;				//The name of the deck

	Card _card;						//Card place holder!

};

